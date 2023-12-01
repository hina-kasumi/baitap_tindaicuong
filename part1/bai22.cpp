#include<stdio.h>
int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    int arr[n],max;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max<arr[i] && arr[i]%4==0)
        {
            max=arr[i];
        }
    }
    if (arr[3]%4!=0)
    {
        goto back;
    }
    printf("so lon nhat chia het cho 4 la: %d",max);
    return 0;
}