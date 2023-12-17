#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    back: printf("nhap so nguyen duong n: ");
    scanf("%d",&n);
    if (n<1) goto back;
    float x,s=1;
    printf("nhap so thuc x: ");
    scanf("%f",&x);
    for (int i = 1; i <= n; i++)
    {
        s=sqrt(i*x+s);
    }
    printf("%f",s);
    return 0;
}
