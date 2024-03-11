/*37, Nhập dãy n số nguyên từ bàn phím. Kiểm tra xem dãy số đó có phải là dãy số giảm thật 
sự không.*/
#include<stdio.h>
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
    int check=0;
    for (i = 1; i < n; i++)
    {
        if (arr[i]>arr[i-1])
        {
            printf("day khong phai day giam. ");
            check++;
            break;
        }
    }
    if (check==0) printf("day la day giam thuc su. ");
    return 0;
}
