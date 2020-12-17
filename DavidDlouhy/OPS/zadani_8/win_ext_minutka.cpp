#include "win_ext_program_minutka.h"
#include <cstdint>

void minutka_updateTime(int *minute, int *sec, bool count_up)
{
    if(count_up)
    {
        if((*sec)==59)
        {
            (*sec)=0;
            (*minute)++;
        }
        else {
        (*sec)++;
        }
    }
    else
    {
        if(*sec==0)
        {
            if((*minute)!=0)
            {
                (*sec)=59;
                (*minute)--;
            }
        }
        else {
            if((*sec)!=0)
            {
                (*sec)--;
            }
        } 
    }
    updateTimeDisplayMinutkaGUI(minute, sec);
}

void startProgram_minutka(uint16_t *p_x, uint16_t *p_y, DigitalIn *button_1)
{
    int time_minute=2;
    int time_secund=0;
    int * p_time_minute=&time_minute;
    int * p_time_secund=&time_secund;
    displayWindow();
    bool stop_program=false;
    displayMinutkaGUI(p_time_minute, p_time_secund);
    while(!stop_program)
    {  
        if(((*p_y)>=88&&(*p_y)<=88+30+4)&&((*p_x)>((BSP_LCD_GetXSize()/2)-112-2)&&(*p_x)<(BSP_LCD_GetXSize()/2)-112-2+34))
        {
            minutka_updateTime(p_time_minute, p_time_secund, false);
            displayMinutkaGUI(p_time_minute, p_time_secund);
            touchscreen_resetPoss(p_x, p_y);
        }
        if(((*p_y)>=88&&(*p_y)<=88+30+4)&&((*p_x)>((BSP_LCD_GetXSize()/2)+85-2)&&(*p_x)<(BSP_LCD_GetXSize()/2)+85-2+34))
        {
            minutka_updateTime(p_time_minute, p_time_secund, true);
            displayMinutkaGUI(p_time_minute, p_time_secund);
            touchscreen_resetPoss(p_x, p_y);
        }
        if((((*p_x)>=(BSP_LCD_GetXSize()/2-40-2))&&((*p_x)<=(BSP_LCD_GetXSize()/2-40-2+84)))&&(((*p_y)>=180-2)&&((*p_y)<=80+4+180-2)))
        {
            touchscreen_resetPoss(p_x, p_y);
            bool loop =true;
            bool redScreenEnabled =true;
            while(loop)
            {
                minutka_updateTime(p_time_minute,  p_time_secund, false);
                displayMinutkaGUI(p_time_minute, p_time_secund);
                
                if(((*p_y)>0&&(*p_y)<=20)&&((*p_x)>(BSP_LCD_GetXSize()-20)&&(*p_x)<BSP_LCD_GetXSize()))
                {
                    stop_program=true;
                    loop=false;
                    redScreenEnabled=false;
                }
                if((time_minute)+(time_secund)==0)
                {
                    loop=false;
                }
                ThisThread::sleep_for(1s);
            } 
            time_minute=2;
            time_secund=0;
            if(redScreenEnabled)
            {
                setRedScreen();
            }
            while(!(*button_1)){
                if(!redScreenEnabled)
                {
                    break;
                }
            }
            displayWindow();
            displayMinutkaGUI(p_time_minute, p_time_secund);
            touchscreen_resetPoss(p_x, p_y);
        }
        if(((*p_y)>0&&(*p_y)<=20)&&((*p_x)>(BSP_LCD_GetXSize()-20)&&(*p_x)<BSP_LCD_GetXSize()))
        {
            stop_program=true;
        }
    }
}