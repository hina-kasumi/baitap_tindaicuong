/*Bài 6. Mỗi nhân viên là một cấu trúc gồm: Họ tên, Lương và Mã công việc (Giả sử chỉ có 3 mã công việc 
là 1, 2, 3). Hãy viết hàm thực hiện các yêu cầu sau: 
1. Nhập từ bàn phím một danh sách n nhân viên có cấu trúc như trên.  
2. Tính trung bình lương nhân viên theo mã công việc. 
3. Xuất danh sách nhân viên trên ra tệp văn bản theo dạng: dòng đầu là số nhân viên, trên mỗi 
ba dòng tiếp theo là các thông tin của một nhân viên (Họ tên, Lương, Mã công việc). 
4. Tính tổng tiền lương của nhân viên có mã công việc là 2 
5. Công việc nào có nhiều nhân viên tham gia nhất*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

struct NhanVien
{
    char name[20];
    float luong;
    int mcv;
};

void Input(NhanVien **nv, int n){
    *nv = (NhanVien*)malloc(n * sizeof(NhanVien));
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("ten: ");
        gets((*nv + i)->name);

        printf("luong: ");
        scanf("%f", &(*nv + i)->luong);

        printf("ma cong viec: ");
        scanf("%d", &(*nv)[i].mcv);
        endl;
    }
}

void Output(NhanVien nv){
    printf("%10s|%10.3f|%10d\n", nv.name, nv.luong, nv.mcv);
}
void Output(NhanVien *nv, int n){
    if(n == 0)
        return;
    Output(nv, n - 1);
    Output(nv[n - 1]);
}

//2. Tính trung bình lương nhân viên theo mã công việc.
NhanVien *tbLuong(NhanVien *nv, int n, int *cnt){
    NhanVien *list = (NhanVien*) malloc(n * sizeof(NhanVien));
    bool check[n] = {0};
    *cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(!check[i]){
            list[*cnt] = nv[i];
            int tmp = 1;
            for (int j = i + 1; j < n; j++)
            {
                if(list[*cnt].mcv == nv[j].mcv){
                    list[*cnt].luong += nv[j].luong;
                    tmp++;
                    check[j] = true;
                }
            }
            list[*cnt].luong /= tmp;
            (*cnt)++;
        }
    }
    return list;
}

//3. Xuất danh sách nhân viên trên ra tệp văn bản theo dạng: dòng đầu là số nhân viên, trên mỗi 
void Share(NhanVien *nv, int n){
    FILE *out = fopen("DanhSach.txt", "w+");
    fprintf(out, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(out, "%s\n%.3f\n%d\n", nv[i].name, nv[i].luong, nv[i].mcv);
    }
    fclose(out);
}

//4. Tính tổng tiền lương của nhân viên có mã công việc là 2 
float tong(NhanVien *nv, int n, int ma){
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        if (nv[i].mcv == ma){
            res += nv[i].luong;
        }
    }
    return res;
}

int main()
{
    int n;
    printf("nhap so nhan vien: ");
    scanf("%d", &n);
    printf("nhap thong tin cho cac nhan vien:\n");
    NhanVien *nv;
    Input(&nv, n);

    printf("danh sach nhan vien:\n");
    Output(nv, n);

    int cnt;
    NhanVien *list = tbLuong(nv, n, &cnt);
    printf("luong trung binh theo ma cong viec:\n");
    for (int i = 0; i < cnt; i++)
        printf("%d: %.3f\n", list[i].mcv, list[i].luong);

    //3. Xuất danh sách nhân viên trên ra tệp văn bản theo dạng: dòng đầu là số nhân viên, trên mỗi
    printf("thong in da duoc in ra DanhSach.txt.\n");
    Share(nv, n);
    
    printf("so luong cua cx 2 la: %.3f.\n\n",tong(nv, n, 2));
    free(nv);
    free(list);
    return 0;
}
