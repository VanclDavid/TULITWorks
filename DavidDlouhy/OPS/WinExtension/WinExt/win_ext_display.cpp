#include "win_ext_display.h"

void setBlackScreen()
{
    BSP_LCD_Clear(LCD_COLOR_BLACK);
}

void initDisplay()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    setBlackScreen();
}

void displayWinLogo_boot_big()
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

void setWallpaperScreeen()
{
    BSP_LCD_Clear(WALLPAPER);
    BSP_LCD_SetBackColor(WALLPAPER);
}

uint16_t * touchscreen_getPoss()
{
    TS_StateTypeDef TS_State;
    static uint16_t posit [2]; 
    uint8_t status;
    status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    while(1) {
        BSP_TS_GetState(&TS_State);
        if (TS_State.touchDetected) {
            
            posit[0] = TS_State.touchX[0];
            posit[1] = TS_State.touchY[0];
            return posit;
        } 
    }
}

void displayWinStartPanel()
{
 BSP_LCD_SetTextColor(PANEL);
    BSP_LCD_FillRect(0, 250, 480, 25);
}
void displayWinLogoStartPanel()
{
    BSP_LCD_SetTextColor(PANEL);
    BSP_LCD_FillRect(0, 250, 25, 25);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(4, 253, 7, 7);
    BSP_LCD_FillRect(13, 253, 7, 7);
    BSP_LCD_FillRect(4, 262, 7, 7);
    BSP_LCD_FillRect(13, 262, 7, 7);
}

void clickWinLogoStartPanel()
{
    BSP_LCD_SetTextColor(PANEL_LIGHT);
    BSP_LCD_FillRect(0, 250, 25, 25);
    BSP_LCD_SetTextColor(WALLPAPER);
    BSP_LCD_FillRect(4, 253, 7, 7);
    BSP_LCD_FillRect(13, 253, 7, 7);
    BSP_LCD_FillRect(4, 262, 7, 7);
    BSP_LCD_FillRect(13, 262, 7, 7);
}
 
void displayWinStartMenuLine(int x, int y, uint32_t color, string textOfLine)
{
   BSP_LCD_SetTextColor(color);
    BSP_LCD_FillRect(x, y, 20, 20);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(PANEL);
    BSP_LCD_SetFont(&Font8);
    BSP_LCD_DisplayStringAt(x+25, y+7.5, (uint8_t *)textOfLine.c_str(), LEFT_MODE);
    //BSP_LCD_FillRect(x+25, y+7.5, 40, 5);    
}


void displayWinStartMenu(string * userName)
{
    BSP_LCD_SetTextColor(PANEL);
    BSP_LCD_FillRect(0, 90, 130, 160);
    BSP_LCD_SetFont(&Font8);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(PANEL);
    BSP_LCD_DisplayStringAt(8, 93+6, (uint8_t *)((*userName).c_str()), LEFT_MODE);
    displayWinStartMenuLine(8, 93+22, LCD_COLOR_RED, "Restartovat");
    displayWinStartMenuLine(8, 93+2*22, LCD_COLOR_ORANGE, "Minutka");
    displayWinStartMenuLine(8, 93+3*22, LCD_COLOR_WHITE, "Odhlasit se");
    displayWinStartMenuLine(8, 93+4*22, LCD_COLOR_DARKYELLOW, "TUL");
    displayWinStartMenuLine(8, 93+5*22, LCD_COLOR_LIGHTMAGENTA, "Hry");       
}


void touchscreen_resetPoss(uint16_t *x, uint16_t *y)
{
    *x=-1;
    *y=-1;
}
void displayLoginPageWelcomw(string * userName)
{
    setWallpaperScreeen();
    BSP_LCD_SetFont(&Font20);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE); 
    string line1 = "Vitejte: "+(*userName);
    BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)(line1.c_str()), CENTER_MODE);
}

void closeWinMenu()
{
    setWallpaperScreeen();
    displayWinStartPanel();
    displayWinLogoStartPanel();
}
void displayWindow()
{
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 20);
    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    BSP_LCD_FillRect(BSP_LCD_GetXSize()-20, 0, 20, 19);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_RED);
    string headerLine="X";
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_DisplayStringAt(BSP_LCD_GetXSize()-15, 3, (uint8_t *)headerLine.c_str(), LEFT_MODE);
}

void displayMinutkaGUI(int *minute, int *sec)
{
    string headerLine="Minutka";
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
        BSP_LCD_SetFont(&Font8);
        BSP_LCD_DisplayStringAt(10, 8, (uint8_t *)headerLine.c_str(), LEFT_MODE);

    string line1="";
    if(*minute<10)
    {
        line1 += "0";
    }
    line1+=(to_string(*minute)+":");
    if(*sec<10)
    {
        line1 += "0";
    }
    line1+=(to_string(*sec));
    string line2="-";
    string line3="+";
    string line4="START";
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_FillRect((BSP_LCD_GetXSize()/2)-112-2, 90-2, 30+4, 30+4);
    BSP_LCD_FillRect((BSP_LCD_GetXSize()/2)+85-2, 90-2, 30+4, 30+4);
    BSP_LCD_FillRect((BSP_LCD_GetXSize()/2-40-2), 180-2, 80+4, 30+4);
    
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect((BSP_LCD_GetXSize()/2-112), 90, 30, 30);
    BSP_LCD_FillRect((BSP_LCD_GetXSize()/2+85), 90, 30, 30);
    BSP_LCD_FillRect((BSP_LCD_GetXSize()/2-40), 180, 80, 30);

    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font20);
    BSP_LCD_DisplayStringAt((BSP_LCD_GetXSize()/2-112+7), 97, (uint8_t *)(line2.c_str()), LEFT_MODE);
    BSP_LCD_DisplayStringAt((BSP_LCD_GetXSize()/2)+85+7, 97, (uint8_t *)(line3.c_str()), LEFT_MODE);
    BSP_LCD_DisplayStringAt((BSP_LCD_GetXSize()/2-40+5), 180+5, (uint8_t *)(line4.c_str()), LEFT_MODE);

    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(0, 95, (uint8_t *)(line1.c_str()), CENTER_MODE);

    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    
    //BSP_LCD_DisplayStringAt(0, 95, (uint8_t *)(line1.c_str()), CENTER_MODE);

}

void updateTimeDisplayMinutkaGUI(int *minute, int *sec)
{
    string line1="";
    if((*minute)<10)
    {
        line1 += "0";
    }
    line1+=(to_string(*minute)+":");
    if(*sec<10)
    {
        line1 += "0";
    }
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(0, 95, (uint8_t *)(line1.c_str()), CENTER_MODE);
}

void setRedScreen()
{
    BSP_LCD_Clear(LCD_COLOR_RED);
}

void displayProgramLaunch(uint32_t * color, uint32_t * p_color_text_program, string * programName)
{
    BSP_LCD_Clear((*color));
    BSP_LCD_SetFont(&Font20);
    BSP_LCD_SetTextColor((*p_color_text_program)); 
    BSP_LCD_SetBackColor((*color)); 
    string line1 = (*programName);
    BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)(line1.c_str()), CENTER_MODE);
}