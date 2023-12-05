/*13. Nhập vào một số nguyên dương là một năm, kiểm tra năm đó có phải năm nhuận hay không? Thuật 
toán: năm nhuận là năm chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100*/
#include<stdio.h>
int main()
{
    int year;
    back: printf("nhap nam muon kiem tra: ");
    scanf("%d",&year);
    if(year<1) goto back;
    if (year%400==0 || (year%4==0 && year%100!=0)) printf("day la nam nhuan.");
    else printf("day khong phai nam nhuan.");
    return 0;
}
