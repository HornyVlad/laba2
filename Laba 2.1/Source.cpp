#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end, start1, end1;
	int i = 0, j = 0, r;
	int **a, **b, **c, proizv;
	int max, max2;
	printf("Укажите размер матрицы: ");
	scanf_s("%d", &max );
	a = (int**)malloc(max * sizeof(int));
	b = (int**)malloc(max * sizeof(int));
	c = (int**)malloc(max * sizeof(int));
	for (i = 0; i < max; i++)
	{
		a[i] = (int*)malloc(max * sizeof(int));
	}
	for (i = 0; i < max; i++)
	{
		b[i] = (int*)malloc(max * sizeof(int));
	}
	for (i = 0; i < max; i++)
	{
		c[i] = (int*)malloc(max * sizeof(int));
	}
	i = 0;
	start = clock();
	srand(time(NULL));
	while (i < max)
	{
		while (j < max)
		{
			a[i][j] = rand() % 10 + 1;
			j++;
		}
		j = 0;
		i++;
	}
	srand(time(NULL));
	i = 0; j = 0;
	while (i < max)
	{
		while (j < max)
		{
			b[i][j] = rand() % 10 + 1;
			j++;
		}
		j = 0;
		i++;
	}
	start1 = clock();
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			proizv = 0;
			for (r = 0; r < max; r++)
			{
				proizv = proizv + a[i][r] * b[r][j];
				c[i][j] = proizv;
			}
		}
	}
	end1 = clock();
	end = clock();
	printf("Время выполнения работы: %.4f\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("Время перемножения: %.4f\n", ((double)end1 - start1) / ((double)CLOCKS_PER_SEC));
	/*for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}*/
	return(0);
}