#include "mbed.h"
#include "ResetReason.h"
#include "win_ext_powernut.h"
#include <string>
#include "stm32746g_discovery_lcd.h"
#include <cstdint>





std::string reset_reason_to_string(const reset_reason_t reason)
{
    switch (reason) {
        case RESET_REASON_POWER_ON:
            return "Power On";
        case RESET_REASON_PIN_RESET:
            return "Hardware Pin";
        case RESET_REASON_SOFTWARE:
            return "Software Reset";
        case RESET_REASON_WATCHDOG:
            return "Watchdog";
        default:
            return "Other Reason";
    }
}
DigitalIn button_1(USER_BUTTON);


Thread t1;
Thread t2;
Thread t3;

void proces1()
{
     //init
      BSP_LCD_Init();
      
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
BSP_LCD_Clear(LCD_COLOR_BLACK);
     //init
    const reset_reason_t reason = ResetReason::get();
     BSP_LCD_SetFont(&Font20);
     BSP_LCD_SetBackColor(LCD_COLOR_BLACK); 
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
    BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)((reset_reason_to_string(reason)).c_str()), CENTER_MODE);


}
void proces2()
{
    winExt_startSerial();
    
    while (1) {
        execute_command();
    }
}
void proces3()
{
    while(1)
    {
        bool active = false;
        while(1){
        if(button_1)
        {  
            active = true;
        }
        if(active)
        {
            active = false;
            NVIC_SystemReset();
        }   
    }
    }
}

int main()
{
    
    
    //printf("\nLast system reset reason: %s\r\n", reset_reason_to_string(reason).c_str());


    //3 vlákna
    //vlakno1 = display
    //vlakon2 = serial
    //vlakno3 = tlacitko
    
    t1.start(proces1);
    t2.start(proces2);
    t3.start(proces3);
    while(1)
    {;}
    
}