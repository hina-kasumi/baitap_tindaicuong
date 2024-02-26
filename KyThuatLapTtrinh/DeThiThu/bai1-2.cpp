/*
Câu 2: Nhập, xuất vào một ma trận thực cấp mxn, thực hiện các yêu cầu sau:
- Tính tổng các phần tử thuộc cột lẻ của ma trận.
- Tính trung bình cộng các phần tử chẵn lớn hơn 10 trong ma trận.
- Tìm giá trị lớn nhất của ma trận
*/
#include <stdio.h>
#include<math.h>
#define endl printf("\n");


int main() {
    int m,n;
    back: printf("nhap kich co cua ma tran: ");
    scanf("%d%d",&m,&n);
    if(m<1 || n<1)
    {
        printf("vui long nhap lai.\n");
        goto back;
    }
    float matrix[m][n];
    printf("nhap gia tri cho cac phan tu trong ma tran:\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%f",&matrix[i][j]);
        }
    }
    printf("ma tran ban vua nhap la:\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%.2f ",matrix[i][j]);
        }
        endl;
    }
    //1,
    for(int cot = 0; cot < n; cot+=2)
    {
        float total = 0;
        for(int hang = 0; hang < m; hang++)
        {
            total+= matrix[hang][cot];
        }
        printf("tong cac phan tu cua cot %d la: %f\n", cot+1, total);
    }
    endl;
    //2,
    float total = 0;
    int count = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int Check = matrix[i][j];
            if(Check == matrix[i][j] && Check % 2 == 0 &&  Check > 10)
            {
                total += matrix[i][j];
                count++;
            }
        }
    }
    if(count) printf("trung binh cong cac so chan lon hon 10 = %f\n", total/count);
    else printf("khong co gia tri chan nao lon hon 10.\n");
    endl;
    //3,
    float max = matrix[0][0];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            max = (max < matrix[i][j])? matrix[i][j]:max;
        }
    }
    printf("gia tri lon nhat torng ma tran la: %f", max);
    return 0;
}