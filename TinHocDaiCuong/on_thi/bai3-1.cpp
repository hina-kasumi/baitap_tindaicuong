#include<stdio.h>
#include<math.h>
#define _n_ printf("\n");
void xuat(float arr[],int i)
{
    printf("%f ",arr[i]);
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float arr[n];
    printf("nhap gia tri cho cac phan tu trong mang: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&arr[i]);
    }
    //in ra
    printf("cac gia tri ban vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        xuat(arr,i);
    }
    _n_;
    //a,
    float tong_duong=0;
    printf("max = ");
    float max=arr[0];
    for (int i = 0; i < n; i++)
    {
        if(max<arr[i]/(i+1)) max=arr[i]/(i+1);
        if (arr[i]>0)
        {
            tong_duong+=arr[i];
        }
    }
    printf("%f",max);
    _n_;
    //b,
    printf("tong cua cac so duong trong day = %f\n",tong_duong);
    //c,
    float x;
    int dem=0;
    printf("nhap gia tri cua x: ");
    scanf("%f",&x);
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i])>x)
        {
            dem++;
        }
    }
    if (dem>0)
    {
        printf("so phan tu co gia tri tuyet doi lon hon x la: %d\nva nhung so do la: ",dem);
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>x) xuat(arr,i);
        }
    }
    else printf("khong co phan tu nao thoa man");
    return 0;
}
