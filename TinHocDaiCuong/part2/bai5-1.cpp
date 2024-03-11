/*1. Cho ma trận A các số thực gồm có m hàng, n cột. Hãy viết chương trình nhập giá trị các phần tử cho 
ma trận và in ma trận A ra màn hình. Hãy tính tổng các số dương trong ma trận các số thực và Tính tích 
các giá trị lẻ trong ma trận, in các giá trị tính được ra màn hình*/
#include<stdio.h>
int main()
{
    int m,n,tong_duong=0,tich_le=1;
    printf("nhap kich co ma tran: ");
    scanf("%d%d",&m,&n);
    int matrix[m][n];
    printf("nhap gia tri cho cac phan tu trong ma tran: ");
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            scanf("%d",&matrix[hang][cot]);
        }
    }
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if (matrix[hang][cot]>0) tong_duong+=matrix[hang][cot];
            if (matrix[hang][cot]%2==1) tich_le*=matrix[hang][cot];
        }
    }
    printf("cac tong cac gia tri duong trong ma tran la: %d\n",tong_duong);
    printf("tich cac gia tri le trong day la: %d",tich_le);
    return 0;
}
