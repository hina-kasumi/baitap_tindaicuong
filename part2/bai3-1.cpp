#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    back: printf("nhap n:");
    scanf("%d",&n);
    if(n<1) goto back;
    float f,x;
    printf("nhap gia tri cua x = ");
    scanf("%f",&x);
    f=x;
    for (int i = 1; i <= n; i++)f+=pow(i+x,3);
    printf("gia tri cua  bieu thuc f = %f",f);
    return 0;
}
