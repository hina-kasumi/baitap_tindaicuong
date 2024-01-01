/*Câu 2: Nhập, xuất vào một ma trận vuông kiểu số thực, thực hiện các yêu cầu sau:
- Tính tích các phần tử nằm phía trên đường chéo chính.
- Kiểm tra xem ma trận có phải là ma trận tam giác trên hay không.
- Tính tổng các phần tử thuộc đường chéo phụ*/
#include<stdio.h>
#define nn printf("\n")

float result(float matrix[][1000],int n)
{
    float tong=0;
    for (int i = 0; i < n; i++)
    {
        tong+=matrix[i][n-i-1];
    }
    return tong;
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float matrix[n][1000],tong=0;
    for (int hang = 0; hang < n; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            scanf("%f",&matrix[hang][cot]);
        }
    }
    printf("tong cac gia tri tren duong cheo phu = %f",result(matrix,n));
    return 0;
}