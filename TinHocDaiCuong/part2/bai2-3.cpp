//3 Viết chương trình nhập vào 4 số thực a, b, c, d. Tìm và in ra số lớn nhất trong 4 số đó
#include<stdio.h>
int main()
{
    float a, b, c, d;
    scanf("%f%f%f%f", &a, &b, &c, &d);
    float max=(a<b)? b:a;
    max =(max<c)? c:max;
    printf("%f",((max<d)? d:max));
    return 0;
}
