/*8. Cho ma trận vuông A các số nguyên gồm có n hàng, n cột. Hãy viết chương trình nhập giá trị các phần 
tử cho ma trận và in ma trận A ra màn hình. Hãy tính tổng các phần tử nằm trên đường chéo chính và hãy 
cho biết phần tử có giá trị lớn nhất trong ma trận. In các giá trị tính được ra màn hình.*/
#include<stdio.h>
int main()
{
    //nhap
    int m,n;
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
    //tim max trong matrix.
    int max=matrix[0][0],min=matrix[0][0];
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if(max<matrix[hang][cot]) max=matrix[hang][cot];
        }
    }
    printf("gia tri lon nhat trong ma tran = %d\n",max);
    //tong tren duong cheo chinh
    int tong=0;
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if(hang==cot) tong+=matrix[hang][hang];
        }
    }
    printf("tong tren duong cheo chinh = %d",tong);
    return 0;
}
