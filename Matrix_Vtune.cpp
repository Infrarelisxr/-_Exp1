#include <iostream>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
int N = 200;
void init(int **m,int* vec,int n)
{
	for (int i = 0; i < N; i++)
	{
		vec[i] = i;
		for (int j = 0; j < N; j++)
		{
			m[i][j] = i + j;
		}
	}
}
void Matrix_com(int** m, int* vec, int n)
{
	int* sum = new int[n];
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < n; j++)
		{
			sum[i] += m[j][i] * vec[j];
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << sum[i] << endl;
	//}
	return;
}
void Matrix_opt(int** m, int* vec, int n)
{
	int* sum = new int[n];
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum[i] += m[j][i] * vec[j];
		}
	}
	return;
}
void Matrix_unroll(int** m, int* vec, int n)
{
	int* sum = new int[n];
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i += 10)  // 将内层循环展开为10次迭代
		{
			sum[i] += m[j][i] * vec[j];
			sum[i + 1] += m[j][i + 1] * vec[j];
			sum[i + 2] += m[j][i + 2] * vec[j];
			sum[i + 3] += m[j][i + 3] * vec[j];
			sum[i + 4] += m[j][i + 4] * vec[j];
			sum[i + 5] += m[j][i + 5] * vec[j];
			sum[i + 6] += m[j][i + 6] * vec[j];
			sum[i + 7] += m[j][i + 7] * vec[j];
			sum[i + 8] += m[j][i + 8] * vec[j];
			sum[i + 9] += m[j][i + 9] * vec[j];

		}
	}
	return;
}

//int* Sum = new int[N];
//int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0;
//void Matrix_unroll(int** m, int* vec, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		Sum[i] = 0;
//	}
//	for (int j = 0; j < n; j+=4)
//	{
//		temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0;
//		for (int i = 0; i < n; i++)
//		{
//			temp0 += m[j + 0][i] * vec[j + 0];
//			temp1 += m[j + 1][i] * vec[j + 1]; 
//			temp2 += m[j + 2][i] * vec[j + 2];
//			temp1 += m[j + 3][i] * vec[j + 3];
//		}
//		Sum[j + 0] = temp0;
//		Sum[j + 1] = temp1;
//		Sum[j + 2] = temp2;
//		Sum[j + 3] = temp3;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << Sum[i] << endl;
//	}
//	return;
//}
int main()
{
		int** m = new int* [N];
		for (int i = 0; i < N; i++)
		{
			m[i] = new int[N];
		}
		int* vec = new int[N];
		init(m, vec, N);
		for (int i = 0; i < 100; i++)
		{
			Matrix_opt(m, vec, N);
		}
		



	
	return 0;
}