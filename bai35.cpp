#include<stdio.h>
int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    printf("nhap gia tri day n: ");
    int arr[n],dem=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((arr[i]+arr[j])%3==0)
            {
                dem++;
            }
        }
    }
    if (dem==0)printf("khong co cap nao co tong chia het cho 3.");
    else
    {
        printf("cap co tong chia het cho 3: ");
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if ((arr[i]+arr[j])%3==0)
                {
                    printf("(%d,%d) ",arr[i],arr[j]);
                }
            }
        }
        printf("\nso cap co tong chia het cho 3: %d",dem);
    }
    return 0;
}