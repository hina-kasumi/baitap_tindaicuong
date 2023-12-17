#include<stdio.h>

int main()
{
    int n;
    back: printf("nhap so nguyen duong n: ");
    scanf("%d",&n);
    if (n<1) goto back;
    float x;
    printf("nhap so thuc x: ");
    scanf("%f",&x);
    float mau,tu,s;
    mau = (n+n*n)/2;
    printf("ket qua cua bieu thuc s = ");
    for (int i = 0; i <= n; i++)
    {
        tu=x;
        for (int j = 1; j <= i; j++)
        {
            tu*=(x+j);
        }
		s+=tu;
    }
    s/=mau;
    printf("%f",s);
    return 0;
}
