//Viết hàm chèn phần tử có giá trị X vào phía sau phần tử có giá trị lớn nhất trong mảng.
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
void Input(int **a, int n){
    *a = (int*) malloc((n + 1) * sizeof(int));
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

int FindMax(int *a, int n){
    int max = *a;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < *(a + i))
        {
            max = *(a + i);
            res = i;
        }
    }
    return res;
}

void Insert(int *a, int *n, int x){
    int location = FindMax(a, *n);
    a[*n] = x;
    for(int i = *n;i > location + 1; i--){
    	swap(a + i, a + i - 1);
	}
	(*n)++;
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
    printf("nhap x: ");
    scanf("%d", &x);
    printf("mang sau khi duoc chen x la: ");
    Insert(a, &n, x);
    Output(a, n);
    return 0;
}
