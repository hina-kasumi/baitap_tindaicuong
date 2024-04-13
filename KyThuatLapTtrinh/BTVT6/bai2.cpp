/*Bài 2: Tổ chức dữ liệu để quản lý sinh viên bằng cấu trúc trong một mảng n phần tử, mỗi phần tử 
có cấu trúc như sau: - - - - 
Mã sinh viên. 
Tên. 
Năm sinh. 
Điểm toán, lý, hoá, điểm trung bình. 
Viết chương trình thực hiện những công việc sau: - 
Nhập danh sách các sinh viên cho một lớp học. - - - - - - 
Xuất danh sách sinh viên ra màn hình. 
Tìm sinh viên có điểm trung bình cao nhất. 
Sắp xếp danh sách lớp theo thứ tự tăng dần của điểm trung bình. 
Tìm kiếm và in ra các sinh viên có điểm trung bình lớn hơn 5 và không có môn nào dưới 3. 
Tìm sinh viên có tuổi lớn nhất.  
Nhập vào mã sinh viên. Tìm và in ra các thông tin liên quan đến sinh viên đó (nếu có). */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")

struct SinhVien
{
    int maSinhVien;
    char ten[20];
    int namSinh;
    float toan;
    float ly;
    float hoa;

    float diemTB (){
        return (toan + ly + hoa)/3;
    }

};

void Input(int *x){
    scanf("%d", x);
}
void Input(float *x){
    scanf("%f", x);
}
void Input(SinhVien *sv){
    printf("ma sinh vien: ");
    Input(&sv->maSinhVien);

    printf("ten: ");
    fflush(stdin);
    gets(sv->ten);

    printf("nam sinh: ");
    Input(&sv->namSinh);

    printf("diem toan: ");
    Input(&sv->toan);

    printf("diem ly: ");
    Input(&sv->ly);
    
    printf("diem hoa: ");
    Input(&sv->hoa);
}



void Input (SinhVien **sv, int n){
    *sv = (SinhVien*) malloc(n * sizeof(SinhVien));

    for (int i = 0; i < n; i++)
    {
        Input(*sv + i);
        endl;
    }
}

void Output(SinhVien sv){
    printf("%10d|%10s|%10d|%10.2f|%10.2f|%10.2f|%10.2f\n",sv.maSinhVien, sv.ten, sv.namSinh, sv.toan, sv.ly, sv.hoa, sv.diemTB());
}

void Output(SinhVien *sv, int n){
    for (int i = 0; i < n; i++)
    {
        Output(*(sv + i));
    }
    endl;
}

float TimMax(SinhVien *sv, int n){
    float max = sv[0].diemTB();
    for (int i = 1; i < n; i++)
    {
        
        if (max < sv[i].diemTB())
        {
            max = sv[i].diemTB();
        }
    }
    return max;
}

float TimMin(SinhVien *sv, int n){
    int min = sv[0].namSinh;
    for (int i = 1; i < n; i++)
    {
        
        if (min > sv[i].namSinh)
        {
            min = sv[i].namSinh;
        }
    }
    return min;
}
//Tìm sinh viên có điểm trung bình cao nhất. 
SinhVien *SinhVienDiemTBCao (SinhVien *sv, int n, int *count){
    SinhVien *list = (SinhVien*) malloc(n * sizeof(SinhVien));
    *count = 0;
    float max = TimMax(sv, n);
    for (int i = 0; i < n; i++)
    {
        if (max == sv[i].diemTB()){
            list[*count] = sv[i];
            (*count) ++;
        }
    }
    return list;
}  

//Sắp xếp danh sách lớp theo thứ tự tăng dần của điểm trung bình. 
void Sort (SinhVien *sv, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sv[i].diemTB() > sv[j].diemTB())
            {
                SinhVien tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;
            }
        }
    }
}
//Tìm kiếm và in ra các sinh viên có điểm trung bình lớn hơn 5 và không có môn nào dưới 3. 
SinhVien *SvDuoi5VaKoDuoi3 (SinhVien *sv, int n, int *count){
    SinhVien *list = (SinhVien*) malloc(n * sizeof(SinhVien));
    *count = 0;

    for (int i = 0; i < n; i++)
    {
        if ((sv + i)->diemTB() > 5 && (sv + i)->toan >= 3 && (sv + i)->ly >= 3 && (sv + i)->hoa >= 3)
        {
            *(list + *count) = *(sv + i);
            (*count)++;
        }
    }
    
    return list;
}

//Tìm sinh viên có tuổi lớn nhất.
SinhVien *SvLonTuoiNhat(SinhVien *sv, int n, int *count){
    SinhVien *list = (SinhVien*) malloc(n * sizeof(SinhVien));
    *count = 0;
    int tuoiLonNhat = TimMin(sv, n);
    for (int i = 0; i < n; i++)
    {
        if (tuoiLonNhat == (sv + i)->namSinh)
        {
            *(list + *count) = *(sv + i);
            (*count)++;
        }
    }
    return list;
}

//Nhập vào mã sinh viên. Tìm và in ra các thông tin liên quan đến sinh viên đó (nếu có). 
int TimSv(SinhVien *sv, int n, int maSv){
    for (int i = 0; i < n; i++)
    {
        if((sv + i)->maSinhVien == maSv)
        return i;
    }
    return -1;
}

int main()
{
    int n;
    printf("nhap so sinh vien can quan ly: ");
    Input(&n);

    printf("nhap thong tin cho cac sinh vien:\n");
    SinhVien *sv;
    Input(&sv, n);

    printf("danh sach sinh vien ban vua nhap la:\n");
    Output(sv, n);

    //Tìm sinh viên có điểm trung bình cao nhất. 
    int soSVDiemCao;
    SinhVien *svDiemCao = SinhVienDiemTBCao(sv, n, &soSVDiemCao);
    printf("danh sach sinh vien co diem truong binh cao nhat:\n");
    Output(svDiemCao, soSVDiemCao);

    //Sắp xếp danh sách lớp theo thứ tự tăng dần của điểm trung bình. 
    Sort(sv, n);
    printf("danh sach sinh vien sau khi xap xep theo diem trung binh:\n");
    Output(sv, n);
    endl;

    //Tìm kiếm và in ra các sinh viên có điểm trung bình lớn hơn 5 và không có môn nào dưới 3.
    int soSvQuaMon;
    SinhVien *sinhVienQuaMon = SvDuoi5VaKoDuoi3(sv, n, &soSvQuaMon);
    if (soSvQuaMon)
    {
        printf("danh sach sinh vien diemTb > 5 va ko mon nao duoi 3:\n");
        Output(sinhVienQuaMon, soSvQuaMon);
        endl;
    }
    else
        printf("khong co isnh vien nao qua mon.\n\n");
    
    
    
    
    
    //tìm sinh viên lơn tuổi nhất
    int soSvLonTuoi;
    SinhVien *sinhVienLonTuoiNhat = SvLonTuoiNhat(sv, n, &soSvLonTuoi);
    printf("danh sach sinh vien lon tuoi nhat:\n");
    Output(sinhVienLonTuoiNhat, soSvLonTuoi);
    endl;

    //Nhập vào mã sinh viên. Tìm và in ra các thông tin liên quan đến sinh viên đó (nếu có).
    printf("nhap ma sinh vien ban muon tim: ");
    int maSv;
    Input(&maSv);
    int indexSvTimDuoc = TimSv(sv, n, maSv);
    if (indexSvTimDuoc == -1)
        printf("khong co sinh vien nay.\n\n");
    else{
        printf("day la thong sinh sinh vien tim duoc:\n");
        Output(*(sv + indexSvTimDuoc));
    }
        
    


    free(sinhVienLonTuoiNhat);
    free(sinhVienQuaMon);
    free(sv);
    free(svDiemCao);
    return 0;
}
