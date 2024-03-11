/*Câu 2: Nhập một ma trận vuông kiểu số nguyên cấp n, thực hiện các yêu cầu sau:
- Đếm số phần tử chẵn có trong ma trận
- Tính trung bình cộng các phần tử nằm trên đường chéo chính (thuộc)
- Tìm giá trị lớn nhất của ma trận, cho biết vị trí của các phần tử đó.*/
#include<stdio.h>

int main()
{
    int n,dem=0;
    float avergae=0;
    printf("nhap bac cua ma tran vuong: ");
    scanf("%d",&n);
    int matrix[n][n];
    printf("nhap gia tri cho cac phan tu trong ma tran: \n");
    for (int hang = 0; hang < n; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            scanf("%d",&matrix[hang][cot]);
            if(!(matrix[hang][cot]%2)) dem++;
        }
    }
    //1,
    printf("so phan tu chan cos torng ma tran = %d\n",dem);
    //2,
    for (int i = 0; i < n; i++)
    {
        avergae+=matrix[i][i];
    }
    printf("gia tri trung binh duong cheo chinh cua ma tran = %f\n",avergae/n);
    //3,
    int max=matrix[0][0],dir_hang=1,dir_cot=1;
    for (int hang = 0; hang < n; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            if (max<matrix[hang][cot])
            {
                max=matrix[hang][cot];
                dir_hang=hang+1;
                dir_cot=cot+1;
            }
        }
    }
    printf("gia tri lon nhat trong ma tran = %d, o hang %d, cot %d",max,dir_hang,dir_cot);
    return 0;
}
