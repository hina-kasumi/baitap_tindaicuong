//Viết hàm tìm vị trí phần tử có giá trị x xuất hiện cuối cùng trong mảng.
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
    if (n == 0)
        return;
    Output(arr, n - 1);
    printf("%d ", arr[n - 1]);
}

void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}

int patermant(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot){
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return i + 1;
}

void QuickSort(int *arr, int low, int high){
    if (low < high){
        int pi = patermant(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int BinarySearch(int *arr, int n, int taget){
    int left = 0;
    int right = n - 1;
    int res = -1;
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (arr[mid] == taget){
            res = mid;
            left = mid + 1;
        }
        else if (arr[mid] > taget)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return res;
}


int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int *arr;
    printf("nhap gia tri cho cac phan tu torng mang: ");
    Input(&arr, n);
    QuickSort(arr, 0, n - 1);
    printf("mang ban vua nhap la: ");
    Output(arr, n);
    endl;

    int x;
    printf("nhap so ban muon tim: ");
    scanf("%d", &x);
    printf("vi tri cuoi cung cua x la: %d", BinarySearch(arr, n ,x));

    
    free(arr);
    return 0;
}
