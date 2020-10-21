#include "LCDLibrary.h"

void initLCD() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
}

void preparePrintLCD(uint32_t backgroundColor, sFONT* font, uint32_t backgroundTextColor, uint32_t foregroundColor) {
    BSP_LCD_Clear(backgroundColor);
    BSP_LCD_SetFont(font);
    BSP_LCD_SetBackColor(backgroundTextColor);
    BSP_LCD_SetTextColor(foregroundColor);
}

void printOnLineLCD(int lineNumber, uint8_t* text, Text_AlignModeTypdef mode) {
    BSP_LCD_DisplayStringAt(0, LINE(lineNumber), text, mode);
}

void clearLineLCD(int lineNumber) {
    BSP_LCD_ClearStringLine(lineNumber);
}

void pauseLCD(int delay) {
    HAL_Delay(delay);
}