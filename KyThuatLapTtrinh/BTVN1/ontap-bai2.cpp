/*đinh nghĩa cấu trúc điểm (x, y, màu)
nhập n điểm và tính độ dài đường gấp khúc
đếm số điểm màu vàng và in ra các điểm đó
tìm điểm đỏ xa gốc toa độ nhất*/

#include<stdio.h>
#include<math.h>
#define endl printf("\n");

struct Point
{
    float x, y;
    int color;
    //0: xanh, 1: do, 2: vang
};

//dem diem mau vang
int Count(Point diem[], int n, int &count)
{
    for (int i = 0; i < n; i++)
    {
        if(diem[i].color == 2) count++;
    }
    return count;
}



int main()
{
    //nhap n
    int n;
    back: printf("nhap so diem co trong mat phang: ");
    scanf("%d%d", &n);
    if ( n<1)
    {
        printf("vui long nhap lai.\n");
        goto back;
    }


    //nhap toa do, mau cua cac diem
    Point diem[n];
    //int color[n];
    printf("nhap toa do va mau cho cac diem:\n");
    for (int i = 0; i < n; i++)
    {
        printf("diem %d", i+1);
        printf("x: "); scanf("%f", &diem[i].x);
        printf("y: "); scanf("%f", &diem[i].y);
        printf("color: "); scanf("%d", &diem[i].color);
        endl;
    }
    

    //dem diem mau vang
    int count = 0;
    if(Count(diem, n, count) > 0) printf("so diem mau vang : %d");
    return 0;
}
