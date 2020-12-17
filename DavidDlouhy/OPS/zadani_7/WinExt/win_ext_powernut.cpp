#include "win_ext_powernut.h"

Watchdog &watchdog_os=Watchdog::get_instance();
static BufferedSerial pc(USBTX, USBRX);
char beg_of_line[] = "WE STM@David > ";
char serialStartMess[] = "\n\rWinExtension PowerNut\n\r\n\rNadstavba WinExtension [Verison: 1.1 - hobbit-1]\n\r\n\r";
char newLine[]="\r\n";

void winExt_startSerial()
{
    pc.write(serialStartMess, sizeof(serialStartMess));
}

void winExt_writeEndOfLine()
{
    pc.write(newLine, sizeof(newLine));
}


void getcommand()
{

    char out[] ="get-command  -> zobrazi vsechny prikazy\n\rreset-device -> restartuje zarizeni\n\r";
    pc.write(out, sizeof(out));
}

void resetdevice()
{
    winExt_writeEndOfLine();
    winExt_writeEndOfLine();
    winExt_writeEndOfLine();
    NVIC_SystemReset();
}

void setwatchdog()
{
    watchdog_os.start(600);
}

string getsysinfo()
{
    return "NEIMPLEMETOVANO";
}

string getdate()
{
  return "NEIMPLEMETOVANO";
}

string readcommand()
{
    int max_size_buff= 1024;
    char *big_buff=new char[max_size_buff];

    pc.write(beg_of_line, sizeof(beg_of_line));
    char *buff = new char[1];
    
    (pc).write(buff, sizeof(buff));
    char *letter = new char[1];
    (pc).read(buff, sizeof(buff));
    letter[0] = buff[0];
    int counter=0;
    while(letter[0]!='\x0D')
    {
        big_buff[counter]=letter[0];
        counter++;
        pc.write(buff, sizeof(buff));
        (pc).read(buff, sizeof(buff));
        letter[0] = buff[0];
    }
    if(counter>0)
    {
        string out="";
        char *out_array = new char[counter];
        /*for(int i=0; i<counter;i++)
        {
            out_array[i]=big_buff[i];
        }*/
        out.append(big_buff, counter);
        return out;
    }
    big_buff=NULL;
    buff=NULL;
    return NULL;
}

void execute_command()
{
    string input= readcommand();
    winExt_writeEndOfLine();
    int ex=0;
    if(input=="get-command")
    {
        getcommand();
        ex++;
    }
    if(input=="reset-device")
    {
        resetdevice();
        ex++;
    }
    if(input=="set-watchdog")
    {
        setwatchdog();
        ex++;
    }
    if(ex==0)
    {
        char msg[] =  "Příkaz není v listu!";
        pc.write(msg, sizeof(msg));
    }
    winExt_writeEndOfLine();
}