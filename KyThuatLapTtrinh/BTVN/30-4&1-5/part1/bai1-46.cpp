/*Viết chương trình nhập vào một dãy số a gồm n số thực (n <= 100), nhập vào 
dãy số b gồm m số thực (m <= 100).
- In ra những phần tử chỉ xuất hiện trong dãy a mà không xuất hiện trong 
dãy b. 
- In ra những phần tử xuất hiện ở cả hai dãy.*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
void swap(float *a, float *b){
    float x = *a;
    *a = *b;
    *b = x;
}

int partition(float *arr, int low, int high){
    float pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return i + 1;    
}

void QuickSort(float *arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int BinarySearch(float *arr, int n, float taget){
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == taget)
            return mid;
        else if (arr[mid] < taget)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void Input(float **arr, int *n){
    scanf("%d", n);
    *arr = (float*) malloc(*n * sizeof(float));
    for (int i = 0; i < *n; i++)
        scanf("%f", *arr + i);
    QuickSort(*arr, 0, *n - 1);
}

void Output(float *arr, int n){
    if (n == 0)
        return;
    Output(arr, n - 1);
    printf("%.2f ", arr[n - 1]);
}

float *KoXuatHienTrongB (float *a, int n, float *b, int m, int *cnt){
    float *list = (float*) malloc(n * sizeof(float));
    *cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (BinarySearch(b, m, a[i]) == -1){
            list[*cnt] = a[i];
            (*cnt)++;
        }
    }
    return list;
}

float *xuatHienCa2(float *a, int n, float *b, int m, int *cnt){
    *cnt = 0;
    float *list = (float*) malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        if (BinarySearch(b, m, a[i]) != -1){
            list[*cnt] = a[i];
            (*cnt)++;
        }
    }
    return list;
}

int main()
{
    int n, m;
    float *a, *b;
    printf("nhap thong so cho mang a: ");
    Input(&a, &n);
    printf("nhap thong so cho mang b: ");
    Input(&b, &m);

    printf("mang a: ");
    Output(a, n);
    endl;

    printf("mang b: ");
    Output(b, m);
    endl;

    int cnt;
    float *list = KoXuatHienTrongB(a, n, b, m, &cnt);
    if (cnt){
        printf("danh sach so khong thuoc b trong a: ");
        Output(list, cnt);
        endl;
    } 
    else 
        printf("tat ca cac so cua a deu thuoc b.\n");

    list = xuatHienCa2(a, n, b, m, &cnt);
    if (cnt){
        printf("danh sach so thuoc ca a va b: ");
        Output(list, cnt);
        endl;
    } 
    else 
        printf("a va b ko co phan tu nao giong nhau.\n");

    
    free(list);
    free(a);
    free(b);
    return 0;
}
