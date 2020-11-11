#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#define WALLPAPER ((uint32_t)0xFF359AFF)
#define PANEL ((uint32_t)0xBB606060)
#define PANEL_LIGHT ((uint32_t)0xBBBCBCBC)


InterruptIn sw(BUTTON1);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;
int openStartDetect=0;

void displayWinStartMenuLine(int x, int y, uint32_t color)
{
   BSP_LCD_SetTextColor(color);
    BSP_LCD_FillRect(x, y, 20, 20);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(x+25, y+7.5, 40, 5);    
}

void displayWinStartMenu()
{
    BSP_LCD_SetTextColor(PANEL);
    BSP_LCD_FillRect(0, 90, 130, 160);
    displayWinStartMenuLine(8, 93+22, LCD_COLOR_RED);
    displayWinStartMenuLine(8, 93+2*22, LCD_COLOR_LIGHTMAGENTA);
    displayWinStartMenuLine(8, 93+3*22, LCD_COLOR_WHITE);
    displayWinStartMenuLine(8, 93+4*22, LCD_COLOR_DARKYELLOW);
    displayWinStartMenuLine(8, 93+5*22, LCD_COLOR_ORANGE);       
}

void exitWinStartMenu()
{
    BSP_LCD_SetTextColor(WALLPAPER);
    BSP_LCD_FillRect(0, 90, 130, 160);
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



void rise_handler(void)
{
    queue.call(printf, "rise_handler in context %p\n", ThisThread::get_id()); 

    openStartDetect=openStartDetect+1;
    clickWinLogoStartPanel();
    
    if(openStartDetect==1)
    {
        displayWinStartMenu();
        openStartDetect=openStartDetect+1;
    }
    else
    {
        openStartDetect=0;
        exitWinStartMenu();    
    }
    
    
    //queue.call(displayWinStartMenu());
}

void fall_handler(void)
{
    queue.call(printf,"fall_handler in context %p\n", ThisThread::get_id());
     displayWinLogoStartPanel();
}

int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_Clear(WALLPAPER);
    displayWinStartPanel();
    displayWinLogoStartPanel();
    t.start(callback(&queue, &EventQueue::dispatch_forever));
    printf("Starting in context %p\r\n", ThisThread::get_id());
    sw.rise(rise_handler);
    sw.fall(fall_handler);
    while (1) {
        //HAL_Delay(20000);
    }
}
