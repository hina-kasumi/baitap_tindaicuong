/*Câu 2: Nhập, xuất vào một ma trận thực cấp mxn, thực hiện các yêu cầu sau:
- Kiểm tra xem ma trận có đối xứng qua đường chéo chính hay không.
- Tìm giá trị lớn nhất của từng hàng.
- Tính trung bình cộng các giá trị dương của ma trận.*/
#include<stdio.h>
void in(float matrix[][1000],int hang,int cot)
{
    printf("%f ",matrix[hang][cot]);
}
bool test(float matrix[][1000],int m)
{
    for (int hang = 0; hang < m; hang++)
        {
            for (int cot = 0; cot <= hang; cot++)
            {
                if (matrix[hang][cot]!=matrix[cot][hang])
                {
                    return 0;
                }
            }
        }
    return 1;
}
int main()
{
    int m,n;
    printf("nhap kich co cua ma tran: ");
    scanf("%d%d",&m,&n);
    float matrix[m][1000];
    printf("nhap gia tri cho cac phan tu trong ma tran.\n");
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            scanf("%f",&matrix[hang][cot]);
        }
    }
    printf("ma tran ban vua nhap la.\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in(matrix,i,j);
        }
    }
    //1,
    if(m==n)
    {
        if (test(matrix,m)) printf("\nday la m tran doi xung.\n");
        else printf("\nday khong phai ma tran doi xung.\n");
    }
    else printf("\nday khong phai la ma tran doi xung.\n");
    
    return 0;
}
