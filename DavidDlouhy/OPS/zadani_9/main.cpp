#include "mbed.h"
#include <string>
#include "stm32746g_discovery_lcd.h"
#include <cstdint>
#include "win_ext_network_wokrer.h"

DigitalIn button_1(USER_BUTTON);
void IchMochteEinenZapocet(); 


Thread thread_ReadButton;
void proces_ReadButton()
{
    bool active = false;
    while(1){
        if(button_1){  
            active = true; 
        }
        if(active)
        {
            active = false;
            IchMochteEinenZapocet(); 
        }   
    }
}

void clearDisplay()
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
}

void initDisplay()
{
    BSP_LCD_Init(); 
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    clearDisplay();
    BSP_LCD_SetFont(&Font20);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK); 
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
}

void infoSendData()
{
    clearDisplay();
    BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"Odesilam data...", CENTER_MODE);
    //zde bude odeslaní a detekce kódu
}

void zapocetProces()
{
    infoSendData();
    string line1= win_ext_sendZapocet();
    clearDisplay();
    if(line1=="OK")
    {
        BSP_LCD_SetTextColor(LCD_COLOR_GREEN); 
    }
    else {
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
    }
    BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)(line1.c_str()), CENTER_MODE);
    ThisThread::sleep_for(2s);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
    //zobrazení info kódu pro 
    clearDisplay();
}

void IchMochteEinenZapocet()
{
    Thread zapocetThread;
    zapocetThread.start(zapocetProces);
    zapocetThread.join();
}

int main()
{
    initDisplay();
    thread_ReadButton.start(proces_ReadButton);
    
}

/*



*/