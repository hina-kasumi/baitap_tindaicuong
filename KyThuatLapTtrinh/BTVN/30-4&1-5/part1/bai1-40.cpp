/* Viết chương trình phát sinh ngẫu nhiên mảng một chiều các số nguyên sao 
cho mảng có thứ tự tăng dần (Không sử dụng hàm sắp xếp). */
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

    
    free(arr);
    return 0;
}
