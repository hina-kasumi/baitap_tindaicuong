#include<stdio.h>
int main()
{
    int n,i,count;
    printf("nhap so n: ");
    scanf("%d",&n);
    float day[n],m;
    printf("nhap so m: ");
    scanf("%f",&m);
    count=0;
    for ( i = 0; i < n; i++)
    {
        {
            scanf("%f",&day[i]);
        }
        {
            if (day[i]>m)
            {
                count++;
            }   
        }
    }
    printf("so so lon hon %f la: %d",m,count);
    return 0;
}
