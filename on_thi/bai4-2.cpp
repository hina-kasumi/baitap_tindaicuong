/*Câu 2: Định nghĩa một cấu trúc Sinh viên gồm các thành phần: Mã SV, tên SV, năm sinh, điểm.
Nhập, xuất n sinh viên.
- Tìm sinh viên lớn tuổi nhất trong lớp.
- Nhập vào mã sinh viên, in ra màn hình thông tin của sinh viên đó.
- Nhập vào điểm chuẩn, in ra màn hình những sinh viên trung tuyển.*/
#include<stdio.h>
#include<string.h>
struct sinhvien
{
    int msv,year;
    float diem;
    char name[20];
};
void in(sinhvien sv[],int i)
{
    printf("ma sinh vien: %d\n",sv[i].msv);
    printf("ten: %s\n",sv[i].name);
    printf("nam sinh: %d\n",sv[i].year);
    printf("diem: %f\n\n",sv[i].diem);
    
}
int main()
{
    int n;
    printf("nhap so sinh vien: ");
    scanf("%d",&n);
    sinhvien sv[n];
    for (int i = 0; i < n; i++)
    {
        printf("nhap ma sinh vien sinh vien thu %d: ",i+1);
        scanf("%d",&sv[i].msv);
        printf("nhap ten sinh vien thu %d: ",i+1);
        fflush(stdin);
        gets(sv[i].name);
        printf("nhap nam sinh sinh vien thu %d: ",i+1);
        scanf("%d",&sv[i].year);
        printf("nhap diem sinh vien thu %d: ",i+1);
        scanf("%f",&sv[i].diem);
    }
    printf("danh sach sinh vien ban vua nhap: ");
    for (int i = 0; i < n; i++)
    {
        in(sv,i);
    }
    //1,
    printf("sinh vien lon tuoi nhat trong lop: \n");
    int max=3000,dir;
    for (int i = 0; i < n; i++)
    {
        if (max>sv[i].year)
        {
            max=sv[i].year;
            dir=i;
        }
    }
    in(sv,dir);
    //2,
    printf("nhap va ma sinh vien ma ban muon tim: ");
    int search;
    dir=-1;
    scanf("%d",&search);
    for (int i = 0; i < n; i++)
    {
        if (search==sv[i].msv)
        {
            dir=i;
            break;
        }
    }
    if(dir==-1) printf("sinh vien ban tim khong ton tai.\n");
    else 
    {
        printf("day la thong tin sinh vien ban can tim.\n");
        in(sv,dir);
    }
    //3,
    float diem_chuan;
    printf("nhap diem chuan: ");
    scanf("%f",&diem_chuan);
    printf("day la danh sach cac thi sinh trung tuyen.\n");
    for (int i = 0; i < n; i++)
    {
        if (sv[i].diem>=diem_chuan)
        {
            in(sv,i);
        }
    }
    
    return 0;
}
