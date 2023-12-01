/*36, Nhập dãy n số nguyên từ bàn phím. Đếm số phần tử trong dãy hoặc chia hết cho 4 hoặc 
chia hết cho 5*/
#include<stdio.h>
void xuat(int n, int arr[n],int chia)
{
    int dem=0,i;
    for (i = 0; i < n; i++)
    {
        if (arr[i]%chia==0)
        {
            dem++;
        }
    }
    if (dem==0)printf("khong co gia tri nao chia het cho %d.\n",chia);
    else
    {
        printf("gia tri chia het cho %d trong day la: ",chia);
        for (i = 0; i < n; i++)
        {
            if (arr[i]%chia==0)
            {
                printf("%d ",arr[i]);
            }
        }
        printf("\nco %d co chia het cho %d trong day.\n",dem,chia);
    }
}




int main()
{
    int n,i;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    printf("nhap gia tri day n: ");
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    //so chia het cho 4
    xuat(n,arr,4);
    //chia cho 5
    xuat(n,arr,5);
    return 0;
}
