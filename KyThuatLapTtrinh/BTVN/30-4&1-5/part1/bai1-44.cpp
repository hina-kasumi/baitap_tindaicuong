//Viết hàm tìm vị trí phần tử âm lớn nhất trong mảng.
#include<bits/stdc++.h>
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

int max(int *arr, int n){
    int max = INT_MIN;
    int dir = -1;
    for (int i = 0; i < n; i++)
    {
        if(max < arr[i] && arr[i] < 0){
            max = arr[i];
            dir = i;
        }
    }
    return dir;
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

    int locationMax = max(arr, n);
    if(locationMax != -1)
        printf("\nvi tri so am lon nhat: %d", locationMax);
    else
        printf("\nmang ko co so am.");
    free(arr);
    return 0;
}
