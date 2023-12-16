//9. Viết chương trình in ra n số nguyên tố đầu tiên (n nhập từ bàn phím)
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("n so nguyen to dau tien la. ");
    scanf("%d",&n);
    int gioi_han =10000;
    int arr[gioi_han];
    //gán toàn bộ các số là số nguyên tố.
    for (int i = 1; i < gioi_han; i++)
    {
        arr[i]=1;
    }
    //sàng những số không phải số nguyên tố
    for (int i = 2; i < sqrt(gioi_han); i++)
    {
        if (arr[i]==1)
        {
            for (int j = i*2; j < gioi_han; j+=i)
            {
                arr[j]=0;
            }
        }
    }
    //in so nguye to
    long long int dem=0;
    for (int i = 1; i < gioi_han; i++)
    {
        if (arr[i]==1)
        {
            printf("%d ",i);
            dem++;
        }
        if(dem==n) break;
    }
    
    return 0;
}
