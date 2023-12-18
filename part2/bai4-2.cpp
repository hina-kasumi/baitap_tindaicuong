#include<stdio.h>
#include<math.h>

//ham nhap va xuat
void xuat(int arr[],int n);
void nhap(int arr[],int n)
{
    printf("nhap gia tri cho cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) scanf("%d",&arr[i]);
    xuat(arr,n);
}
void xuat(int arr[],int n)
{
    printf("day ban vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

//cau b
int cau_b(int arr[],int n)
{
    int dem=0;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i+1]%arr[i]==0) dem++;
    }
    return dem;
}
//cau c
int cau_c(int arr[],int n)
{
    int result=0;
    for (int i = 0; i < n; i++)
    {
        result+=(n-i)*(arr[i]);
    }
    return result;
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    int arr[n];
    //cau a, nhap va xuat
    nhap(arr,n);

    //cau b, bo 2 so lien tiep so sau chia het cho so truoc.
    printf("so so co bo 2 so lien tiep co so sau chia het cho so truoc la: %d\n",cau_b(arr,n));

    //cau c,tinh tong
    printf("%d",cau_c(arr,n));
    return 0;
}
