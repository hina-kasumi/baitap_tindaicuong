#include<stdio.h>
#include<math.h>
void show(float arr[],int n);
//nhap
void nhap(float arr[], int n)
{
    printf("nhap gia tri cho cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) scanf("%f",&arr[i]);
    show(arr,n);
}
//xuat cau a.
void show(float arr[], int n)
{
    printf("day ban vua nhap la: ");
    for(int i = 0; i<n; i++) printf("%f ",arr[i]);
} 
//ham cho cau b
float tinh_b (float arr[],int n)
{
    float max=arr[0]/n;
    float ketqua;
    for (int i = 0; i < n; i++)
    {
        ketqua=arr[i]/(n-i);
        if (max<ketqua) max=ketqua;
    }
    return max;
}
//cau c
float cau_c(float arr[],int n, int i, float *result)
{
    if(i<n-1) 
    {
        *result+= arr[i]+arr[i+1];
        return cau_c(arr, n, i+1, result);
    }
    return *result;
}
int main()
{
    //a, in ra 
    int n;
    back: printf("nhap so nguyen duong n: ");
    scanf("%d",&n);
    if (n<1) goto back;
    float arr[n];
    //nhap va in ra mang
    nhap(arr,n);
    //cau b
    printf("\n%f",tinh_b(arr,n));
    //cau c
    float dap_an_c=0;
    int i=0;
    cau_c(arr,n,i, &dap_an_c);
    printf("\n%f",dap_an_c);
    return 0;
}
