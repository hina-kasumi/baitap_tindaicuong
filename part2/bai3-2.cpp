/*2. Cho số thực x và số nguyên dương n. Tính biểu thức:
F = 2005 + (x+3)/9 + (x+5)/11 + ... + (x + 2n +1)/(2n+7)*/
#include<stdio.h>
int main()
{
    int n;
    printf("nhap so nguyen duong n: ");
    scanf("%d",&n);
    float s=2005,x;
    printf("nhap gia tri cua x = ");
    scanf("%f",&x);
    for (int i = 1; i <= n; i++) s+=(x+2*i+1)/(2*i+7);
    printf("gia tri cua bieu thuc %f", s);
    return 0;
}
