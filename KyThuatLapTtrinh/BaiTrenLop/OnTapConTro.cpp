#include<stdio.h>
#include<math.h>
#include<string.h>
//nhap mang day do co n phan tu
//tinh tong cac phan tu lon hon x
//tinh tbc cac phan tu chan

void input(int *a)
{
    scanf("%d", a);
}

void In_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        input(arr+i);
    }
    
}

void Output(int x)
{
    printf("%d ", x);
}

void Out_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        Output(*(arr+i));
    }
    
}

int main()
{
    //nhap n
    int n;
    printf("nhap n: ");
    input(&n);
    while (n < 1)
    {
        printf("vui long nhap lai\n");
        input(&n);
    }
    
    //nhap mang
    printf("nhap cac phan tu cho mang: ");
    int arr[n];
    In_Array(arr, n);
    Out_Array(arr, n);

    return 0;
}
