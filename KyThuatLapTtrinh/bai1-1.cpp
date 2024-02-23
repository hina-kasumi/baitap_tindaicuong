/*Câu 1: Nhập, xuất vào một dãy có n điểm, thực hiện các yêu cầu sau: 
- Tính độ dài đường gấp khúc đi qua tất cả các điểm. 
- Nhập bán kính R, đếm và in ra màn hình các điểm nằm phía trong đường tròn tâm O, bán kính R. 
- Tìm diện tích hình tròn tâm O nhỏ nhất chứa tất cả các điểm.*/

#include<stdio.h>
#include<math.h>
#define endl printf("\n");
const float PI = 3.14;

void Output(float x, float y)
{
    printf("(%f,%f)\n",x, y);
}

int main()
{
    int n;
    printf("nhap si diem muon toa: ");
    scanf("%d",&n);


    float x[n], y[n];
    printf("nhap toa do cac diem\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f",&x[i], &y[i]);
    }

    printf("cac diem ban vua nhap la: \n");
    for (int i = 0; i < n; i++)
    {
        Output(x[i], y[i]);
    }
    endl;

    //1,
    printf("do dai tung doan gap khuc la:\n");
    for (int i = 0; i < n-1; i++)
    {
        float do_dai = sqrt(pow(x[i+1] - x[i], 2) + pow(y[i+1] - y[i], 2));
        printf("%f\n",do_dai);
    }
    endl;

    //2,
    float R, max = 0;
    int count = 0;
    printf("nhap ban kinh cho duong tron tam O: ");
    scanf("%f",&R);
    for (int i = 0; i < n; i++)
    {
        float khoang_cach = sqrt(pow(x[i], 2)+ pow(y[i], 2));
        if (khoang_cach < R)
        {
            count++;
            Output(x[i], y[i]);
        }
        max = (max < khoang_cach)? khoang_cach:max;
    }
    printf("co %d diem nam trong duong tron tamO ban kinh %f\n\n", count, R);
    //3,
    printf("dien tich duong tron nho nhat chua toan bo diem = %f", PI * max * max);


    return 0;
}
