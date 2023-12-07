/*2. Cho ma trận A các số thực gồm có m hàng, n cột. Hãy viết chương trình nhập giá trị các phần tử cho 
ma trận và in ma trận A ra màn hình. Hãy tính các giá trị tổng trên mỗi dòng trong ma trận A và Tính tích 
các giá trị dương trên từng cột trong ma trận. In các giá trị tính được ra màn hình.*/
#include<stdio.h>
int main()
{
    //nhap
    int m,n,tong_dong=0, tich_duong=1;
    printf("nhap kich co cua ma tran: ");
    scanf("%d%d",&m,&n);
    int matrix[m][n];
    printf("nhap gia tri cho cac phan tu trong ma tran: ");
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            printf("[%d][%d] = ",hang+1,cot+1);
            scanf("%d",&matrix[hang][cot]);
        }
    }
    //in ma tran
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            printf("%d ",matrix[hang][cot]);
        }
        printf("\n");
    }
    // tong hang
    printf("tong cac gia tri tren tung hang la: ");
    for (int hang = 0; hang < m; hang++)
    {
        tong_dong=0;
        for (int cot = 0; cot < n; cot++)
        {
            tong_dong+=matrix[hang][cot];
        }
        printf("\n%d",tong_dong);
    }
    //tich cot
    printf("\ntich cac gia tri duong tren 1 cot la: ");
    for (int cot = 0; cot < n; cot++)
    {
        tich_duong=1;
        for (int hang = 0; hang < m; hang++)
        {
            if (matrix[hang][cot]>0)
            {
                tich_duong*=matrix[hang][cot];
            }
        }
        printf("\n%d",tich_duong);
    }
    return 0;
}
