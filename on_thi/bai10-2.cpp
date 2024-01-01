/*Câu 2: Xây dựng một cấu trúc Sinh viên gồm các thành phần: Mã sinh viên, Họ tên
,Trường(giả sử có 3 trường dự thi là A, B, C), Điểm thi. Nhập, xuất n thí sinh. Viết chương 
trình thực hiện:
- Tìm kiếm và in ra các sinh viên có điểm thi >= 15 thuộc trường B.
- Sắp xếp lại các phần tử của mảng cấu trúc theo thứ tự giảm dần của điểm, sau đó in 
danh sách thí sinh.
- Nhập vào tên một sinh viên, in ra thông tin sinh viên đó*/
#include<stdio.h>
#include<string.h>
#define nn printf("\n")
struct sinh_vien
{
    int msv;
    char name[30],school[20];
    float diem;
};

void xuat(sinh_vien sv[], int i)
{
    printf("%10d%20s%15s%10.1f\n",sv[i].msv,sv[i].name,sv[i].school,sv[i].diem);
}

void bang()
{
    printf("\tmsv\t\tho ten\t\ttruong\t   diem\n");
}

//2,
void bub_sort(sinh_vien sv[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (sv[i].diem<sv[j].diem)
            {
                sinh_vien tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;
            }
        }
    }
}

int main()
{
    int n,check=0;
    char a[2]="A",b[2]="B",c[2]="C";
    back: printf("nhap so sinh vien can quan ly: ");
    scanf("%d",&n);
    if (n<1) goto back;
    sinh_vien sv[n];
    printf("nhap thong tin sinh vien:\n");
    for (int i = 0; i < n; i++)
    {
        printf("thong tin sinh vien thu %d\n",i+1);
        printf("msv: "); scanf("%d",&sv[i].msv);
        printf("ten: "); fflush(stdin); gets(sv[i].name);
        printf("truong: "); fflush(stdin); gets(sv[i].school);
        printf("diem: "); scanf("%f",&sv[i].diem);
        if(sv[i].diem>=15 && !stricmp(sv[i].school,b)) check++;
    }
    //0,
    printf("thong tin ban vua nhap:\n");
    for (int i = 0; i < n; i++)
    {
        bang();
        xuat(sv,i);
    }
    nn;
    //1,
    if(check)
    {
        printf("\nco %d sinh vien thuoc truong B co diem >=15\n",check);
        bang();
        for (int i = 0; i < n; i++)
        {
            if (sv[i].diem>=15 && !stricmp(sv[i].school,b))
            {
                xuat(sv,i);
            }
        }
    }
    else printf("khong co sinh vien truong B nao co diem >=15");
    nn;
    //2,
    bub_sort(sv,n);
    printf("\ndanh sach sinh vien sau khi duoc xap xep theo thu tu giam dan\n");
    bang();
    for (int i = 0; i < n; i++)
    {
        xuat(sv,i);
    }
    nn;
    //3,
    char search[30];
    printf("nhap ten sinh vien muon tim: "); fflush(stdin); gets(search);
    printf("day la thong tin sinh vien do\n");
    bang();
    for (int i = 0; i < n; i++)
    {
        if (!strcmpi(search,sv[i].name))
        {
            xuat(sv,i);
        }
    }
    return 0;
}
