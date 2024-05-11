#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")


void InOut(int *arr, int n, FILE *f){
	if(n == 0)
		return;
	InOut(arr, n - 1, f);
	fscanf(f, "%d", arr + n - 1);
	printf("%d ", arr[n - 1]);
}

void InOut(int **matrix, int m, int n, FILE *f){
	if(m == 0)
		return;
	InOut(matrix, m - 1, n, f);
	InOut(matrix[m - 1], n, f);
	endl;
}

int Max(int *arr, int n){
	if(n == 0)
		return arr[n];
	n--;
	int max = Max(arr, n);
	return (max < arr[n])? arr[n]:max;
}

int InMaxLe(int **matrix, int m, int n){
	int max = matrix[0][0];
	for(int i = 1; i< m; i+=2){
		int tmp = Max(matrix[i], n);
		max = (max < tmp)? tmp:max;
	}
	return max;
}

int main()
{
	FILE *f = fopen("matrix.txt", "r");
	int m, n; fscanf(f, "%d%d", &m, &n);
	int **matrix = (int**) malloc(m * sizeof(int*));
	for(int i = 0; i< n; i++)
		matrix[i] = (int*) malloc(n * sizeof(int));
	
	InOut(matrix, m, n, f);
	printf("max cac hang le la: %d\n", InMaxLe(matrix, m, n));
	
	
	
	fclose(f);
	for(int i = 0; i< n; i++)
		free(matrix[i]);
	free(matrix);
}
