#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>

int createBinFile() {
	FILE* file = fopen("input.bin", "wb");
	char input[] = "mature edition betray acceptable obscure abridge pain demonstrator organ quarter";
	fwrite(&input, sizeof(input), 1, file);
	fclose(file);
	return 0;
}

int getFileSize(FILE * file) {
	fseek(file, 0L, SEEK_END);
	int size = ftell(file);
	rewind(file);
	return size;
}

char* concat_fields(const char* field1, const char* field2){
	char* result = new char[strlen(field1) + strlen(field1) + 1];
	strcpy(result, field1);
	strcat(result, field2);
	return result;
}

int main() {
	int response = createBinFile();

	char offeset[] = ".txt";

	char readMode[] = "r";
	char writeMode[] = "w";

	char input[60];
	scanf("%s", &input);
	if (strcmp(input, "bin") == 0) {
		strcpy(offeset, ".bin");
	}

	FILE* fileReader = fopen(concat_fields("input",offeset), readMode);
	if(!fileReader) return 500;
	int size = getFileSize(fileReader);

	FILE* copy1 = fopen(concat_fields("kopie-1",offeset), writeMode);
	if (!copy1) return 500;
	FILE* copy2 = fopen(concat_fields("kopie-2",offeset), writeMode);
	if (!copy2) return 500;
	char c;
	int index = 0;
	while ((c = fgetc(fileReader)) != EOF){
		index >= (size / 2) ? fputc(c, copy2) : fputc(c, copy1);
		index++;
	}
	int copy1Size = getFileSize(copy1);
	fclose(copy1);
	int copy2Size = getFileSize(copy2);
	fclose(copy2);
	fclose(fileReader);

	printf("input[%d] = copy1[%d] + copy2[%d] (%d = %d) \n", size , copy1Size, copy2Size,size,(copy1Size + copy2Size));

	system("pause");

	return 200;
}