#include <inttypes.h>
#include "mbed.h"
#include "LCDLibrary.h"

#if !defined(MBED_THREAD_STATS_ENABLED)
#error "Thread statistics not enabled"
#endif
 
#define MAX_THREAD_STATS    0x8
#define BLINKY_THREAD_STACK 224
#define IDLE_THREAD_STACK 384
#define STOP_FLAG 0xEF
#define WAIT_TIME_MS 500

static EventFlags idle_ef;

DigitalIn button(USER_BUTTON);
DigitalOut led1(LED1);

Thread thread1;
Thread thread2;
Thread thread3;

void thread1_void()
{
    while (true) {
        printOnLineLCD(3, (uint8_t *)"THREAD 1", CENTER_MODE);
        pauseLCD(2000);
        clearLineLCD(3);
        pauseLCD(2000);
        printOnLineLCD(3, (uint8_t *)"Pepicku,", CENTER_MODE);
        printOnLineLCD(4, (uint8_t *)"kolik druhu opic znas?", CENTER_MODE);
        printOnLineLCD(5, (uint8_t *)"...", CENTER_MODE);
        printOnLineLCD(6, (uint8_t *)"Ani jeden, pani ucitelko,", CENTER_MODE);
        printOnLineLCD(7, (uint8_t *)"ja jsem abstinent!", CENTER_MODE);
        pauseLCD(2000);
        clearLineLCD(3);
        clearLineLCD(4);
        clearLineLCD(5);
        clearLineLCD(6);
        clearLineLCD(7);
        pauseLCD(2000);
    }
}

void thread2_void()
{
    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(1000);
    }
}

void thread3_void()
{
    while(true){
        if(button){
            clearLineLCD(9);
            printOnLineLCD(9, (uint8_t *)"BUTTON - ON", CENTER_MODE);

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
        } else {
            clearLineLCD(9);
            printOnLineLCD(9, (uint8_t *)"BUTTON - OFF", CENTER_MODE);
        }
        HAL_Delay(500);
    } 
}

int main()
{
    initLCD();
    preparePrintLCD(LCD_COLOR_BLACK,&LCD_DEFAULT_FONT,LCD_COLOR_BLACK,LCD_COLOR_WHITE);
    
    thread1.start(thread1_void);
    thread2.start(thread2_void);
    thread3.start(thread3_void);

    while(true){
        BSP_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"MAIN THREAD", CENTER_MODE);
        pauseLCD(1000);
        BSP_LCD_ClearStringLine(1);
        pauseLCD(1000);
    }
}
