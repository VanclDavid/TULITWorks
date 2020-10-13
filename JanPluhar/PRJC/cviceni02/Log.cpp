#define _CRT_SECURE_NO_WARNINGS  
#include "Log.h"
#include <string.h>
void log(char description[],const char file_name[]) {
	FILE* fw = fopen(file_name, "w");
	fwrite(&*description, strlen(description), 1, fw);
	fclose(fw);
}