#include <stdio.h>
#include <stdlib.h>

int main() {

	float* p_f;
	float f = 3.14;
	float f1 = 6.36;

	if (p_f == NULL) {
		p_f = &f;
	}

	p_f = &f;

	printf("%p , %p , %p , %f , %f \n", &p_f, p_f, &f, *p_f, f);


	int size = 256;
	char *ascii;
	ascii = (char *)malloc( sizeof(char) * size );
	if (ascii = NULL) {
		return 10;
	}


	ascii[1] = 'a';

	int *p_int;
	p_int = (int*)malloc( sizeof(int) * 1 );

	free((char *)ascii);
	ascii = NULL;

	getchar();
	return 1;
}