/*Tổ chức dữ liệu để quản lý sinh viên bằng cấu trúc trong một mảng n phần tử, mỗi phần tử có cấu trúc như sau:
    - Mã sinh viên. 
    - Tên. 
    - Năm sinh. 
    - Điểm toán, lý, hoá, điểm trung bình. 

Viết chương trình thực hiện những công việc sau: 

- Nhập danh sách các sinh viên cho một lớp học. 
- Xuất danh sách sinh viên ra màn hình. 
- Tìm sinh viên có điểm trung bình cao nhất. 
- Sắp xếp danh sách lớp theo thứ tự tăng dần của điểm trung bình. 
- Tìm kiếm và in ra các sinh viên có điểm trung bình lớn hơn 5 và không có môn nào dưới 3. 
- Tìm sinh viên có tuổi lớn nhất.  
- Nhập vào mã sinh viên. Tìm và in ra các thông tin liên quan đến sinh viên đó (nếu có).*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n")

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

void Input(SinhVien **sv, int n){
    *sv = (SinhVien*) malloc(n * sizeof(SinhVien));

    for (int i = 0; i < n; i++){
        printf("ma sinh vien: ");
        scanf("%d", &(*sv + i)->maSinhVien);

        printf("ten: ");
        fflush(stdin);
        gets((*sv + i)->ten);

        printf("nam sinh: ");
        scanf("%d", &(*sv + i)->namSinh);

        printf("diem toan: ");
        scanf("%f", &(*sv + i)->toan);

        printf("diem ly: ");
        scanf("%f", &(*sv + i)->ly);

        printf("diem hoa: ");
        scanf("%f", &(*sv + i)->hoa);

        endl;
    }
}

void Output(SinhVien sv){
    printf("%10d|%10s|%10d|%10.2f|%10.2f|%10.2f\n", 
        sv.maSinhVien, 
        sv.ten, 
        sv.namSinh, 
        sv.toan, 
        sv.ly, 
        sv.hoa );
}
void Output(SinhVien *sv, int n){
    if (n == 0)
        return;

    Output(sv, n - 1);
    Output(*(sv + n - 1));
}

void swap(SinhVien *a, SinhVien *b){
    SinhVien x = *a;
    *a = *b;
    *b = x;
}

//3, Tìm sinh viên có điểm trung bình cao nhất.
SinhVien DiemCaoNhat(SinhVien *sv, int n){
    SinhVien max = *sv;
    for (int i = 1; i < n; i++){
        if (max.diemTB() < (sv + i)->diemTB())
            max = *(sv + i);
    }
    return max;
}

//4,Sắp xếp danh sách lớp theo thứ tự tăng dần của điểm trung bình.
int partition(SinhVien *sv, int low, int high){
    float pivot = sv[high].diemTB();
    int i = low - 1;
    for (int j = low; j <= high; j++){
        if (sv[j].diemTB() < pivot){
            i++;
            swap(sv + i, sv + j);
        }
    }
    swap(sv + i + 1, sv + high);
    return i + 1;
}

void QuickSort(SinhVien *sv, int low, int high){
    if(low < high){
        int pi = partition(sv, low, high);
        QuickSort(sv, low, pi - 1);
        QuickSort(sv, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("nhap so sinh vien can quan ly: ");
    scanf("%d", &n);

    SinhVien *sv;
    printf("nhap thong tin cho cac sinh vien:\n");
    Input(&sv, n);

    printf("danh sach sinh vien ban vua nhap la:\n");
    Output(sv, n);

    //3, Tìm sinh viên có điểm trung bình cao nhất.
    printf("\nsinh vien co diem trung binh cao nhat:\n");
    Output(DiemCaoNhat(sv, n));

    //4, Sắp xếp danh sách lớp theo thứ tự tăng dần của điểm trung bình. 
    QuickSort(sv, 0, n - 1);
    printf("\ndanh sach sinh vien sau khi duoc xep theo diem tb:\n");
    Output(sv, n);

    free(sv);
    return 0;
}
