#include "mbed.h"

DigitalOut greenLed(LED1);

void dot()
{
    greenLed = 1;
    wait(1.0);
    greenLed = 0;
    wait(1.0);
}

void dash()
{
    greenLed = 1;
    wait(3.0);
    greenLed = 0;
    wait(1.0);
}

void pause()
{
    greenLed = 0;
    wait(1.0);
}

int main()
{
    while(1) {
        dash();
        dot();
        dot();
        pause();
        dot();
        dash();
        pause();
        dot();
        dot();
        dot();
        dash();
        pause();
        dot();
        dot();
        pause();
        dash();
        dot();
        dot();
        wait(5.0);
    }
}