#include "mbed.h"
#include <inttypes.h>
#include "stm32746g_discovery_lcd.h"
#if !defined(MBED_THREAD_STATS_ENABLED)
#error "Thread statistics not enabled"
#endif
 
#define MAX_THREAD_STATS    0x8
#define BLINKY_THREAD_STACK 224
#define IDLE_THREAD_STACK 384
#define STOP_FLAG 0xEF
#define WAIT_TIME_MS 500

static EventFlags idle_ef;

int runCode=0;
char myName[] =      "   David Dlouhy   ";
char msg_welcome[] = "Vitejte uzivateli:";
char msg_loading[] = " Probiha priprava ";
char msg_start[] =   " Spoustim  system ";

int load_counter;

Thread thread_1;
Thread thread_2;
Thread thread_3;
Thread thread_4;

DigitalOut myled(LED1);
DigitalIn mybut(USER_BUTTON);

void blik(double time)
{
    myled=1;
    wait(time);
    myled=0;
    wait(time);
}

void displayName()
{
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)myName, CENTER_MODE);   
}
void displayText(char input[])
{
    if(runCode==0)
    {
    BSP_LCD_ClearStringLine(30);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)input, CENTER_MODE);   }
}
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
void blueDeath()
{
    runCode=1;
    BSP_LCD_Clear(LCD_COLOR_BLUE);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
    BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)"A problem has been detected...", CENTER_MODE);   
    BSP_LCD_DisplayStringAt(0, 60, (uint8_t *)"Stop code:", CENTER_MODE); 
    BSP_LCD_DisplayStringAt(0, 90, (uint8_t *)"*** STOP: 0x000000C5", CENTER_MODE); 
}
void proces_1()
{
    //kod
    while(1)
    {
        if(load_counter<20)
        {
            displayText(msg_start);
        }  
        if(load_counter<90&&load_counter>20)
        {
            displayText(msg_loading);
        }
    
        if(load_counter>90&&load_counter<100)
        {
            displayText(msg_welcome);
        }
        if(load_counter==100)
        {
            displayText(myName);
        }
    }  
}

void proces_2()
{
    displayWinLogo();
    while(load_counter<100)
    {
        wait(1);
        if(runCode==0)
        {
            
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_FillRect(15+(4*(load_counter)), 225, 50, 5);
        load_counter++;}
    }
}

void proces_3()
{
    bool active = false;
    while(1){
        if(mybut){  
            active = true;
        }
        if(active)
        {
            active = false;
            blueDeath();
        }   
    }

}

void proces_4()
{
    double interval = 0.5;
    while(1)
    {
        while(interval<1.0)
        {
            interval=interval+0.1;
            blik(interval);
        }
        while(interval>0.1)
        {
            interval=interval-0.1;
            blik(interval);
        }
    }
}
int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    displayName();
    displayWinLogo();
    thread_1.start(proces_1);
    thread_2.start(proces_2);
    thread_3.start(proces_3);
    thread_4.start(proces_4);
    mbed_stats_thread_t *stats;
    int count;
    printf("=======THREAD INFO=======\n");
    stats = new mbed_stats_thread_t[MAX_THREAD_STATS];
    count = mbed_stats_thread_get_each(stats, MAX_THREAD_STATS);
    for (int i = 0; i < count; i++) {
        printf("ID: 0x%" PRIx32 "\n", stats[i].id);
        printf("Name: %s \n", stats[i].name);
        printf("State: %" PRId32 "\n", stats[i].state);
        printf("Priority: %" PRId32 "\n", stats[i].priority);
        printf("Stack Size: %" PRId32 "\n", stats[i].stack_size);
        printf("Stack Space: %" PRId32 "\n", stats[i].stack_space);
        printf("\n");
    }

    while (1) {
        //HAL_Delay(20000);
    }
}
