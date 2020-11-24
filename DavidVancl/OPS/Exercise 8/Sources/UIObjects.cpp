#include "UIObjects.h"
#include <cstdint>

void printPlusSide(){
    uint32_t tmp = BSP_LCD_GetTextColor();
    BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    BSP_LCD_FillRect(0,0,120,275);
    BSP_LCD_SetTextColor(tmp);
}

void printMinusSide(){
    uint32_t tmp = BSP_LCD_GetTextColor();
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    BSP_LCD_FillRect(BSP_LCD_GetXSize() - 120,0,120,275);
    BSP_LCD_SetTextColor(tmp);
}

void printChangeUnitBox(){
    uint32_t tmp_back = BSP_LCD_GetBackColor();
    uint32_t tmp_front = BSP_LCD_GetTextColor();
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_LIGHTYELLOW);
    BSP_LCD_DisplayStringAt(180, 200, (uint8_t *) "min/sec", LEFT_MODE);
    BSP_LCD_SetTextColor(tmp_front);
    BSP_LCD_SetBackColor(tmp_back);
}

void printSetButton(){
    uint32_t tmp_back = BSP_LCD_GetBackColor();
    uint32_t tmp_front = BSP_LCD_GetTextColor();
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
    BSP_LCD_DisplayStringAt(0, 50, (uint8_t *) "start", CENTER_MODE);
    BSP_LCD_SetTextColor(tmp_front);
    BSP_LCD_SetBackColor(tmp_back);
}