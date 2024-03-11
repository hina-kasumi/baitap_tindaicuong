/*Câu 1: Nhập, xuất vào một dãy có n điểm, thực hiện các yêu cầu sau:
- Tính độ dài đường gấp khúc đi qua tất cả các điểm.
- Nhập bán kính R, đếm và in ra màn hình các điểm nằm phía trong đường tròn tâm 
O, bán kính R.
- Tìm diện tích hình tròn tâm O nhỏ nhất chứa tất cả các điểm.*/
#include<stdio.h>
#include<math.h>
#define pr(a) printf(a)
#define pr_i(a) printf("%d",a)
#define pr_f(a) printf("%f",a)
struct do_thi
{
    float x;
    float y;
};
//nhap n
void nhap_n(int *n)
{
    pr("nhap gia tri n duong: ");
    scanf("%d",n);
}
//nhap diem
void nhap_diem(do_thi diem[],int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f",&diem[i].x,&diem[i].y);
    }
}
//tinh do dai gap khuc
float do_dai(float x1, float y1,float x2, float y2)
{
    float result=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    return result;
}
//dem
short cau_b(float x,float y,float r)
{
    if(sqrt(x*x+y*y)<r) return 1;
    else return 0;
}

int main()
{
    int n;
    back: nhap_n(&n);
    if(n<1) goto  back;
    do_thi diem[n];
    pr("nhap toa do cac diem co trong do thi: \n");
    nhap_diem(diem,n);
    //a,
    for (int i = 0; i < n-1; i++)
    {
        printf("\ngia tri cua doan gap khuc thu %d ", i+1);
        printf("%f", do_dai(diem[i].x,diem[i].y,diem[i+1].x,diem[i+1].y));
    }
    //b,
    float r;
    pr("\nnhap do dai ban kinh r = ");
    scanf("%f",&r);
    int dem=0;
    int r_max=0;
    for (int i = 0; i < n; i++)
    {
        if(cau_b(diem[i].x,diem[i].y,r))
        {
            dem++;
        }
        if(cau_b(diem[i].x,diem[i].y,r) && r_max<sqrt(pow(diem[i].x,2)+pow(diem[i].y,2)))
        {
            r_max=sqrt(pow(diem[i].x,2)+pow(diem[i].y,2));
        }
    }
    if(dem>0) {
        pr("\nso diem nam trong duong tron ");pr_i(dem);
        pr("\ncac diem do la: ");
        for (int i = 0; i < n; i++)
        {
            if (cau_b(diem[i].x,diem[i].y,r))
            {
                printf("(%f,%f), ",diem[i].x,diem[i].y);
            }
        }
    }
    else pr("khong co diem nao nam trong duong tron\n");
    //c,
    pr("\n");
    pr_f(3.14*2*r_max*r_max);
    return 0;
}
