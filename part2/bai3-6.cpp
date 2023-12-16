#include<stdio.h>
#include<math.h>

void nhap(float *a)
{
    scanf("%f",a);
}
int gt(int n)
{
    int gt=1;
    for (int i = 1; i <= n; i++)
    {
        gt*=i;
    }
    return gt;
}
int main()
{
    float n,x,result=0;
    printf("nhap n: ");
    nhap(&n);
    printf("nhap gia tri cua x: ");
    nhap(&x);
    for (int i = 1; i <= n; i++)
    {
        result+=(pow(-1,i+1)*pow(x,2*i-1)/gt(i*2-1));
    }
    printf("%f",result);
    return 0;
}
