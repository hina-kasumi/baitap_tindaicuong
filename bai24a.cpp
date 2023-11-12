//Cho số thực x và số nguyên dương n. Hãy viết chương trình tính biểu thức S
//S = 2005 + x + x^2 + … + x^n
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    float x, bieuthuc=2005;
    printf("nhap mu n va gia tri x: ");
    scanf("%d%f",&n,&x);
    for (int i = 1; i <= n; i++)
    {
        bieuthuc+=pow(x,i);
    }
    printf("%f",bieuthuc);
    return 0;
}
