//14. Nhập r, a, b. Tìm giao điểm của vòng tròn tâm tại gốc O(0,0), bán kính r và đường thẳng y = ax + b.
#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,r,x,y;
    printf("nhap he so cho phuong trinh y = ax + b: ");
    scanf("%f%f",&a,&b);
    back: printf("nhap ban kinh duong tron tam O ban kinh r = ");
    scanf("%f",&r);
    if(r<0) goto back;
    float x2 = a*a+1, x1 = a*b, x0 = b*b-r*r, delta=x1*x1-x2*x0;
    if(x1==0) 
    {
        x=sqrt(-x0/x2);
        printf("duong thang cat duong tron tai 2 diem: (%f,%f) va (%f,%f)", x, a*x+b, -x, a*(-x)+b);
    }
    else
    {
        if (delta==0)
        {
            x=-x1/x2;
            y=a*x+b;
            printf("duong thang cat duong tron tai 1 diem: (%f,%f)",x,y);
        }
        else if (delta>0)
        {
            x=(-x1-sqrt(delta))/x2;
            y=a*x+b;
            printf("duong tron va duong thang cat nhau tai 2 diem: (%f,%f) va ",x,y);
            x=(-x1+sqrt(delta))/x2;
            y=a*x+b;
            printf("(%f,%f)",x,y);
        }
        else printf("duong tron va duong thang khong cat nhau.");
    }
    return 0;
}
