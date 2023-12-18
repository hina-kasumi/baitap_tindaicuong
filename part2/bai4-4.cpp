#include<stdio.h>
#include<math.h>
//cau a, nhap xuat
void xuat(float arr[],int n);
void nhap(float arr[],int n)
{
    printf("nhap gia tri cho cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) scanf("%f",&arr[i]);
    xuat(arr,n);
}
void xuat(float arr[],int n)
{
    printf("day ban vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ",arr[i]);
    }
    printf("\n");
}
//cau b
void cau_b(float arr[], int n, float x, int i,int &dem)
{
    if (i<n)
    {
        
        if(abs(arr[i]) > x)
        {
            dem++;
        }
        cau_b(arr,n,x,i+1,dem);
    }
}
//cau c
void cau_c(float arr[],int n,int i,int *dem,int j)
{
    if(i<n)
    {
        if(arr[i]*arr[j]==arr[i]+arr[j]) (*dem)++;
        cau_c(arr,n,i+1,dem,j);
    }
}
//cau d
void cau_d (float arr[],int n, float max,int &i1, int &i2)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (max<abs(abs(arr[i])-abs(arr[j])))
            {
                max=abs(abs(arr[i])-abs(arr[j]));
                i1=i;
                i2=j;
            }
        }
    }
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float arr[n];
    //cau a, nhap va xuat
    nhap(arr,n);
    //cau b, cac so lon hon x
    int i=0;
    int dem=0;
    float x;
    printf("nhap so nguyen x: ");
    scanf("%f",&x);
    //cauu b dung tham chieu
    cau_b(arr,n,x,0,dem);
    printf("co %d phan tu lon hon x do la: ", dem);
    for (int i = 0; i < n; i++)
    {
        if(abs(arr[i])>x) printf("%f ",arr[i]);
    }
    // cau c. Đếm các cặp 2 phần tử bất kỳ mà tích của chúng bằng tổng của chúng
    //dem bang con tro
    dem=0;
    
    for (int j = 0; j < n-1; j++)
    {
        cau_c(arr,n,j+1,&dem,j);
    }
    
    printf("\nco %d cap so co tong bang tich",dem);
    // cau d
    float max=0;
    int i1,i2;
    cau_d(arr,n,max,i1,i2);
    printf("\ncap co hieu lon nhat la: %f va %f", arr[i1],arr[i2]);
    return 0;
}
