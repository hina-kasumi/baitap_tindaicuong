#include<stdio.h>
#include<math.h>

int main()
{
    short limit=1000,sum;
    for (short i = 3; i < limit; i++)
    {
        sum=0;
        for (short j = 1; j <= i/2; j++)
        {
            if (i%j==0)
            {
                sum+=j;
            }
        }
        if (sum==i)
        {
            printf("%hd ",i);
        }
    }
    
    return 0;
}
