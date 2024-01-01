/*Câu 1: Nhập, xuất vào một dãy số n điểm, thực hiện các yêu cầu sau:
- Đếm số điểm nằm phía trên đường phân giác của góc phần tư thứ nhất và in kết quả
ra màn hình.
- Tìm diện tích hình chữ nhật nhỏ nhất có 4 cạnh của chiều dài và chiều rộng song 
song với trục tọa độ chứa tất cả các điểm*/
#include<stdio.h>
#include<math.h>
#define nn printf("\n")

int main()
{
    int n,dem=0;
    do{
        printf("nhap n: ");
        scanf("%d",&n);
    }while(n<1);
    int diem[n][2];
    printf("nhap gia tri cho tung phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&diem[i][0],&diem[i][1]);
        if(diem[i][0]>0 && diem[i][1]>0) dem++;
    }
    //1,
    if(dem==0) printf("khong co diem nao thuoc goc phan tu thu nhat\n");
    else printf("so diem thuoc goc phan tu thu nhat: %d\n",dem);
    //2,
    int maxx=diem[0][0],maxy=diem[0][1],minx=diem[0][0],miny=diem[0][1];
    for (int i = 0; i < n; i++)
    {
        maxx=(maxx<diem[i][0])? diem[i][0]:maxx;
        maxy=(maxy<diem[i][0])? diem[i][0]:maxy;
        minx=(minx>diem[i][0])? diem[i][0]:minx;
        miny=(miny>diem[i][0])? diem[i][0]:miny;
    }
    printf("dien tich chu nhat: %d",(maxx-minx)*(maxy-miny));
    return 0;
}
