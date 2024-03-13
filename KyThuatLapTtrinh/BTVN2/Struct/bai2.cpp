/*Câu 2. Xây dựng cấu trúc Hàng, gồm các thuộc tính: mã hàng, tên hàng, xuất xứ, loại hàng(1, 2, 3), số lượng, tgbh (thời gian bảo hành, theo tháng).
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
    int ma;
    char ten[20];
    int loai;
    int sl;
    int tgbh;
};

void Intput(Hang *hang){
    printf("nhap ma: ");
    scanf("%d", hang->ma);

    printf("nhap ten: ");
    fflush(stdin);
    gets(hang->ten);
}
void Input(int n, Hang *hang){
    
}

int main()
{
    
    return 0;
}