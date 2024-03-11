/*6. Cho ma trận A các số thực gồm có m hàng, n cột. Hãy viết chương trình nhập giá trị các phần tử cho 
ma trận và in ma trận A ra màn hình. Hãy tính giá trị lớn nhất và giá trị nhỏ nhất trong ma trận, có bao 
nhiêu phần tử trong ma trận có giá trị lớn nhất và có bao nhiêu phần tử trong ma trận có giá trị nhỏ nhất. 
In các giá trị tính được ra màn hình.*/
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
    //tim max min trong matrix.
    int max=matrix[0][0],min=matrix[0][0],dem_max=0,dem_min=0;
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if(max<matrix[hang][cot]) max=matrix[hang][cot];
            if(min>matrix[hang][cot]) min=matrix[hang][cot];
        }
    }
    printf("gia tri lon nhat trong ma tran = %d\n",max);
    printf("gia tri nho nhat trong ma tran = %d\n",min);
    //co bao nhieu phan tu co gia tri lon nhat va nho nhat.
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if(max==matrix[hang][cot]) dem_max++;
            if(min==matrix[hang][cot]) dem_min++;
        }
    }
    printf("co %d phan tu co gia tri la gia tri lon nhat.\n",dem_max);
    printf("co %d phan tu co gia tri la gia tri nho nhat.\n",dem_min);
}