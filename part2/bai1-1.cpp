/*1. Viết chương trình nhập vào một số đo nhiệt độ theo độ F (Fahrenheit) và xuất ra nhiệt độ tương đương
của nó theo độ C (Celsius), sử dụng công thức chuyển đổi: C = (F – 32)*5/9*/
#include<stdio.h>
int main()
{
    int nhiet_do;
    printf("nhiet do F = ");
    scanf("%d",&nhiet_do);
    printf("%d F = %.2f C",nhiet_do,(nhiet_do)*5.0/9);
    return 0;
}
