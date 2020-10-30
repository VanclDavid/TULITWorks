#include "mbed.h"

DigitalOut myled(LED1);
//funkce na blikání
void blik(double time)
{
    myled=1;
    wait(time);
    myled=0;
    wait(time);
}
int main() {  
    //smyčka s dynamickou úpravou blikání (pomalu -> rychle)
     while(1) {
        double i = 3;
        while(i>0.1)
        {
            blik(i);
            if(i>1)
            {
                i=i-1.0;
            }
            else
            {
                if(i>0.5)
                {
                    i=i-0.2;
                }
                else
                {
                    i=i-0.01;    
                }
            }
        }
    } 
}

