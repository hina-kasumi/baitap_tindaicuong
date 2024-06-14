#include<stdio.h>
#include<stdlib.h>
#define endl printf("\n")
void Input(int ***matrix, int n, FILE *f)
{
    *matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(*matrix + i) = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", *(*matrix + i) + j);
        }
    }
}

void Output(int **matrix, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        endl;
    }
}

int **multiply(int **a, int **b, int n){
    int **c = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        *(c + i) = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

int main()
{
    FILE *f = fopen("matrix.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    int **a, **b;
    Input(&a, n, f);
    Input(&b, n, f);
    printf("matrix a:\n");
    Output(a, n);
    printf("matrix b:\n");
    Output(b, n);
    int **c = multiply(a, b, n);
    printf("ma tran sau khi nhan la:\n");
    Output(c, n);
    return 0;
}