/*Viết chương trình nhập vào mảng một chiều các số nguyên và xuất ra màn 
hình các phần tử có từ 3 ước số trở lên. 
- Hàm nhập, xuất, Đếm số ước của số n*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

void Input(int **arr, int n){
    *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", *arr + i);
}
void Output(int *arr, int n){
    if(n == 0)
        return;
    Output(arr, n - 1);
    printf("%d ", arr[n - 1]);
}

int SoUoc(int n){
    int res = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            res += 2;
    }
    if (n == (int)sqrt(n) * (int)sqrt(n))
        return res - 1;
    return res;
}

void Uoc3(int *arr, int n){
    if (n == 0)
        return;
    n--;
    Uoc3(arr, n);
    if (SoUoc(arr[n]) >= 3)
        printf("%d ", arr[n]);
}

int main()
{
    int n;
    printf("Nhap n: ");
	scanf("%d", &n);

    int *arr;
    printf("nhap gia tri cho cac phan tu: ");
    Input(&arr, n);

    printf("mang ban vua nhap: ");
    Output(arr, n);
    endl;

    printf("so co so uoc tu 3 tro len: ");
    Uoc3(arr, n);
    
    free(arr);
    return 0;
}
