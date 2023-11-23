/*42, Nhập một dãy số thực a1, a2 ... an.
Nhập số thực M. Xác định và in ra màn hình trên 1 dòng các phần tử của dãy mà có giá trị
lớn hơn M.*/
#include<stdio.h>
int main()
{
    int n,i,check=0;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float arr[n],m;
    printf("nhap gia tri day n: ");
    for (i = 0; i < n; i++) scanf("%f",&arr[i]);
    printf("nhap so thuc m: ");
    scanf("%f",&m);
    for ( i = 0; i < n; i++) if(m<arr[i]) check++;
    if(check==0) printf("khong co gia tri nao lon hon m.");
    else
    {
        printf("nhung gia tri trong day lon hon m la: ");
        for ( i = 0; i < n; i++) if(m<arr[i]) printf("%f ",arr[i]);
    }
    return 0;
}
