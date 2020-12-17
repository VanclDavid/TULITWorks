    //proovnej příkazy s přečteným řádkem
    //proveď přesnou shodu

    //příkazy - zvlášt c++
    ////get-command
    ////reset-device
    ////set-watchdog
    ////get-sysinfo
    ////get-date
#include "mbed.h"
#include <string>
#include <iomanip>
#include <stdio.h>

void winExt_writeEndOfLine();
void winExt_startSerial();
void getcommand();
void resetdevice();
void setwatchdog();
string getsysinfo();
string getdate();
string readcommand();
void execute_command();