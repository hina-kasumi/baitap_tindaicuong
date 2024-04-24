/*Câu 4. Xây dựng cấu trúc MatHang (Mặt hàng) có các thuộc tính :
Mã hàng (kiểu chuỗi), Đơn giá, số lượng (kiểu nguyên), ngày bán (kiểu chuỗi);
Viết hàm main() thực hiện các yêu cầu:
	Nhập m mặt hàng
	Đếm số mặt hàng có số lượng lớn hơn 10.
	Tìm các mặt hàng có số lượng ít nhất
	Có bao nhiêu mặt hàng có đơn giá lơn hơn 100
	Tính số tiền bán được trong một ngày cho trước.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n")

struct MatHang
{
    char code[20];
    int howMuch;
    int howMany;
    char date[11];
};

//hàm nhập cho một biến
void Input(int *x){
    scanf("%d",x);
}

//hàm nhập cho một biến có kiểu dữ liệu mặt hàng
void Input(MatHang *good){
    //mã hàng
    printf("ma hang: ");
    fflush(stdin);
    gets(good->code);

    //giá
    printf("gia: ");
    scanf("%d", &good->howMuch);

    //số lượng
    printf("so luong: ");
    scanf("%d", &good->howMany);
    
    // ngày bán
    printf("ngay ban: ");
    fflush(stdin);
    gets(good->date);

    endl;
}

//nhập thông tin cho danh sách các mặt hàng
void Input(MatHang *goods, int n){
    printf("nhap thong tin cho %d mat hang:\n", n);
    for (int i = 0; i < n; i++)
    {
        Input(goods + i);
    }
    
}

//in ra một biến có kiểu dữ liệu Hàng hóa
void Output(MatHang good){
    printf("%10s|%10d|%10d|%10s\n", good.code, good.howMuch, good.howMany, good.date);
}

//in ra một danh sách mặt hàng
void Output(MatHang *goods, int n){
    for (int i = 0; i < n; i++)
    {
        Output(*(goods + i));
    }
    endl;
}

//đếm số mặt hàng số lượng lớn hơn 10
int CountSL (MatHang *goods, int n, int dk){
    //tạo một biến để đếm có phần tử thỏa mãn không
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if((goods + i)->howMany >= dk){
            count++;
        }
    }
    return count;
}

//Tìm các mặt hàng có số lượng ít nhất
//tìm số lượng ít nhất
int Min(MatHang *soLuong, int n){
    int min = soLuong->howMany;
    for (int i = 0; i < n; i++)
    {
        if (min > (soLuong + i)->howMany)
        {
            min = (soLuong + i)->howMany;
        }
        
    }
    return min;
}

//tìm những mặt hàng có số lượng ít nhất
MatHang *ListMin(MatHang *goods, int n, int *count){
    int min = Min(goods, n);
    (*count) = 0;
    //tạo một mảng động để lưu danh sách hàng cần tìn
    MatHang *List = (MatHang*) malloc(n * sizeof(MatHang));

    for (int i = 0; i < n; i++)
    {
        if ((goods +i)->howMany == min)
        {
            *(List + *count) = *(goods + i);
            (*count) ++;
        }
    }
    return List;
}

//đếm số mặt hàng có đơn giá >100
int CountGIA (MatHang *goods, int n, int dk){
    //tạo một biến để đếm có phần tử thỏa mãn không
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if((goods + i)->howMuch > dk){
            count++;
        }
    }
    return count;
}

//nhập ngày bán
void Input(char *ngay){
    fflush(stdin);
    gets(ngay);
}

//Tính số tiền bán được trong một ngày cho trước.
int MoneyEarned(MatHang *goods, int n){
    //nhập
    char ngay[11];
    printf("nhap ngay muon tinh: ");
    Input(ngay);

    int result = 0;
    //tính
    for (int i = 0; i < n; i++)
    {
        if(!strcmp((goods + i)->date, ngay))
            result += (goods + i)->howMuch;
    }
    return result;
}




int main()
{
    //nhap n
    int n;
    back: printf("nhap so mat hang can quan ly: ");
    Input(&n);
    if (n < 1)
    {
        printf("vui long nhap lai.\n");
        goto back;
    }
    
    //khai báo con trỏ có kiểu dữ liệu Mặt Hàng
    MatHang *goods;
    goods = (MatHang*) malloc(n * sizeof(MatHang));

    //nhập thông tin cho danh sách mặt hàng
    Input(goods, n);

    //in ra danh sách các mặt hàng vừa nhập
    printf("danh sach mat hang:\n");
    Output(goods, n);

    //Đếm số mặt hàng có số lượng lớn hơn 10.
    int count = CountSL(goods, n, 10);

    if (count)
        printf("co %d mat hang co so luong >= 10.\n\n", count);
    else
        printf("khong co mat hang co so luong >= 10.\n\n");


    //Tìm các mặt hàng có số lượng ít nhất
    MatHang *List = ListMin(goods, n, &count);
    printf("danh sach mat hang co so luong it nhat:\n");
    Output(List, count);

    //giải phóng bộ nhớ
    free(List);

    //Có bao nhiêu mặt hàng có đơn giá lơn hơn 100
    count = CountGIA(goods, n, 100);
    printf("co %d mat hang don gia tren 100.\n\n", count);

    //Tính số tiền bán được trong một ngày cho trước.
    count = MoneyEarned(goods, n);
    printf("ngay do ban kiem dc: %d dong",count);
    

    //giải phóng bộ nhớ
    free(goods);
    return 0;
}
