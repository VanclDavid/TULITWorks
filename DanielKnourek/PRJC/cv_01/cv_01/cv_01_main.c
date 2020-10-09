#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int main() {

    //printf("Hello World!");

    FILE* fOriginal;
    fOriginal = fopen("SOUBOR.TXT", "r");
    int a;
    while (fscanf(fOriginal, "%d", &a) != EOF) {
        printf("%d \n", a);

        system("pause");
    }
          
    fclose(fOriginal);

    //FILE* fw;
    //fw = fopen("SOUBOR.TXT", "a");
    //fprintf(fw, "Hello World!");
    //fclose(fw);


    printf("\n");
    system("pause");
    return 0;

}