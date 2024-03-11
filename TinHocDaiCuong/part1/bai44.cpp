#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    //nhap gia tri
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    printf("nhap cac he so: ");
    float heso[n+1];
    for (i=0;i<=n;i++) scanf("%f",&heso[i]);
    //in he so da thuc tren mot dong
    printf("he so cua da thuc la: ");
    for (i=0;i<=n;i++) printf("%.2f ",heso[i]);
    //Đếm rồi in ra màn hình số các hệ số có giá trị bằng 0.
    int dem=0;
    for (i=0;i<=n;i++) if(heso[i]==0) dem++;
    printf("\nso he so co gia tri bang 0 la: %d\n",dem);
    //nhap x va in ra gia tri p'(x).
    printf("nhap gia tri x = ");
    float x,result=0;
    scanf("%f",&x);
    for ( i = 0; i <= n; i++)
    {
        result+=heso[i]*i*pow(x,i-1);
    }
    printf("ket qua cua bieu thuc la: %f",result);
    return 0;
}
