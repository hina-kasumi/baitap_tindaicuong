/*39, Nhập dãy số gồm n số thực từ bàn phím, sau đó nhập 2 số thực a, b từ bàn phím. Đếm số
phần tử trong dãy có giá trị thuộc [a,b]. Liệt kê các phần tử nằm ngoài [a,b].*/
#include<stdio.h>
int main()
{
    int n,i,dem=0,check=0;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float arr[n],a,b;
    re: printf("nhap gia tri a va b: ");
    scanf("%f%f",&a,&b);
    if(a>=b) goto re;
    printf("nhap gia tri day n: ");
    for (i = 0; i < n; i++) scanf("%f",&arr[i]);
    for ( i = 0; i < n; i++)
    {
        if(arr[i]>=a && arr[i]<=b) dem++;
        else  check++;
    }
    if(dem==0) printf("\nkhong co so nao trong day thuoc [%f,%f] ",a,b);
    else
    {
        printf("\nso phan tu trong day thuoc [%f,%f] la: %d",a,b,dem);
    }
    if(check==0) printf("\nkhong co gia tri nao nam ngoai [%f,%f] ",a,b);
    else
    {
        printf("\ncac phan tu nam ngoai [%f,%f]: ",a,b);
        for ( i = 0; i < n; i++)
        {
            if(arr[i]>=a && arr[i]<=b) continue;
            else printf("%f ",arr[i]);
        }
    }
    return 0;
}