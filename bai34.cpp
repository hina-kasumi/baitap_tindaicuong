/*34, Nhập dãy n số nguyên từ bàn phím. Xác định 2 số nguyên chia hết cho 3 lớn nhất trong 
dãy và chỉ rõ vị trí của 2 số nguyên đó. Giả sử rằng dãy số có phần tử thứ 2 và phần tử thứ 3 
chia hết cho 3.*/
#include<stdio.h>
int main()
{
    int n,i=0;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if (n<=0) goto back;
    int arr[n],max1,max2,dem=0,dirmax1,dirmax2,step;
    arr: printf("nhap gia tri cua cac phan tu trong day: ");
    i=0;
    while (i<n)
    {
        scanf("%d",&arr[i]);
        if (arr[i]%3==0)
        {
            dem++;
            max1=arr[i];
            max2=arr[n-1-i];
            if(max1<max2)
            {
                step=max1;
                max1=max2;
                max2=step;
            }
        }
        i++;
    }
    if (dem<2)
    {
        printf("vui long nhap lai cac phan tu trong day: \n");
        goto arr;
    }
    //so chia het cho 3 lon nhat
    for (i = 0; i < n; i++)
    {
        if (max1<=arr[i] && arr[i]%3==0)
        {
            max1=arr[i];
            dirmax1=i+1;
        }
    }
    printf("\nso chia het cho 3 lon nhat la: %d",max1);
    printf("\n vitri so chia het cho 3 lon nhat la: %d",dirmax1);
    //so chia het cho 3 lon thu 2
    for (i = 0; i < n; i++)
    {
        if (max2<=arr[i] && arr[i]%3==0 && arr[i]!=max1)
        {
            max2=arr[i];
            dirmax2=i+1;
        }
    }
    printf("\nso chia het cho 3 lon thu 2 la: %d",max2);
    printf("\n vitri so chia het cho 3 lon thu 2 la: %d",dirmax2);
    return 0;
}