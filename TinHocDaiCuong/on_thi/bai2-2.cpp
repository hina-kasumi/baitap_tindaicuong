/*Câu 2: Định nghĩa một cấu trúc Sách gồm các thành phần: Mã sách, tên sách, tên tác giả, 
giá tiền. Nhập, xuất n cuốn sách.
- Nhâp vào tên một tác giả, in ra màn hình những cuốn sách của tác giả đó.
- Cho biết cuốn sách nào đắt nhất.
- Đếm những cuốn sách có giá lớn hơn 100.*/
#include<stdio.h>
#include<string.h>
struct sach
{
    char name[50],tac_gia[50];
    int ma_sach,gia;
};
void in(sach book[],int i)
{
    printf("ma sach: %d\n",&book[i].ma_sach);
    printf("ten sach: %s \n",book[i].name);
    printf("ten tac gia: %s\n",book[i].tac_gia);
    printf("gia tien: %d\n\n",book[i].gia);
}
int main()
{
    int n;
    back: printf("nhap so sach muon quan ly: ");
    scanf("%d",&n);
    if(n<1) goto back;
    sach book[n];
    int dat_nhat=0,dir;
    //nhap thông tin cho cuốn sách
    for (int i = 0; i < n; i++)
    {
        printf("nhap thong tin cho cuon sach thu %d\n",i+1);
        printf("nhap ma sach: ");
        scanf("%d",&book[i].ma_sach);
        printf("nhap ten sach: ");
        fflush(stdin);
        gets(book[i].name);
        printf("nhap ten tac gia: ");
        fflush(stdin);
        gets(book[i].tac_gia);
        printf("nhap gia tien: ");
        scanf("%d",&book[i].gia);
        if(dat_nhat<book[i].gia) 
        {
            dat_nhat=book[i].gia;
            dir=i;
        }
    }
    //nhâp tên tác giả và tìm thông tin
    printf("nhap ten tac gia ban muon tim: ");
    char tim_tac_gia[50];
    fflush(stdin);
    gets(tim_tac_gia);
    printf("nhung cuon sach cua tac gia %s la:\n",tim_tac_gia);
    for (int i = 0; i < n; i++)
    {
        if (!stricmp(tim_tac_gia,book[i].tac_gia))
        {
            in(book,i);
        }
    }
    //b,
    printf("cuon sach co gia dat nhat la:\n");
    in(book,dir);
    //c,
    printf("cuon sach co gia lon hon 100 la: \n");
    for (int i = 0; i < n; i++)
    {
        if (book[i].gia>100)
        {
            in(book,i);
        }
    }
    
    return 0;
}
