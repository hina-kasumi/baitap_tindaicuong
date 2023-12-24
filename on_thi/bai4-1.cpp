#include<stdio.h>
#include<math.h>
void in(double heso[], double heso1[],int m,int n)
{
    int hieu=n-m;
    printf("phuong trinh hieu cua Q(x) va P(x) = ");
    for(int i=0;i<hieu;i++)
    {
        printf("%.2fx^%d + ",heso[i],n-i);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%.2fx^%d + ",heso[i+hieu]-heso1[i],n-i-hieu);
    }
    printf("%.2f",heso[n]-heso1[m]);
}
main()
{
    int n;
    printf("nhap bac cho phuong trinh: ");
    scanf("%d",&n);
    printf("nhap he so cho phuong trinh: ");
    double heso[n+1];
    for(int i=0;i<=n;i++)
    {
        scanf("%lf",&heso[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%.2fx^%d + ",heso[i],n-i);
    }
    printf("%3.2lf",heso[n]);
    double x;
    printf("\nnhap so thuc x: ");
    scanf("%lf",&x);
    //chua dao ham
    double Px=heso[n];
    for(int i=0;i<n;i++)
    {
        Px+=heso[i]*pow(x,n-i);
    }
    //dao ham
    double px=heso[n-1];
    for(int i=0;i<n-1;i++)
    {
        Px+=heso[i]*pow(x,n-i-1)*(n-i);
    }
    //1,
    printf("ket qua cua s = %lf\n",sqrt(2021+Px+px));
    //2,
    int m;
    printf("nhap bac cho Q(x): ");
    scanf("%d",&m);
    printf("nhap he so cho Q(x): ");
    double heso1[m+1];
    for(int i=0;i<=m;i++)
    {
        scanf("%lf",&heso1[i]);
    }
    if(m>n) in(heso1,heso,m,n);
    else if(m<n) in(heso,heso1,m,n);
}
