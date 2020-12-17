#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <cstdint>
#include <string>
#include "win_ext_display.h"
#include "win_ext_boot.h"
#include "win_ext_program_minutka.h"

DigitalIn button_1(USER_BUTTON);
uint16_t x, y;

DigitalIn * p_button_1=&button_1;
uint16_t * p_x=&x;
uint16_t * p_y=&y;

int userID=0;
string winext_users[3];

//DEBUG---------------------------------------------------------------------------
void touch_debug()
{
    string textOfLine="X:"+to_string(x)+" Y:"+to_string(y);
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(PANEL);
        BSP_LCD_SetFont(&Font8);
        BSP_LCD_DisplayStringAt(10, 10, (uint8_t *)textOfLine.c_str(), LEFT_MODE);
}
//DEBUG---------------------------------------------------------------------------
//OBSLUHY---------------------------------------------------------------------------
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
        }   
    }
}

Thread thread_ReadTouch;
void proces_ReadTouch()
{
    while(1) {
        uint16_t * posOfTouch;
        posOfTouch = touchscreen_getPoss();
        x=posOfTouch[0];
        y=posOfTouch[1];
        uint16_t tmp_x, tmp_y;
        ThisThread::sleep_for(10ms);
        if(tmp_x==x && tmp_y==y)
        {
            x=-1;
            y=-1;
        }
    }
}
//OBSLUHY---------------------------------------------------------------------------

Thread thread_boot;
void proces_boot()
{
    boot_printBasicInfo();
    ThisThread::sleep_for(5s);
    setBlackScreen();
}

Thread thread_loadingOS;
void proces_loadingOS()
{
    displayWinLogo_boot_big();
    loadWinExt();  
    setBlackScreen();
}

void proces2()
{
    startProgram_minutka(p_x, p_y, p_button_1);
}
void osdesktop()
{
    setWallpaperScreeen();
    displayWinStartPanel();
    displayWinLogoStartPanel();
    touchscreen_resetPoss(p_x,p_y);
    bool open_menu=false;
    bool pre_open_menu=false;
    string * p_userID=&winext_users[userID];
    while(1)
    {
        
        if((x<25&&x>0)&&(y<275&&y>250))
        {
            clickWinLogoStartPanel();
            displayWinStartMenu(p_userID);
            touchscreen_resetPoss(p_x,p_y);
            open_menu=true;
        }
        if(open_menu&&(!(pre_open_menu==open_menu)))
        {
            clickWinLogoStartPanel();
            displayWinStartMenu(p_userID);
            touchscreen_resetPoss(p_x,p_y);
        }
        if((((x<130)&&(y<90||y>250)))&&(open_menu))
        {
            if(x>0&&y>0)
            {
            closeWinMenu();
            open_menu=false;
            }
        }
        if(x>130&&(open_menu))
        {
            if(x>0&&y>0&&x<65535)
            {
            closeWinMenu();
            open_menu=false;
            }
        }
        pre_open_menu=open_menu;       
        if(open_menu)
        {
            uint32_t color_program = LCD_COLOR_BLACK;
            uint32_t color_text_program = LCD_COLOR_WHITE;
            string programName_program = "ERR";
            uint32_t * p_color_program=&color_program;
            uint32_t * p_color_text_program=&color_text_program;
            string * p_programName_program=&programName_program;
            //ODHLASENI
            if((x<29&&x>7)&&(y<(93+3*22)+20&&y>91+3*22))
            {
                programName_program="Nasheldanou...";
                displayProgramLaunch(p_color_program, p_color_text_program, p_programName_program);
                ThisThread::sleep_for(2s);
                userID=0;
                touchscreen_resetPoss(p_x,p_y);
                break;
            }
            //RESTART
            if((x<29&&x>7)&&(y<(93+22)+20&&y>91+22))
            {
                programName_program="Restartovani...";
                displayProgramLaunch(p_color_program, p_color_text_program, p_programName_program);
                ThisThread::sleep_for(2s);
                NVIC_SystemReset();
            }
            //MINUTKA
            if((x<29&&x>7)&&(y<(93+2*22)+20&&y>91+2*22))
            {
                color_program=LCD_COLOR_ORANGE;
                color_text_program=LCD_COLOR_BLACK;
                programName_program="MINUTKA";
                displayProgramLaunch(p_color_program, p_color_text_program, p_programName_program);
                ThisThread::sleep_for(2s);
                //TOTO JE SPOUSTENI PROGRAMU
                touchscreen_resetPoss(p_x,p_y);
                Thread vlakno2;
                vlakno2.start(proces2);
                vlakno2.join();
            }
            //DALSI
            //...
            
        }
    }
}

Thread thread_login;
void proces_login()
{
    x=-1;
    y=-1;
    while(1)
    {
    while(userID==0)
    {
        BSP_LCD_DisplayStringAt(0, LINE(0), (uint8_t *)"", LEFT_MODE);
        if((x<200&&x>60)&&(y<130&&y>80))
        {
            userID=1;
        }
        if((x<200&&x>60)&&(y<200&&y>145))
        {
            userID=2;
        }
    }
    string * p_userID=&winext_users[userID];
    displayLoginPageWelcomw(p_userID);
    ThisThread::sleep_for(2s);
    osdesktop();
    displayLoginPage();
    }
}

int main()
{
    winext_users[0]="NONE";
    winext_users[1]="David";
    winext_users[2]="Admin";
    bool skip = false;
    //BOOT
    initDisplay();
    thread_ReadTouch.start(proces_ReadTouch);
    thread_ReadButton.start(proces_ReadButton);
    if(!skip)
    {
        thread_boot.start(proces_boot);
        thread_boot.join();
    }
    //BOOT
    //OS LOADING
    if(!skip)
    {
        thread_loadingOS.start(proces_loadingOS);
        thread_loadingOS.join();
    }
    //OS LOADING
    //OS
    displayLoginPage();
    thread_login.start(proces_login);
    thread_login.join();
    //OS

    while(1)
    {

    }
}
