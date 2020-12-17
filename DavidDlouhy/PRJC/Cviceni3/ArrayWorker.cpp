#include <malloc.h>
#include <stdio.h>
float* createArray(int sizeOfArray)
{
	return (float*)malloc(sizeOfArray * sizeof(float));
}

void insertValueArray(float * array, int sizeOfArray)
{
	for(int i =0; i< sizeOfArray; i++)
	{
		printf("Cislo [%d/%d]?\n", (i + 1),sizeOfArray);
		float number = 0;
		float* p_number = &number;
		scanf_s("%f", p_number);
		array[i] = number;
	}
}

void printArray(float* array, int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%f\n", array[i]);
	}
}

void switchArrayValues(float* array, int sizeOfArray)
{
	for (int i = 0; i < (sizeOfArray / 2); i++)
	{
		int opposite;
		float actualValue = array[i];
		if ((sizeOfArray % 2) == 0)
		{
			opposite = (sizeOfArray / 2) + i;
		}
		else
		{
			opposite= ((sizeOfArray / 2) + 1) + i;
		}
		array[i] = array[opposite];
		array[opposite] = actualValue;
	}
}

void clearArray(float* array)
{
	*array = NULL;
	array = NULL;
	free(array);
}

int testeArraySwitch()
{
	//Hodnoty testu (oèekávané)
	float input[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 0.0};
	float output[10] = { 6.6, 7.7, 8.8, 9.9, 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
	//Hodoty testu 
	float real_input[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 0.0 };
	//float real_output[10];
	float* p_real_output = (float*)malloc(10 * sizeof(float));
	for (int i = 0; i < 10; i++)
	{
		p_real_output[i] = real_input[i];
	}
	switchArrayValues(p_real_output, 10);
	for (int i=0; i< 10; i++)
	{
		if (p_real_output[i] != output[i])
		{
			return 1;
		}
	}
	clearArray(p_real_output);
	return 0;
}