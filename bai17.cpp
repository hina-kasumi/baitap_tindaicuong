#include<stdio.h>
#include<math.h>
main()
{
    int n,i;
    printf("nhap n: ");
    scanf("%d",&n);
    float day[n],tich,ketqua,count;
    tich=1;
    count=0;
    for (i = 0; i < n; i++)
    {
        {
            scanf("%f",&day[i]);
        }
        {
            if(day[i]>0)
                {
                    tich*=day[i];
                    count++;
                }
        }
    }
    ketqua=pow(tich,1/count);
    printf("ket qua la: %f",ketqua);
}
