#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "win_ext_display.h"
#include <cstdint>
#include <string>

string boot_boardName = "STM32F7446G";
string boot_buildDate = "21. 11. 2020";
string boot_osVer = "mbed-os 6.5.0";
string boot_winExVer = "1.1 (hobbit-1)";
void boot_printBasicInfo()
{
    int line=15;
    string line1="# Start basic overview #";
    string line2="Board: "+boot_boardName;
    string line3="Version of OS: "+boot_osVer;
    string line4="Version of WinExtension: "+boot_winExVer;
    string line5="Build date: "+boot_buildDate;
    string line6="Starting...";
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);    
    BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)line1.c_str(), CENTER_MODE);
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(0, 30+4*(line), (uint8_t *)line2.c_str(), LEFT_MODE);
    BSP_LCD_DisplayStringAt(0, 30+5*(line), (uint8_t *)line3.c_str(), LEFT_MODE);
    BSP_LCD_DisplayStringAt(0, 30+6*(line), (uint8_t *)line4.c_str(), LEFT_MODE);
    BSP_LCD_DisplayStringAt(0, 30+7*(line), (uint8_t *)line5.c_str(), LEFT_MODE);
    BSP_LCD_DisplayStringAt(0, 30+10*(line), (uint8_t *)line6.c_str(), LEFT_MODE);
}

void loadWinExt()
{

    char line1_1[] = " Probiha priprava ";
    char line1_2[] = " Spoustim  system ";
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    for(int i=0;i<10;i++)
    {
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        if(i>3)
        {
            BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)line1_1, CENTER_MODE);
        }
        else
        {
            BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)line1_2, CENTER_MODE);
        }
        BSP_LCD_FillRect(15+(40*(i)), 225, 50, 5);
        ThisThread::sleep_for(1s);
    }
}

void displayLoginPage()
{
    int x=10;
    int y=30;
    int num=1;
    setWallpaperScreeen();
    //Vyberte uzivatele:
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DisplayStringAt(x, y, (uint8_t *)"VYBERTE UZIVATELE:", LEFT_MODE);
    //Na toto bude zvlášt metod, kteerá bude generovat i kliknutelná pole
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(x+50, y+35+10, 150, 60);
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(x+50+10, y+35+10+10+5, (uint8_t *)"David", LEFT_MODE);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(x+50, y+35+60+10+10, 150, 60);
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(x+50+10, y+35+60+10+10+10+5, (uint8_t *)"Admin", LEFT_MODE);

    
    
    
//
}