/*Câu 2. Xây dựng cấu trúc Hàng, gồm các thuộc tính: 
mã hàng, tên hàng, xuất xứ, loại hàng(1, 2, 3), số lượng, tgbh (thời gian bảo hành, theo tháng).
Viết hàm main() để:
	Nhập thông tin cho n mặt hàng điện tử.
	Thống kê tổng số hàng của từng loại hàng mà có thời gian bảo hành từ 12 tháng trở lên.
	Tìm một mặt hàng có tên cho trước.
	Tìm số lượng lớn nhất của mặt hàng loại 2
	Sắp xếp cấu trúc giảm dần theo thời gian bảo hành.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n")

struct Hang
{
    int code;
    char name[20];
    int type;
    int many;
    int baohanh;
};

//hàm nhận cho một biến kiểu số nguyên
void Input (int *x){
    scanf("%d", x);
}

//hàm nhập của một biến có kiểu dữ liệu Hang
void Input(Hang *goods){
    //nhập mã hàng đó
    printf("ma hang: ");
    scanf("%d", &goods->code);

    //nhập tên hàng
    printf("ten hang: ");
    fflush(stdin);
    gets(goods->name);

    //nhập loại hàng
    printf("loai hang: ");
    scanf("%d", &goods->type);

    //nhập số lượng hàng
    printf("so luong: ");
    scanf("%d", &goods->many);

    //nhập thời gian bảo hành
    printf("thoi gian bao hanh: ");
    scanf("%d", &goods->baohanh);
}

//nhập mảng có kiểu dữ liệu hàng
void Input(Hang *goods, int n){
    for (int i = 0; i < n; i++)
    {
        Input(goods + i);
        endl;
    }
}

//in ra thông tin của một biến có kiểu dữ liệu hàng
void Output (Hang good){
    printf("%10d|%10s|%10d|%10d|%10d\n", good.code, good.name, good.type, good.many, good.baohanh);
}

//in ra một danh sách thông tin các mặt hàng đang quan ly
void Output(Hang *goods, int n){
    for (int i = 0; i < n; i++)
    {
        Output(*(goods + i));
    }
    endl;
}

//thống kê những mặt hàng có thời gian bảo hành từ x tháng trở lên
Hang *BaoHanh(Hang *goods, int n, int time, int *count){
    //khai báo một danh sách ảo để truyền dữ liệu cho danh sách
    Hang *baohanh = (Hang*) malloc(n * sizeof(Hang));
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((goods + i)->baohanh >= time)
        {
            *(baohanh + *count) = *(goods + i);
            (*count)++;
        }
    }
    return baohanh;
}

//Tìm một mặt hàng có tên cho trước.
Hang *Find(Hang *gooods, int n, char search[], int *count){
    //khai báo danh sách chứa thông tin tìm được
    Hang *List = (Hang*) malloc(n * sizeof(Hang));

    *count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!strcmpi(search, (gooods + i)->name))
        {
            *(List + *count) = *(gooods + i);
            (*count)++;
        }
    }
    return List;
}

//Tìm số lượng lớn nhất của mặt hàng loại 2
int Max(Hang *good, int n, int loai){
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if ((good + i)->type == loai && (good + i)->many > max)
        {
            max = (good + i)->many;
        }
    }
    return max;
}

//Sắp xếp cấu trúc giảm dần theo thời gian bảo hành.
void Sort(Hang *goods, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((goods + i)->baohanh < (goods + j)->baohanh)
            {
                Hang tmp = *(goods + i);
                *(goods + i) = *(goods + j);
                *(goods + j) = tmp;
            }
        }
    }
}

int main()
{
    //nhập n là số lượng mặt hàng cần quản lý
    int n;
    back: printf("nhap so luong mat hang dien tu can quan ly: ");
    Input(&n);
    if (n < 1)
    {
       printf("vui long nhap lai.\n");
       goto back;
    }
    
    //khai báo con trỏ có kiểu dữ liệu Hang
    Hang *goods = (Hang*) malloc(n * sizeof(Hang));
    printf("nhap thong tin cho hang hoa:\n");
    Input(goods, n);

    //in ra danh sách hàng hóa bạn vừa nhập
    printf("day la danh sach ban vua nhap:\n");
    Output(goods, n);
    

    //1, Thống kê tổng số hàng của từng loại hàng mà có thời gian bảo hành từ 12 tháng trở lên.
    //khai báo danh sách của những hàng có bảo hành từ 12 tháng trở lên
    Hang *baoHanhLau;
    //baoHanhLau = (Hang*) malloc(n * sizeof(Hang));

    //khai báo biến count để đếm xem có bao nhiêu phần tử trong danh sách 12 tháng
    int count;
    baoHanhLau = BaoHanh(goods, n, 12, &count);

    //in ra
    if(count){
        printf("danh sach nhung loai hang co bao hanh >= 12 thang:\n");
        Output(baoHanhLau, count);
    } else {
        printf("khong co hang nao bao hanh >= 12 thang.\n\n");
    }
    

    //giải phóng bộ nhớ
    free(baoHanhLau);

    //2, Tìm một mặt hàng có tên cho trước.
    //nhâp tên cần tìm
    printf("nhap ten mat hang ban muon tim: ");
    char search[20];
    fflush(stdin);
    gets(search);

    //tạo một danh sách có tên trùng với tên tên muốn tìm
    Hang *finded;
    finded = Find(goods, n, search, &count);
    if (count)
    {
        printf("nhung mat hang co ten %s:\n", search);
        Output(finded, count);
    }
    else
        printf("khong tim thay mat hang co ten %s.\n\n",search);
    
    //giải phóng bộ nhớ
    free(finded);
    
    //3,Tìm số lượng lớn nhất của mặt hàng loại 2
    int max = Max(goods, n, 2);
    if (max >= 0)
        printf("so luong lon nhat cua mat hang loai 2 la: %d\n\n", max);
    else
        printf("khong co mat hang loai 2 nao.\n\n");

    //4, Sắp xếp cấu trúc giảm dần theo thời gian bảo hành.
    Sort(goods, n);
    printf("danh sach sau khi xap xep giam dan theo thoi gian bao hanh:\n");
    Output(goods, n);

    //giải phóng bộ nhớ
    free(goods);
    return 0;
}

