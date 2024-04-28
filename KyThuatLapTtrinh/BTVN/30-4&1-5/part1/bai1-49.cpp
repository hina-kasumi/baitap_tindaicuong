//Nhập vào giá trị X. Viết hàm xoá tất cả các phần tử có giá trị X.
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
void Input(int **a, int n){
    *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", *a + i);
}

void Output(int *a, int n){
    if(n == 0)
        return;
    Output(a, n -1);
    printf("%d ", a[n - 1]);
}
void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}
void erease (int *a, int *n, int x){
    for (int i = 0; i < *n; i++)
    {
        if(a[i] == x){
            for (int j = i; j < *n - 1; j++)
                a[j] = a[j + 1];
            a[*n - 1] = 0;
            (*n)--;
            i--;
        }
    }
}

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int *a;
    printf("nhap gia tri cho cac phan tu trong mang: ");
    Input(&a, n);

    printf("mang ban vua nhap la: ");
    Output(a, n);
    endl;

    int x;
    printf("nhap so ban muon xoa: ");
    scanf("%d", &x);

    erease(a, &n, x);
    printf("mang sau khi xoa %d la: ",x);
    Output(a, n);
    return 0;
}
