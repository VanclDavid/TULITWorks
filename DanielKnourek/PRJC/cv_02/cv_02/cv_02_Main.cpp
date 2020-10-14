#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h";
#include <iostream>
#include <process.h>
#include <string>

int main() {

    printf("Hello World! \n\r");
    system("pause");

    std::string str;
    std::getline(std::cin, str);

    printf("%s \n", str);
    system("pause");
    return 0;
    //scanf je problem ze posledni enter nenacte a necha ho v inpout stream,  getchar()
}