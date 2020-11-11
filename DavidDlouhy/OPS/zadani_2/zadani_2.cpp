#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
//jméno
char myName[] = "David Dlouhy";
//Vykreslení jména
void displayName()
{
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)myName, CENTER_MODE);   
}
//zobrazení logo win
void displayWinLogo()
{
    BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
    BSP_LCD_FillRect(185, 90, 50, 50);
    BSP_LCD_SetTextColor(LCD_COLOR_LIGHTBLUE);
    BSP_LCD_FillRect(185, 145, 50, 50);
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_FillRect(240, 90, 50, 50);
    BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
    BSP_LCD_FillRect(240, 145, 50, 50);
}
//hlavní část
int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    while (1) {
        BSP_LCD_Clear(LCD_COLOR_BLACK);
        displayName();
        displayWinLogo();
        HAL_Delay(20000);
    }
}
