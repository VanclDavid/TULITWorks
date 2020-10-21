#include "mbed.h"
#include "LCDLibrary.h"

InterruptIn button(USER_BUTTON);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread thread;

int riseStuff = 0, fallStuff = 0;

void riseHandler(void) {
    clearLineLCD(7);

    switch (riseStuff) {
    case 0:
        BSP_LCD_SetTextColor(LCD_COLOR_LIGHTRED);
        BSP_LCD_FillCircle(125, 55, 50);

        queue.call(clearLineLCD, 7);
        queue.call(printOnLineLCD, 7, (uint8_t*)"RED LIGH - ON", CENTER_MODE);

        riseStuff++;
        break;
    case 1:
        BSP_LCD_SetTextColor(LCD_COLOR_LIGHTYELLOW);
        BSP_LCD_FillCircle(230, 55, 50);

        queue.call(clearLineLCD, 7);
        queue.call(printOnLineLCD, 7, (uint8_t*)"YELLOW LIGH - ON", CENTER_MODE);

        riseStuff++;
        break;
    case 2:
        BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGREEN);
        BSP_LCD_FillCircle(335, 55, 50);

        queue.call(clearLineLCD, 7);
        queue.call(printOnLineLCD, 7, (uint8_t*)"GREEN LIGH - ON", CENTER_MODE);

        riseStuff = 0;
        break;
    }
}

void fallHandler(void) {
    clearLineLCD(7);

    switch (fallStuff) {
    case 0:
        BSP_LCD_SetTextColor(LCD_COLOR_DARKRED);
        BSP_LCD_FillCircle(125, 55, 50);
        fallStuff++;
        break;
    case 1:
        BSP_LCD_SetTextColor(LCD_COLOR_DARKYELLOW);
        BSP_LCD_FillCircle(230, 55, 50);
        fallStuff++;
        break;
    case 2:
        BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
        BSP_LCD_FillCircle(335, 55, 50);
        fallStuff = 0;
        break;
    }
}

int main()
{
    initLCD();
    preparePrintLCD(LCD_COLOR_BLACK, &LCD_DEFAULT_FONT, LCD_COLOR_BLACK, LCD_COLOR_WHITE);

    thread.start(callback(&queue, &EventQueue::dispatch_forever));

    BSP_LCD_SetTextColor(LCD_COLOR_DARKRED);
    BSP_LCD_FillCircle(125, 55, 50);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKYELLOW);
    BSP_LCD_FillCircle(230, 55, 50);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
    BSP_LCD_FillCircle(335, 55, 50);

    button.rise(riseHandler);
    button.fall(fallHandler);

    while (true) {}
}