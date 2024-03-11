//tìm x,y trong hệ phương trình cấp 1.
#include<stdio.h>
int main()
{
    //nhap he so cho he phuong trinh
    float a1,a2,b1,b2,c1,c2,x,y;
    printf("nhap he so cho phuong trinh 1: ax+by=c\n");
    scanf("%f%f%f",&a1,&b1,&c1);
    printf("nhap he so cho phuong trinh 2: ax+by=c\n");
    scanf("%f%f%f",&a2,&b2,&c2);
    //giai he phuong trinh
    y=(a1*c2-a2*c1)/(b2*a1-b1*a2);
    x=(c1-b1*y)/a1;
    printf("gia tri cua x = %f\n",x);
    printf("gia tri cua y = %f",y);
    return 0;
}
