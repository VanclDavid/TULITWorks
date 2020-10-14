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

void printLCD(uint16_t Xpos, uint16_t Ypos, char text[], Text_AlignModeTypdef mode)
{
    BSP_LCD_DisplayStringAt(Xpos, Ypos, (uint8_t*)text, mode);
}

void pauseLCD(int delay) {
    HAL_Delay(delay);
}

int main()
{
    initLCD();

    while (1) {
        preparePrintLCD(LCD_COLOR_BLACK, &LCD_DEFAULT_FONT, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
        char text[] = "David Vancl";
        printLCD(0, 120, text, CENTER_MODE);
        pauseLCD(2000);
        preparePrintLCD(LCD_COLOR_BLACK, &LCD_DEFAULT_FONT, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
        char hiddenText[] = "WOW :D";
        printLCD(0, 120, hiddenText, CENTER_MODE);
        pauseLCD(500);
    }
}