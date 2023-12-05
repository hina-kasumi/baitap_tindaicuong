/*9. Viết chương trình giải phương trình bậc 2: ax2 + bx + c = 0 (a, b, c nhập từ bàn phím). Xét tất cả các 
trường hợp có thể.*/
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;
    printf("Nhap cac he so a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) printf("Phuong trinh vo so nghiem");
            else printf("Phuong trinh vo nghiem");
        }
        else
        {
            x1 = -c / b;
            printf("Phuong trinh co nghiem duy nhat: x = %f", x1);
        }
    }
    else
    {
        if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co hai nghiem phan biet: x1 = %f va x2 = %f", x1, x2);
        }
        else if (delta == 0)
        {
            x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep: x1 = x2 = %f", x1);
        }
        else printf("Phuong trinh vo nghiem");
    }
}