// ignorování warningu
#define _CRT_SECURE_NO_WARNINGS
//Jsou binární a textové soubory. Textové jsou celı string a binární jsou rùzné datové typy
//Importujeme hlavièkové soubory
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


//c nemá vıjimky a proto vrátíme pøípadnì napøíklad 1

//Pøeète pouze textovı soubor
//V neposlední øadì bychom si mìli sdìlit, e práce se soubory pouívá tzv.buffer.Zapisovat toti znak po znaku by disk velmi vytíilo, proto se èeká, a se naplní urèitá vyrovnávací pamì, která se potom najednou na disk zapíše a tím se ušetøí pøístupy k disku.

