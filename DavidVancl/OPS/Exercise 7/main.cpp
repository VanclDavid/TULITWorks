#include "mbed.h"
#include "ResetReason.h"
#include "LCDLibrary.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <string>


using namespace std;
using namespace std::chrono;

Timeout time_reset_out;
static BufferedSerial pc(USBTX, USBRX);
Thread reading_serial;

string reset_reason_to_string(const reset_reason_t reason)
{
    switch (reason) {
        case RESET_REASON_POWER_ON:
            return "power";
        case RESET_REASON_PIN_RESET:
            return "button";
        case RESET_REASON_SOFTWARE:
            return "serial";
        case RESET_REASON_WATCHDOG:
            return "watchdog";
        default:
            return "Other Reason";
    }
}

void read_serial_method(){
    char character;
    int compareIndex = 0;
    char command[] = {'r','e','s','e','t'};

    while (true) {
        pc.read(&character, sizeof(string));

        if(character == command[compareIndex]){
            compareIndex++;
            if(compareIndex == 5){
                 NVIC_SystemReset();
                 compareIndex = 0;
            }
        } else {
            compareIndex = 0;
        }
    }
}

int main()
{
    initLCD();
    preparePrintLCD(LCD_COLOR_LIGHTGREEN,&LCD_DEFAULT_FONT,LCD_COLOR_LIGHTGREEN,LCD_COLOR_BLACK);
    const reset_reason_t reason = ResetReason::get();
    printf("Zařízení bylo resetováno: %s \n", reset_reason_to_string(reason).c_str());
    printOnLineLCD(3, (uint8_t *) "Last reset by:", CENTER_MODE);
    printOnLineLCD(4, (uint8_t *) reset_reason_to_string(reason).c_str(), CENTER_MODE);
    reading_serial.start(read_serial_method);

    Timer tim;
    tim.start();
    float last = 10;

    while (true) {
        if(duration<float>(tim.elapsed_time()).count() > last){
            Watchdog &watchdog = Watchdog::get_instance();
            watchdog.start(10);
            last += 10;
        }
    }
}