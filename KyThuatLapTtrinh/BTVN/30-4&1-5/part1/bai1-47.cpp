/*Viết chương trình phát sinh ngẫu nhiên mảng một chiều số nguyên a gồm 
30.000 phần tử có giá trị từ 0 đến 20.000.
Hãy thống kê tần suất xuất hiện của các phần tử trong a. */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
void Input(int *a, int n){
    if (n == 0)
        return;
    Input(a, n - 1);
    scanf("%d", a + n - 1);
}

void Output(int *a, int n){
    if (n == 0)
        return;
    Output(a, n - 1);
    printf("%d ", (*a + n - 1));
}

int *SoLan(int *a, int n){
    int *LanXuatHien = (int*)malloc(20000 * sizeof(int));
    memset(LanXuatHien, 0, 20000);
    for (int i = 0; i < n; i++)
        LanXuatHien[a[i]]++;
    return LanXuatHien;
}
int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    printf("nhap gia tri cho cac phan tu cua mang: ");
    Input(a, n);

    printf("mang ban vua nhap la: ");
    Output(a, n);

    int *LanXuatHien = SoLan(a, n);
    for (int i = 0; i < 20000; i++)
        if (LanXuatHien[i])
            printf("\n%d: %d lan", i, LanXuatHien[i]);
    
    



    free(a);
    free(LanXuatHien);
    return 0;
}
