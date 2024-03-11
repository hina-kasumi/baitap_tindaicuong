#include<stdio.h>
#include<stdlib.h>

void Input(int *x)
{
    scanf("%d", x);
}

void Input_Array(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        Input(*arr+i);
    }
}

void Output(int a)
{
    printf("%d ",a);
}

void Output_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        Output(*(arr+i));
    }
    
}

int main()
{
    int n;
    printf("nhap n: ");
    Input(&n);

    int *a;
    a = (int*) malloc((n) * sizeof(int));

    int *b;
    b = (int*) malloc(n * sizeof(int));

    printf("nhap phan tu cho day a: ");
    Input_Array(&a, n);

    printf("nhap phan tu cho day b: ");
    Input_Array(&b, n);

    printf("mang a: ");
    Output_Array(a, n);

    printf("\nmang b: ");
    Output_Array(b, n);
    return 0;
}
