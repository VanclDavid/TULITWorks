#include "mbed.h"
#include <cstdint>
#include <cstdlib>
#include <string>

#include "LCDLibrary.h"
#include "UIObjects.h"

LowPowerTicker alarm_event;
Ticker countDown;
Thread printing;
InterruptIn reset_button(BUTTON1);
bool isMinutes = true;
int minutes = 2,seconds = 0;

void printTime(){
    string min_string = "";
    (minutes < 10) ? min_string = "0" + to_string(minutes) : min_string = to_string(minutes);
    string sec_string = "";
    (seconds < 10) ? sec_string = "0" + to_string(seconds) : sec_string = to_string(seconds);
    min_string = min_string + ":" + sec_string;
    printOnLineLCD(5, (uint8_t *) min_string.c_str(), CENTER_MODE);

    string type_str = "ac: " + (string)((isMinutes) ? "minutes" : "seconds");
    printOnLineLCD(6, (uint8_t *) type_str.c_str(), CENTER_MODE);
    pauseLCD(100);
}

void printing_void(){
    while (true) {
        printTime();
    }
}

void triggerAlarm(){
    preparePrintLCD(LCD_COLOR_RED,&LCD_DEFAULT_FONT,LCD_COLOR_RED,LCD_COLOR_RED);
}

void countDown_void(){
    seconds--;
    if(seconds <= 0){
        seconds = 60;
        minutes--;
    }
}

void reset_device(){
    alarm_event.detach();
    countDown.detach();
    minutes = 2;
    seconds = 0;
}

int main()
{
    initLCD();
    
    if (getLCDStatus() != TS_OK) printLCDError();
    preparePrintLCD(LCD_COLOR_BLACK,&LCD_DEFAULT_FONT,LCD_COLOR_BLACK,LCD_COLOR_WHITE);

    printPlusSide();
    printMinusSide();
    printChangeUnitBox();
    printSetButton();
    printTime();
    reset_button.fall(reset_device);

    pauseLCD(1000);
    printing.start(printing_void);

    TS_StateTypeDef TS_State;
    uint32_t YSize = BSP_LCD_GetYSize();
    uint32_t XSize = BSP_LCD_GetXSize();
    while(true) {
        BSP_TS_GetState(&TS_State);

        if (TS_State.touchDetected) {
            uint16_t x = TS_State.touchX[0];
            uint16_t y = TS_State.touchY[0];

            if(x < 120 && x > 0 && y > 0 && y < YSize){ // +
                if(isMinutes){
                    if(minutes < 50) minutes++;
                } else {
                    if(seconds < 60) seconds++;
                }
            } else if(x > (XSize - 120) && x < XSize && y > 0 &&  y < YSize){ // -
                if(isMinutes){
                    if(minutes != 0) minutes--;
                } else {
                    if(seconds != 0) seconds--;
                }
            } else if(x > 180 && x < (180 + 120) && y > 200 && y < (200 + 30)){ //change unit
                isMinutes = !isMinutes;
            } else if(x > 180 && x < (180 + 120) && y > 50 && y < (50 + 30)){ //set button
                volatile uint64_t delay = ((volatile uint8_t) minutes * 60) + (volatile uint8_t) seconds;
                alarm_event.attach(&triggerAlarm, delay);
                countDown.attach(countDown_void,1);
            }
        }
        wait_us(100000); 
    }
}