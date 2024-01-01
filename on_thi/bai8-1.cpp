/*Câu 1: Nhập, xuất vào một dãy số n điểm, thực hiện các yêu cầu sau:
- Tìm đoạn thẳng dài nhất
- Nhập 2 số thực a, b. Đếm rồi in ra màn hình số điểm thuộc đường thẳng y = ax + b.
- Đếm số điểm nằm phía trên đường phân giác của góc phần tư thứ nhất và in kết quả
ra màn hình.*/
#include<stdio.h>
#include<math.h>
#define nn printf("\n");
struct dothi
{
    float x,y;
};

void xuat(dothi diem[],int i)
{
    printf("(%.2f,%.2f)",diem[i].x,diem[i].y);
}

void nhap(dothi diem[],int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f",&diem[i].x,&diem[i].y);
    }
    for (int i = 0; i < n; i++)
    {
        xuat(diem,i);
    }
}

int dem1(dothi diem[],int n,int i,int dem)
{
    if(i<n)
    {
        if (diem[i].x>0 && diem[i].y>0)
        {
            dem++;
        }
        return dem1(diem,n,i+1,dem);
    }
    else return dem;
}

float lon_nhat(dothi diem[],int n,int i,float max)
{
    if(i<n-1)
    {
        float do_dai = sqrt( pow( diem[i+1].x - diem[i].x , 2) + pow( diem[i+1].y - diem[i].y , 2));
        max=(max<do_dai)? do_dai:max;
        return lon_nhat(diem,n,i+1,max);
    }
    else return max;
}

int main()
{
    int n;
    do
    {
        printf("nhap n: ");
        scanf("%d",&n);
    } while (n<1);
    printf("nhap toa do cua %d diem: ",n);
    dothi diem[n];
    nhap(diem,n);
    //1,
    printf("\n\ndoan thang dai nhat la: %f\n",lon_nhat(diem,n,0,0));
    //2,
    float a,b;
    int dem=0;
    printf("\nnhap he so a va b: ");
    scanf("%f%f",&a,&b);
    for (int i = 0; i < n; i++)
    {
        if (diem[i].y==a*diem[i].x+b)
        {
            dem++;
        }
    }
    if (dem>0) printf("co %d diem thuoc duong thang y=%.2fx+%.2f.\n",dem,a,b);
    else printf("khong co diem nao thuoc duong thang.\n");
    //3,
    dem=dem1(diem,n,0,0);
    if(dem) printf("co %d diem thuoc goc phan tu thu nhat.",dem);
    else printf("khong co diem nao thuoc goc phan tu thu nhat.");
    return 0;
}
