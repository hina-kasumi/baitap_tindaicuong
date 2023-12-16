#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float x,y,result=0;
    printf("nhap so thuc x va y: ");
    scanf("%f%f", &x, &y);
    for (int i = 1; i <= n; i++)
    {
        result+=(1+pow(x,i))/(pow(x,2*i)+1);
    }
    printf("gia tri cua bieu thuc s = %f",result);
    return 0;
}
