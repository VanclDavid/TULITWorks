#define _CRT_SECURE_NO_WARNINGS

#include <process.h>
#include "stdio.h"

int makeTestFiles() {
    
    
    // TXT file
    FILE* fCurrent = fopen("fileTXT.txt", "wt");
    char Testmessage[] = "Hello world to txt file #1!";
    fprintf(fCurrent, "%s", Testmessage);
    fclose(fCurrent);

    // BIN file
    fCurrent = fopen("fileBIN.bin", "wb");
    Testmessage[27] = "Hello world to bin file #2!";
    fwrite(&Testmessage, sizeof(Testmessage), 1, fCurrent);
    fclose(fCurrent);
    return 0;
}

int main() {
    makeTestFiles();

    //printf("Hello World!");

    //FILE* fOriginal;
    //fOriginal = fopen("SOUBOR.TXT", "rt");
    //int a;
    //while (fscanf(fOriginal, "%d", &a) != EOF) {
    //    printf("%d \n", a);

    //    system("pause");
    //}
    //      
    //fclose(fOriginal);

    //FILE* fw;
    //fw = fopen("SOUBOR.TXT", "a");
    //fprintf(fw, "Hello World!");
    //fclose(fw);


    printf("\n");
    system("pause");
    return 0;

}