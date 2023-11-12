#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    float arr[n],step;
    for ( i = 0; i < n; i++)
    
        {
            scanf("%f",&arr[i]);
        }
    for ( i = 0; i < n; i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]<arr[j])
                {
                    step=arr[i];
                    arr[i]=arr[j];
                    arr[j]=step;
                }
            }
        }
    
    for ( i = 0; i < n; i++)
    {
        printf("%f ",arr[i]);
    }
    return 0;
}
