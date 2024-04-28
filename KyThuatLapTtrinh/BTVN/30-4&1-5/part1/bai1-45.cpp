//Viết hàm tính giá trị trung bình các phần tử là nguyên tố trong mảng.
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
const int LIMIT = 1000;
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

void Snag(){
    for (int i = 2; i * i <= LIMIT; i++){
        if (!isPrime[i]){
            for (int j = i * i; j < LIMIT; j+=i){
                isPrime[j] = true;
            }
        }
    }
}

float TBCPrime(int *arr, int n){
    float res = 0;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > 0 && !isPrime[arr[i]]){
            res += 1.0*arr[i];
            count++;
        }
    }
    if (count == 0)
        return -1;
    return res / count;
}

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int *arr;
    printf("nhap gia tri cho cac phan tu trong mang: ");
    Input(&arr, n);
    printf("mang ban vua nhap: ");
    Output(arr, n);

    Snag();
    
    float tbcPrime = TBCPrime(arr, n);
    if (tbcPrime == -1)
        printf("\nkhong ton tai so nguyen to.");
    else
        printf("\ntbc cac so nguyen to: %f", isPrime);
    
    
    free(arr);
    return 0;
}
