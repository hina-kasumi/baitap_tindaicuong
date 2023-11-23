#include<stdio.h>
#include<math.h>
int main()
{
    float x,result;
    int n;
    back: printf("nhap so nguyen duong n: ");
    scanf("%d",&n);
    if(n<1) 
    {
        printf("vui long nhap lai so n.\n");
        goto back;
    }
    printf("nhap so thuc x: ");
    scanf("%f",&x);
    result=x;
    for (int i = 1; i <= n; i++)
    {
        result+=pow(i+x,3);
    }
    printf("gia tri bieu thuc la: %f",result);
    return 0;
}
