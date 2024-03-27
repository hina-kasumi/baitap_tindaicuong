/*viết hàm cấu trúc MatHang có các thành phần Mã hàng(kiểu chuỗi), đơn giá(long); và các hàm khác
xây dựng cấu truc HoaDon (hóa đơn bán hàng) có các thành phần:
mã hàng(String), số lượng(int), ngày bán(String); hàm nhập và các hàm khác
1, nhập m mặt hàng
2, nhập n hóa đơn (giả thiết mã hàng của mỗi hóa đơn đều có trong m mặt hàng đã nhập)
3, đếm số hóa đớn có số lượng lớn hơn 10
4, tìm số tiền bán được trong 1 ngày cho trước*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

void Input (int *x){
    scanf("%d", x);
}

struct MatHang
{
    char maHang[20];
    long price;
    HoaDon hoaDon;
    
};

struct HoaDon
{
    char maHang[20];
    int soLuong;
    char ngayBan[11];
};

void InputMatHang(MatHang *goods, int m){
    for (int i = 0; i < m; i++)
    {
        printf("ma hang: ");
        fflush(stdin);
        gets((goods + i)->maHang);

        printf("gia: ");
        scanf("%ld", &(goods + i)->price);
        endl;
    }
}

void OutputMatHang(MatHang good){
    printf("%10s|%10ld\n", good.maHang, good.price);
}

void OutputMatHang(MatHang *goods, int m){
    for (int i = 0; i < m; i++)
        OutputMatHang(*(goods + i));
}

void InputHoaDon(HoaDon *hoaDon, int n){
    for (int i = 0; i < n; i++)
    {
        printf("ma hang: ");
        fflush(stdin);
        gets((hoaDon + i)->maHang);

        printf("so luong: ");
        Input(&(hoaDon + i)->soLuong);

        printf("ngay ban: ");
        fflush(stdin);
        gets((hoaDon + i)->ngayBan);
    }
}

void OutputHoaDon(HoaDon hoaDon){
    printf("%10s|%10d|%10s\n", hoaDon.maHang, hoaDon.soLuong, hoaDon.ngayBan);
}

void OutputHoaDon(HoaDon *hoaDon, int n){
    for (int i = 0; i < n; i++)
        OutputHoaDon(*(hoaDon + i));
}

int HoaDonLonHon10 (HoaDon *hoaDon, int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((hoaDon + i)->soLuong > 10)
            count++;
    }
    return count;
}


int NgayKiemTra(HoaDon *hoaDon, int n){
    char ngayKiemTra[11];
    fflush(stdin);
    gets(ngayKiemTra);
    
    int soTienKiemDuoc = 0;

    for (int i = 0; i < n; i++)
    {
        if (!strcmp((hoaDon + i)->ngayBan, ngayKiemTra));
    }
    
}




int main()
{
    //Mặt Hàng
    int m;
    printf("nhap so mat hang can quan ly: ");
    Input(&m);

    MatHang *goods = (MatHang*) malloc(m * sizeof(MatHang));
    printf("nhap thong tin cho mat hang:\n");
    InputMatHang(goods, m);

    printf("danh sach mat hang ban vua nhap la:\n");
    OutputMatHang(goods, m);
    endl;

    //Hoa Đơn
    int n;
    printf("nhap so hoa don can quan ly: ");
    Input(&n);

    HoaDon *hoaDon = (HoaDon*) malloc(n * sizeof(HoaDon));
    printf("nhap thong tin cho hoa don:\n");
    InputHoaDon(hoaDon, n);

    printf("danh sach thong tin hoa don ban vua nhap:\n");
    OutputHoaDon(hoaDon, n);
    endl;


    int soLuongLonHon10 = HoaDonLonHon10(hoaDon, n);
    if (soLuongLonHon10)
        printf("co %d hoa hon co so luong hon hon 10.\n\n", soLuongLonHon10);
    else
        printf("khong co hoa don nao co so luong lon hon 10.\n\n");

    


    free(hoaDon);
    free(goods);
    return 0;
}
