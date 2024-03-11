#include<stdio.h>
#include<math.h>
//ham nhap va xuat
void xuat(int arr[],int n);
void nhap(int arr[],int n)
{
    printf("nhap gia tri cho cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) scanf("%d",&arr[i]);
}
void xuat(int arr[],int n)
{
    printf("day ban vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//cau b
int cau_b(int arr[],int n)
{
    int dem=1;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]<arr[i+1]) dem++;
    }
    if(dem==n) return 1;
    else return 0;
}
//cau c
void cau_c(int arr[],int n,float *ketqua)
{
    for (int i = 0; i < n-1; i++)
    {
        *ketqua+=1.0*arr[i]*arr[i+1];
    }
    *ketqua/=(n+n*n)/2;
}

int main()
{
    //cau a
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    int arr[n];
    re_arr: nhap(arr,n);
    //a,kiem tra sao cho ko co so nao  bang nhau trong mang
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j]) goto re_arr;
        }
    }
    //xuat mang ra
    xuat(arr,n);
    //cau b, kiem tra xem co phai la xap xep tang dan ko
    if(cau_b(arr,n)) printf("day la day tang dan.\n");
    else printf("day ko phai day tang dan dan.\n");
    //cau c, tinh
    float result=0;
    cau_c(arr,n,&result);
    printf("gia tri cua s = %f",result);
    return 0;
}
