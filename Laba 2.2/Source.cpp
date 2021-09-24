#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
			{
				items[j + gap] = items[j];
			}
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right)
{
int i, j;
int x, y;

i = left; j = right;
x = items[(left + right) / 2];
do {
	while ((items[i] < x) && (i < right)) i++;
	while ((x < items[j]) && (j > left)) j--;
	if (i <= j) {
		y = items[i];
		items[i] = items[j];
		items[j] = y;
		i++; j--;
	}
} while (i <= j);
if (left < j) qs(items, left, j);
if (i < right) qs(items, i, right);
}


int comp(const int* i, const int* j)
{
	return *i - *j;
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end, start1, end1;
	int i = 0, j = 0, max, sort, type;
	int* a;
	printf("Укажите размер массива: ");
	scanf_s("%d", &max);
	a = (int*)malloc(max * sizeof(int));
	printf("\nКак заполнить массив?\nСлучайная генерация - 1\nПо возрастанию - 2\nПо убыванию - 3\nПоловина на половину - 4\n");
	scanf_s("%d", &type);
	switch (type)
	{
	case 1: while (i < max)
		{
			a[i] = rand() % 100 + 1;
			i++;
		}
	case 2: for (i = 0; i < max; i++)
		{
			a[i] = i;
		}
	case 3: for (i = max; i > 0; i--)
		{
			a[i] = i;
		}
	case 4: for (i = 0; i < max / 2; i++)
		{
			a[i] = i;
		}
		  for (i = max / 2; i < max; i++)
		{
		  a[i] = i;
		}
	}
	printf("\nВыберите тип сортировки\nСортировка Шелла - 1\nБыстрая сортировка - 2\nqsort - 3\n");
	scanf_s("%d", &sort);
	start = clock();
	switch (sort)
	{
	case 1: shell(a, max);
	case 2: qs(a, 0, max);
	case 3: qsort(a, max, sizeof(int), (int(*) (const void *, const void *)) comp);
	}
	end = clock();
	/*printf("Массив: ");
	for (i = 1; i <= max; i++)
	{
		printf("%d ", a[i]);
	}*/
	
	printf("\nВремя выполнения работы: %.4f\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	return(0);
}