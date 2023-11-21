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
    for (i = 1; i < n; i++)
    {
        if (arr[i]<arr[i-1])
        {
            
        } 
    }
    
    return 0;
}
