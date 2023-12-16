//tìm số Fibonacci thứ n
#include<stdio.h>
#include<math.h>

int main()
{
    long long int n,result;
    scanf("%lld",&n);
    long long int n_1=1,n_2=0;
    for (int i = 2; i <= n; i++)
    {
        result=n_1+n_2;
        n_2 = n_1;
        n_1 = result;
    }

    printf("%lld",result);
    return 0;
}
