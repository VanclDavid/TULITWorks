#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

void initLCD()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
}

void preparePrintLCD(uint32_t backgroundColor, sFONT* font, uint32_t backgroundTextColor, uint32_t foregroundColor)
{
    BSP_LCD_Clear(backgroundColor);
    BSP_LCD_SetFont(font);
    BSP_LCD_SetBackColor(backgroundTextColor);
    BSP_LCD_SetTextColor(foregroundColor);
}

void pauseLCD(int delay) {
    HAL_Delay(delay);
}

void thread1_void()
{
    while (true) {
        BSP_LCD_DisplayStringAt(0, LINE(3), (uint8_t*)"THREAD 1", CENTER_MODE);
        pauseLCD(2000);
        BSP_LCD_ClearStringLine(3);
        pauseLCD(2000);
        BSP_LCD_DisplayStringAt(0, LINE(3), (uint8_t*)"Pepicku,", CENTER_MODE);
        BSP_LCD_DisplayStringAt(0, LINE(4), (uint8_t*)"kolik druhu opic znas?", CENTER_MODE);
        BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t*)"...", CENTER_MODE);
        BSP_LCD_DisplayStringAt(0, LINE(6), (uint8_t*)"Ani jeden, pani ucitelko,", CENTER_MODE);
        BSP_LCD_DisplayStringAt(0, LINE(7), (uint8_t*)"ja jsem abstinent!", CENTER_MODE);
        pauseLCD(2000);
        BSP_LCD_ClearStringLine(3);
        BSP_LCD_ClearStringLine(4);
        BSP_LCD_ClearStringLine(5);
        BSP_LCD_ClearStringLine(6);
        BSP_LCD_ClearStringLine(7);
        pauseLCD(2000);
    }
}

DigitalOut led1(LED1);
void thread2_void()
{
    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(500);
    }
}

DigitalIn button(USER_BUTTON);
void thread3_void()
{
    while (true) {
        if (button) {
            BSP_LCD_ClearStringLine(9);
            BSP_LCD_DisplayStringAt(0, LINE(9), (uint8_t*)"BUTTON - ON", CENTER_MODE);
        }
        else {
            BSP_LCD_ClearStringLine(9);
            BSP_LCD_DisplayStringAt(0, LINE(9), (uint8_t*)"BUTTON - OFF", CENTER_MODE);
        }
        pauseLCD(500);
    }
}

Thread thread1;
Thread thread2;
Thread thread3;

int main()
{
    initLCD();
    preparePrintLCD(LCD_COLOR_BLACK, &LCD_DEFAULT_FONT, LCD_COLOR_BLACK, LCD_COLOR_WHITE);

    thread1.start(thread1_void);
    thread2.start(thread2_void);
    thread3.start(thread3_void);

    while (true) {
        BSP_LCD_DisplayStringAt(0, LINE(1), (uint8_t*)"MAIN THREAD", CENTER_MODE);
        pauseLCD(1000);
        BSP_LCD_ClearStringLine(1);
        pauseLCD(1000);
    }
}