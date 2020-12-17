//seètení 2 matic
void countSumMatrix(float** matrix1, float** matrix2, float** matrixout, int* row, int* col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			matrixout[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}
//vynásobení 2 matic
void countMultipleMatrix(float** matrix1, float** matrix2, float** matrixout, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size; j++)
		{
			float sum = 0;
			for (int k = 0; k < *size; k++)
			{
				sum += (matrix1[i][k] * matrix2[k][j]);
			}
			
			matrixout[i][j] = sum;
		}
	}
}