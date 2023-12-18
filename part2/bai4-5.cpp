#include<stdio.h>
#include<math.h>
#define for(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define pr_int(x) printf("%d", x)
#define pr_float(x) printf("%f",x)
#define pr(a) printf(a);
struct do_thi{
    float x,y;
};
//xuat va nhap
void xuat(do_thi toa_do[], int n)
{
    pr("cac toa do ban vua nhap la: ");
    for(i,0,n) printf("(%f,%f), ", toa_do[i].x,toa_do[i].y);
    pr("\n");
}

void nhap(do_thi toa_do[], int n)
{
    for(i,0,n) scanf("%f%f",&toa_do[i].x,&toa_do[i].y);
    xuat(toa_do,n);
}
//nhap a va b
void nhap_ab(float &a,float &b)
{
    scanf("%f%f",&a,&b);
}
//dem cac diem tren doan thang
int dem_b(do_thi toa_do[], int n,int i,int dem,float a,float b)
{
    if (i<n)
    {
        if(toa_do[i].y>toa_do[i].x*a+b) dem++;
        return dem_b(toa_do,n,i+1,dem,a,b);
    }
    return dem;
}
//do dai cua doan thang dai nhat
float cau_c(do_thi toa_do[], int n)
{
    float max=0;
    for(i,0,n-1)
    {
        for(j,i+1,n)
        {
            if(max<sqrt(pow(toa_do[i].x-toa_do[j].x,2)+pow(toa_do[i].y-toa_do[j].y,2)))
            {
                max=sqrt(pow(toa_do[i].x-toa_do[j].x,2)+pow(toa_do[i].y-toa_do[j].y,2));
            }
        }
    }
    return max;
}
int main()
{
    int n;
    pr("nhap n: ");
    scanf("%d",&n);
    do_thi toa_do[n];
    pr("nhap cac diem cho do thi: ");
    //cau a
    nhap(toa_do,n);
    //cau b
    float a,b;
    int dem=0;
    pr("nhap 2 so thuc a va b ");
    nhap_ab(a,b);
    //dem cac diem ben tren y=ax+b
    pr("so diem nan tren duong thang y=a*x+b = ");
    pr_int(dem_b(toa_do,n,0,dem,a,b));
    //cau c
    pr("\ndoan thang dai nhat la: ");
    pr_float(cau_c(toa_do,n));
}
