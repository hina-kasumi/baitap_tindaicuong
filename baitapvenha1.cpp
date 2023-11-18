#include<stdio.h>
int main()
{
    int phantu[10],tong=0;
    for (int i = 0; i < 10; i++)scanf("%d",&phantu[i]);
     for (int i = 0; i < 10; i++)
    {    
        {
            printf("%d ", phantu[i]);
        }
        {
            if (phantu[i]%2==0)
            {
                tong+=phantu[i];
            }
        }
    }
    int max=phantu[0];
    for (int i = 0; i < 10; i++)
    {
        if (max<phantu[i])
        {
            max=phantu[i];
        }
    }
    printf("\n%d\n",tong);
    printf("%d",max);
    return 0;
}