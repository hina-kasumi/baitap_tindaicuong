/*4. Cho một số nguyên dương n. Tính:
S = 1.3.5.7...n nếu n lẻ và
S = 2.4.6.8...n nếu n chẵn*/
int s(int n, int x)
{
    int s=1;
    for (int i = 1; i <= n; i++)
    {
        if(i%2==x)
        {
            s*=i;
        }
    }
    return s;
}
#include<stdio.h>
int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    printf("%d",s(n,n%2));
    return 0;
}
