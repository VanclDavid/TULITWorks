// ignorov�n� warningu
#define _CRT_SECURE_NO_WARNINGS
//Jsou bin�rn� a textov� soubory. Textov� jsou cel� string a bin�rn� jsou r�zn� datov� typy
//Importujeme hlavi�kov� soubory
#include <stdio.h> 
#include <locale.h>
#include <string>
void writeBinFile();
void readBinFile();
void writeFile();
int getFileSize(FILE*file);
int fileCopyWorker(char fileName[]);
int fileCopyBinWorker(char fileName[]);
int main()
{
    setlocale(LC_ALL, "cs_CZ");
    char fileName[]="textovySoubor.txt";
    char fileName2[] = "binarni.soubor";
    fileCopyWorker(fileName);
    fileCopyBinWorker(fileName2);
    return 0;
}

int getFileSize(FILE * file)
{
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    rewind(file);
    return size;
}

int fileCopyWorker(char fileName[])
{
    FILE* fr = fopen(fileName,"r");
    if (!fr)
    {
        return 1;
    }
    int size = getFileSize(fr);
    FILE* wrA = fopen("kopie-1.txt", "w");
    if (!wrA)
    {
        return 1;
    }
    FILE* wrB = fopen("kopie-2.txt", "w");
    if (!wrB)
    {
        return 1;
    }
    char actualChar;
    int posision = 0;
    while ((actualChar=fgetc(fr)) != EOF)
    {
        printf("%c", actualChar);
        posision >= (size / 2) ? fputc(actualChar, wrB) : fputc(actualChar, wrA);
        posision++;
    }
    fclose(wrA);
    fclose(wrB);
    fclose(fr);
    return 0;
}
int fileCopyBinWorker(char fileName[])
{
    FILE* fr = fopen(fileName, "rb");
    if (!fr)
    {
        return 1;
    }
    int size = getFileSize(fr);
    FILE* wrA = fopen("kopie-1.dat", "wb");
    if (!wrA)
    {
        return 1;
    }
    FILE* wrB = fopen("kopie-2.dat", "wb");
    if (!wrB)
    {
        return 1;
    }
    char actualChar;
    int posision = 0;
    while ((actualChar = fgetc(fr)) != EOF)
    {
        posision >= (size / 2) ? fputc(actualChar, wrB) : fputc(actualChar, wrA);
        posision++;
    }
    fclose(wrA);
    fclose(wrB);
    fclose(fr);
    return 0;
}


//c nem� v�jimky a proto vr�t�me p��padn� nap��klad 1

//P�e�te pouze textov� soubor
//V neposledn� �ad� bychom si m�li sd�lit, �e pr�ce se soubory pou��v� tzv.buffer.Zapisovat toti� znak po znaku by disk velmi vyt�ilo, proto se �ek�, a� se napln� ur�it� vyrovn�vac� pam�, kter� se potom najednou na disk zap�e a t�m se u�et�� p��stupy k disku.

