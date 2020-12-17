#include "win_ext_network_wokrer.h"
#include <string>

EthernetInterface ethernet_connector;

std::string convertToString(char* a, int size) 
{ 
    string s = a; 
    return s; 
}

std::string win_ext_getDate()
{
   // NTPClient ntp;

    printf("NTP Client example (using Ethernet)\r\n");
    EthernetInterface ethernet_connector;
    NTPClient ntp(&ethernet_connector);
    time_t timestamp = ntp.get_timestamp();
    std::tm * ptm = std::localtime(&timestamp);
    char buffer[32];

    std::strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", ptm);

    int b_size = sizeof(buffer) / sizeof(char); 
    std::string s_buffer = convertToString(buffer, b_size); 

    printf("%s", s_buffer.c_str());
    //std::printf("Follow this command: %s", myString.c_str());
    return s_buffer;
}

std::string win_ext_sendZapocet()
{
    printf("Start eth komunikace\n");
    ethernet_connector.connect();
    SocketAddress a;
    ethernet_connector.get_ip_address(&a);
    if(!(a.get_ip_address()))
    {
        printf("Chyba ip_err\n");
        return "NEPODARILO SE - IP_ERR!";
    }
    printf("IP address: %s\n", a.get_ip_address() ? a.get_ip_address() : "None");
    TCPSocket socket;
    socket.open(&ethernet_connector);
    ethernet_connector.gethostbyname("api.thingspeak.com", &a);
    a.set_port(80);
    socket.connect(a);
    std::string datum = win_ext_getDate();
    std::string text ="7BGKHY6ER3G9WR3M&field1=19000010&field2="+datum+"\r\n\r\n";
    std::string pozadavek = "POST /update HTTP/1.1\nHost: api.thingspeak.com\nConnection: close\nX-THINGSPEAKAPIKEY: 7BGKHY6ER3G9WR3M\nContent-Type: application/x-www-form-urlencoded\nContent-Length: "+std::to_string(text.length())+"\n\n"+text;
    char sbuffer[pozadavek.length()];
    int i;
    for (i = 0; i < sizeof(sbuffer); i++) {
        sbuffer[i] = pozadavek[i];
    }
    int scount = socket.send(sbuffer, sizeof sbuffer);
    printf("sent %d [%.*s]\n", scount, strstr(sbuffer, "\r\n") - sbuffer, sbuffer);
    char rbuffer[64];
    int rcount = socket.recv(rbuffer, sizeof rbuffer);
    printf("recv %d [%.*s]\n", rcount, strstr(rbuffer, "\r\n") - rbuffer, rbuffer);
    if(rcount!=64)
    {
        printf("Chyba trans_err\n");
        socket.close();
        return"NEPODARILO SE - TRANS_ERR!";
    }
    socket.close();
    ethernet_connector.disconnect();
    printf("Konec eth komunikace\n");
    return "OK";
}