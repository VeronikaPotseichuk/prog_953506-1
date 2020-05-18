//#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdio>
#include <stdio.h>

void Sort(int** A, int N, int M)
{
	int H = 0;
	for (int k(1); k <= N; k++)
		for (int i = 0; i < N - k; i++)
			for (int j = 0; j < M - k; j++)
			{
				if (A[i][j] > A[i + 1][j + 1])
				{
					H = A[i][j];
					A[i][j] = A[i + 1][j + 1];
					A[i + 1][j + 1] = H;
				}
			}
}

int main()
{
	int n, m;
	double sum = 0;
	printf("Enter the value of the veriable n: ");
	scanf_s("%d", &n);
	printf("Enter the value of the veriable m: ");
	scanf_s("%d", &m);
	printf("______________________________________________________\nSource matrix");
	int** arr = new int* [n];
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 10;
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	sum = sum / (n * m);

	printf("\n\nModified matrix\n");

	//***************************************
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i = j) {
				Sort(arr, n, m);
			}
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

