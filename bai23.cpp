#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("nhap n va x: ");
    float x;
    scanf("%d%f",&n,&x);
    float bieuthuc=1;
    for (int i = 2; i <= n; i++)
    {
        bieuthuc+=pow(x,i);
    }
    printf("%f",bieuthuc);
    return 0;
}