/*Câu 2: Nhập, xuất vào một ma trận nguyên cấp mxn, thực hiện các yêu cầu sau:
- Tính tổng các phần tử nằm trên cột có chỉ số chẵn
- Kiểm tra ma trận có phải là ma trận tam giác trên hay không
- Tính tổng từng hàng của ma trận*/
#include<stdio.h>
#include<math.h>
#define nn printf("\n");

int main()
{
    int m,n;
    do
    {
        printf("nhap kich co cua ma tran: ");
        scanf("%d%d",&m,&n);
    } while (m<1 || n<1);
    int matrix[m][n];
    printf("nhap gia tri cho cac phan tu trong ma tran:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int dem=0;
    printf("ma tran ban vua nhap la:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",matrix[i][j]);
            if(matrix[i][j]==0) dem++;
        }
        nn;
    }
    if  (m!=n)
    {
        printf("\nday khong ma tran tam giac tren.\n");
        goto skip;
    }
    
    for (int hang = 1; hang < m; hang++)
    {
        for (int cot = 0; cot < hang; cot++)
        {
            if (matrix[hang][cot]!=0 || dem==m*n)
            {
                printf("\nday khong ma tran tam giac tren.\n");
                goto skip;
            }
        }
    }
    printf("\nday la ma tran tam giac tren.\n");
    //3,
    skip: printf("tong tung hang cua ma tran.\n");
    int tong;
    for (int hang = 0; hang < m; hang++)
    {
        tong=0;
        for (int cot = 0; cot < n; cot++)
        {
            tong+=matrix[hang][cot];
        }
        printf("hang %d co tong = %d\n",hang+1,tong);
    }
    return 0;
}
