/*8. Viết chương trình nhập điểm thi từ bàn phím và hiển thị kết quả : kém nếu điểm từ 0 đến 3; Yếu nếu 
điểm là 4; Trung bình nếu điểm từ 5 đến 6; Khá nếu điểm từ 7 đến 8; Giỏi nếu điểm từ 9 đến 10.*/
#include<stdio.h>
int main()
{
    short point;
    back: printf("nhap diem thi: ");
    scanf("%hd", &point);
    if(point<0 || point>10)goto back;
    if(point>=0 && point<=3) printf("F");
    if(point==4) printf("D");
    if(point==5 || point==6) printf("C");
    if(point==7 || point==8) printf("B");
    if(point==9 || point==10) printf("A");
    return 0;
}
