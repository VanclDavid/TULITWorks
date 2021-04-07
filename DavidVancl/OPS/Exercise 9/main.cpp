#include "mbed.h"
#include "LCDLibrary.h"
#include <cstdio>
#include "EthernetInterface.h"
#include <string>
#include "BufferedSerial.h"

DigitalIn button(BUTTON1);
BufferedSerial pc(USBTX, USBRX);
EthernetInterface eth;
Timeout intervalLimit;
bool limit = true,show_limit = false;

void clearLCD(){
    clearLineLCD(5);
}

void sendData_logic(){
    eth.connect();

    SocketAddress addr;
    eth.get_ip_address(&addr);
    if(!(addr.get_ip_address()))
    {
        const char dataERR[] = "ERROR DETECTED \n";
        pc.write(dataERR,sizeof dataERR);
        return;
    }

    nsapi_error_t ret = eth.gethostbyname("api.thingspeak.com", &addr);

    if (ret == NSAPI_ERROR_OK) {
        const char dataSUCC[] = "ASI OK BYCH REKL \n";
        pc.write(dataSUCC,sizeof dataSUCC);
    }   

    TCPSocket socket;
    socket.open(&eth);

    addr.set_port(80);
    socket.connect(addr);

    struct tm t;

    time_t seconds = time(NULL);
    std::string date = ctime(&seconds);
    std::string parameters = "api_key=7BGKHY6ER3G9WR3M&field1=19000047&field2="+date+"\r\n\r\n";
    std::string request = "POST /update HTTP/1.1\nHost: api.thingspeak.com\nConnection: close\nX-THINGSPEAKAPIKEY: 7BGKHY6ER3G9WR3M\nContent-Type: application/x-www-form-urlencoded\nContent-Length: "+to_string(parameters.length())+"\n\n"+parameters;
    int dataLength = request.length();

    char data[dataLength + 1];
    strcpy(data, request.c_str());
    pc.write(data,sizeof data);

    const char dataS[] = "\n SENDING DATA \n";
    pc.write(dataS,sizeof dataS);
    socket.send(data, sizeof(data));

    char rbuffer[64];
    int rcount = socket.recv(rbuffer, sizeof rbuffer);
    pc.write(rbuffer, sizeof rbuffer);

    socket.close();
    eth.disconnect();
    const char dataE[] = "\n END \n";
    pc.write(dataE,sizeof dataE);
}

void resetLimit(){
    clearLineLCD(5);
    limit = true;
}

void detect_button(){
    int was = 0;
    while (true) {
        int is = 0;
        if((is = button.read()) == 1 && was== 0 && limit){
            printOnLineLCD(5,(uint8_t *) "SENDING DATA", CENTER_MODE);
            limit = false;
            show_limit = true;
            Thread con_thread;
            con_thread.start(sendData_logic);
            con_thread.join();
            intervalLimit.attach(resetLimit,2.0);
        } else if (limit == false && show_limit){
            show_limit = false;
            clearLineLCD(5);
            printOnLineLCD(5,(uint8_t *) "TIMEOUT ty moulo", CENTER_MODE);
        }
        was = is;
    }
}

int main()
{
    set_time(1606405800);
    pc.set_baud(9600);
    Thread button_thread;
    
    initLCD();
    preparePrintLCD(LCD_COLOR_BLACK,&LCD_DEFAULT_FONT,LCD_COLOR_BLACK,LCD_COLOR_WHITE);

    button_thread.start(detect_button);
    button_thread.join();
}