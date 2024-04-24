/*xây dụng cấu trúc sv: tên , mã, điểm, lớp
- tính điểm trung bình của tất cả sv
- nhập điểm chuẩn in ra sv trượt
- nhập x và in ra sinh viên lớn hơn x, bé hơn, bằng x
- thống kê mỗi lớp có bao nhiêu sinh viên*/


#include<stdio.h>
#include<string.h>

#define sc scanf
#define pr printf
#define endl printf("\n")

struct SinhVien
{
    int id;
    char name[20];
    float mark;
    char lop[10];
};


//ham in ra danh sach
void out (SinhVien sv)
{
    pr("%10d%20s%10.2f%10s\n",sv.id, sv.name, sv.mark, sv.lop);
}


//ham in nhung so lon hon x
bool Higher (SinhVien sv[], int n, int x)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if(sv[i].mark > x) 
        {
            out(sv[i]);
            check = true;
        }
    }
    endl;
    return check;
}

//ham in ra so nho hon x
bool Lower (SinhVien sv[], int n, int x)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if(sv[i].mark < x) 
        {
            out(sv[i]);
            check = true;
        }
    }
    endl;
    return check;
}

bool Equal (SinhVien sv[], int n, int x)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if(sv[i].mark == x)
        {
            out(sv[i]);
            check = true;
        }
    }
    endl;
    return check;
}

int main()
{
    //so sinh vien can quan ly
    int n;
    back: pr("nhap so sinh vien can quan ly: ");
    sc("%d", &n);
    if(n<1)
    {
        pr("vui long nhap lai.\n");
        goto back;
    }

    //nhap thong tin sinh vien
    SinhVien sv[n];
    pr("nhap thong tin sinh vien:\n");
    for (int i = 0; i < n; i++)
    {
        //id
        pr("id: "); sc("%d", &sv[i].id);
        
        //ten sinh vien
        pr("ten: "); fflush(stdin); gets(sv[i].name);

        //diem
        pr("diem: "); sc("%f", &sv[i].mark);

        //lop
        pr("lop: "); fflush(stdin); gets(sv[i].lop);
        endl;
    }
    
    //in ra danh sach sinh vien
    pr("danh sach sinh vien ban vua nhap:\n");
    for (int i = 0; i < n; i++)
    {
        out(sv[i]);
    }
    endl;

    //1,điểm trung bình của sinh viên
    float average = 0;
    for (int i = 0; i < n; i++)
    {
        average+= sv[i].mark;
    }
    pr("diem trung binh cua cac sinh vien: %.2f\n\n", average/n);


    //2,nhập điểm chuẩn in ra sv trượt
    float x = 0;
    pr("nhap diem chuan: ");
    sc("%f", &x);
    pr("danh sach nhung sinh vien truot:\n");
    if(!Lower(sv, n, x)) pr("khong co sinh vien nao truot.\n\n");


    //3,nhập x và in ra sinh viên lớn hơn x, bé hơn, bằng x
    pr("nhap x: ");
    sc("%f",&x);

    //danh sach lon hon x
    pr("nhung sinh vien co diem lon hon x:\n");
    if(!Higher(sv, n, x)) pr("khong co sinh vien nao diem cao hon x\n\n");
    
    //danh sach bang hon x
    pr("nhung sinh vien co diem bang x:\n");
    if(!Equal(sv, n, x)) pr("khong co sinh vien nao diem bang x.\n\n");

    //danh sach nho hon x
    pr("nhung sinh vien co diem nho hon x:\n");
    if(!Lower(sv, n, x)); pr("khong co sinh vien nao diem nho hon x.\n\n");

    //4,thống kê mỗi lớp có bao nhiêu sinh viên
    int check[n]={0};
    for (int i = 0; i < n; i++)
    {
        int dem=1;
        if (!check[i])
        {
            for (int j = i+1; j < n; j++)
            {
                if(!stricmp(sv[i].lop,sv[j].lop))
                {
                    dem++;
                    check[j]=1;
                }
            }
        }
        if(!check[i]) printf("\nlop %s co %d sinh vien.",sv[i].lop,dem);
    }
    return 0;
}
