#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// nhap mang day do co n phan tu
// tinh tong cac phan tu lon hon x
// tinh tbc cac phan tu chan

// tim gia tri lon nhat cua day va 1 vi tri chua ma
// cho biet cac cap so lien tiep thoa man tinh chat tich chia het cho tong

void input(int *a)
{
    scanf("%d", a);
}

void In_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        input(arr + i);
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
        Output(*(arr + i));
    }
}

int Sum(int *arr, int n, int x, bool *check)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) > x)
        {
            sum += *(arr + i);
            *check = 1;
        }
    }
    return sum;
}

float TBC(int *arr, int n, bool *check)
{
    float tbc = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            tbc += (float)*(arr + i);
            count++;
            *check = 1;
        }
    }
    return tbc / count;
}

int Max(int *arr, int n, int *dir)
{
    int max = *(arr);
    for (int i = 0; i < n; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
            *dir = i;
        }
    }
    return max;
}

int *find(int *arr, int n, int x, int *k)
{
    int *pt;
    pt = (int*) malloc((n+1) * sizeof(int));
    *k = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr+i) > x)
        {
            *(pt+*k) = *(arr+i);
            *k++;
        }
        
    }
    
}


bool TichChiaTong(int *arr, int n)
{
    bool check = 0;
    for (int i = 1; i < n; i++)
    {
        if ((*(arr+i))*(*(arr+i-1)) % ((*(arr+i))+(*(arr+i-1))) == 0)
        {
            Output(*(arr+i));
            Output(*(arr+i-1));
            printf("\n");
            check = 1;
        }
    }
    return check;
}

int main()
{
    // nhap n
    int n;
    printf("nhap n: ");
    input(&n);
    while (n < 1)
    {
        printf("vui long nhap lai\n");
        input(&n);
    }

    // nhap mang
    printf("nhap cac phan tu cho mang: ");

    // cap phat dong
    int *arr;
    arr = (int *)malloc((n + 1) * sizeof(int));
    In_Array(arr, n);
    Out_Array(arr, n);

    // tinh tong cac phan tu lon hon x
    // nhap x
    int x;
    printf("\nnhap x: ");
    input(&x);

    bool check = 0;
    int sum = Sum(arr, n, x, &check);

    if (check)
        printf("tong cac so lon hon x: %d\n\n", sum);
    else
        printf("khong co phan tu nao lon x.\n\n");

    // tinh tbc cac so chan
    check = 0;
    float tbc = TBC(arr, n, &check);
    if (check)
        printf("tbc cac so chan: %.2f\n\n", tbc);
    else
        printf("mang ko co so chan\n\n");

    // tim max va cho biet vi tri cua no
    int dir = 0;
    int max = Max(arr, n, &dir);
    printf("max = %d (%d)\n\n", max, dir);

    // cho biet cac cap so lien tiep
    printf("cac cap so thoa man:\n");
    bool a = TichChiaTong(arr, n);
    if(!a) printf("khong co cap nao thoa man\n\n");


    // giai phong bo nho bi thua
    free(arr);

    return 0;
}
