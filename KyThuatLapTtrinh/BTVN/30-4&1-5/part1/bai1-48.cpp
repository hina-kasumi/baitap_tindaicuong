//Viết hàm sắp xếp mảng theo thứ tự tăng dần và giảm dần.
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

int patament(int *a, int low, int high, int TangGiam){
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high; j++){
        if (a[j] < pivot && TangGiam == 1){
            i++;
            swap(a + i, a + j);
        }
        else if (a[j] > pivot && TangGiam == 2){
            i++;
            swap(a + i, a + j);
        }
    }
    swap(a + i + 1, a + high);
    return i + 1;
}
void QuickSort(int *a, int low, int high, int TangGiam){
    if (low < high){
        int pi = patament(a, low, high, TangGiam);
        QuickSort(a, low, pi - 1, TangGiam);
        QuickSort(a, pi + 1, high, TangGiam);
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

    
    printf("mang sau khi xep tang dan: ");
    QuickSort(a, 0, n - 1, 1);
    Output(a, n);
    endl;
    
    printf("mang sau khi xep giam dan: ");
    QuickSort(a, 0 , n - 1, 2);
    Output(a, n);

    free(a);
    return 0;
}
