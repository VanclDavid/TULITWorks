#include "mbed.h"
#include <cstdint>

static BufferedSerial pc(USBTX, USBRX);
DigitalIn btn(BUTTON1);

char textOnClick[] = "Give me a Cookie ";
char textOnClick2[] = "\nCo se asi muze stat, kdyz se 3x zmackne tlacitko...\n";
char textOnClick3[] =" 1. stisk\n";
char textOnClick4[] =" 2. stisk\n";
char textOnClick5[] ="\nThank you!\n";
bool cookie=false;
Thread thread_1;
Thread thread_2;

void proces_1()
{
    while(1)
    {
    while(cookie)
    {
        for(int x=0; x<sizeof(textOnClick);x++)
        {
            pc.write(&textOnClick[x], sizeof(char));
        }
    }
    }
}



void proces_2()
{
    btn.mode(PullDown);    
    uint8_t size = sizeof(textOnClick2), last = btn.read(),actual;
    pc.write(textOnClick2,sizeof(textOnClick2));
    int counter=0;
    while(true){
        
        actual = btn.read();
        if (actual != last) {
            last = actual;
            if(actual){
                if(counter==0)
                {
                    for(int x=0; x<sizeof(textOnClick3);x++)
                    {
                        pc.write(&textOnClick3[x], sizeof(char));
                    }
                }
                if(counter==1)
                {
                    for(int x=0; x<sizeof(textOnClick4);x++)
                    {
                        pc.write(&textOnClick4[x], sizeof(char));
                    }
                }
                if(counter==2)
                {
                    //CHCI SUSENKU
                    cookie=true;
                }
                if(counter==3)
                {
                    //DOSTAL JSEM SUSUENKU
                    cookie=false;
                    counter=-1;
                    ThisThread::sleep_for(200);
                    for(int x=0; x<sizeof(textOnClick5);x++)
                    {
                        pc.write(&textOnClick5[x], sizeof(char));
                    }
                }
              counter++;
            }
        }
    }
}


int main()
{
    
    thread_1.start(proces_1);
    thread_2.start(proces_2);
    while(1)
    {
    }
}
