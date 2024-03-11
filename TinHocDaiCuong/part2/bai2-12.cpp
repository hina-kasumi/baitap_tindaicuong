/*12. Viết chương trình nhập vào điểm 3 môn thi: Toán, Lý, Hóa của học sinh. Nếu tổng điểm >= 15 và 
không có môn nào dưới 4 thì in kết quả đậu. Nếu đậu mà các môn đều lớn hơn 5 thì in ra lời phê "Học 
đều các môn", ngược lại in ra "Học chưa đều các môn", các trường hợp khác là "Thi hỏng"*/
#include<stdio.h>
int main()
{
    float toan,ly,hoa,tong_diem;
    back: printf("nhap diem 3 mon toan ly hoa: ");
    scanf("%f%f%f",&toan,&ly,&hoa);
    if(toan<0 || ly<0 || hoa<0) goto back;
    tong_diem=toan+ly+hoa;
    if (tong_diem>=15)
    {
        if (toan>=5 && ly>=5 && hoa>=5)printf("hoc deu tat ca cac mon.");
        else if (toan>=4 && ly>=4 && hoa>=4)printf("dau.");
        else printf("chua hoc deu tat ca cac mon.");
    }
    else printf("thi hong.");
    return 0;
}
