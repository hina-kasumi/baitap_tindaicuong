/*4. Cho ma trận A các số nguyên gồm có m hàng, n cột. Hãy viết chương trình nhập giá trị các phần tử cho 
ma trận và in ma trận A ra màn hình. Hãy cho biết có bao nhiêu phần tử chẵn trong ma trận A có giá trị
nằm trong đoạn [5, 20] và có bao nhiều phần tử lẻ trong ma trận có giá trị nhỏ hơn 100. In các giá trị tính 
được ra màn hình.*/
#include<stdio.h>
int main()
{
    //nhap
    int m,n,chan=0, le=0;
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
    //co bao nhieu phan tu chan trong ma tran trong [5,20]
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if (matrix[hang][cot]%2==0 && matrix[hang][cot]>=5 && matrix[hang][cot]<=20)
            {
                chan++;
            }
        }
    }
    printf("co %d phan tu chan trong ma tran trong [5,20].\n",chan);
    //so phan tu le co gia tri <100
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if (matrix[hang][cot]%2==1 && matrix[hang][cot]<=100)
            {
                le++;
            }
        }
    }
    printf("co %d phan tu le trong ma tran nho hon 100.\n",le);
    return 0;
}
