/*Viết chương trình nhập vào mảng một chiều các số nguyên và xuất ra màn 
hình các phần tử là số nguyên tố. 
- Hàm nhập 
- Hàm xuất 
- Hàm KT số nguyên tố*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
const int LIMIT = 10000;
bool isPrime[LIMIT] = {true, true};

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

void Sang(){
    for (int i = 0; i <= 100; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j < LIMIT; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void kiemTra(int *arr, int n){
    Sang();
    for (int i = 0; i < n; i++)
    {
        printf("%d: ", arr[i]);
        if (!isPrime[arr[i]])
            printf("la so nguyen to.\n");
        else
            printf("khong phai so nguyen to.\n");
    }
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
    
    kiemTra(arr, n);

    free(arr);
    return 0;
}
