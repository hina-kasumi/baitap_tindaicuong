#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<0) goto back;
    printf("nhap he so nguyen: ");
    int arr[n+1];
    for (i = 0; i <= n; i++) scanf("%d",&arr[i]);
    printf("he so cua da thuc: ");
    for (i = 0; i <= n; i++) printf("%d ",arr[i]);
    float x,result;
    printf("\nnhap gia tri so thuc x: ");
    scanf("%f",&x);
    for (i = 0; i <= n; i++)
    {
        result+=arr[i]*pow(x,i);
    }
    printf("gia tri cua  bieu thuc la: %f",result);
}