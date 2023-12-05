/*7. Nhập vào ngày, tháng, năm. Kiểm tra xem ngày, tháng, năm đó có hợp lệ không? In kết quả ra màn 
hình.*/
#include<stdio.h>
void show(short day, short month, short thang2)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day <= 30 ) printf("hop le.");
        else printf("khong hop le.");
    }
    else if (month == 2)
    {
        if (day <= thang2) printf("hop le.");
        else printf("khong hop le.");
    }
    else
    {
        if (day <= 31) printf("hop le.");
        else printf("khong hop le.");    
    }
}
int main()
{
    //nhap ngay thang nam
    short day,month, year;
    printf("nhap ngay thang nam: ");
    scanf("%hd%hd%hd", &day ,&month, &year);
    //kiem tra xem ngay thang nam co thoa man khong
    if (year<1 || month<1 || day<1 || month>12 || day>31) printf("khong hop le.");
    else if(year%4==0) show(day,month,29);
    else if(year%4!=0) show(day,month,28);
    return 0;
}
