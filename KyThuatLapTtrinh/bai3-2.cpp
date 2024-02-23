/*u 2: Nhập, xuất vào một ma trận thực cấp mxn, thực hiện các yêu cầu sau:
- Tìm giá trị lớn nhất của ma trận, cho biết các giá trị đó nằm ở cột nào.
- Tính tổng các phần tử dương của từng hàng, cho biết hàng nào có tổng lớn 
nhất.
- Tính tích các giá trị dương của ma trận*/
#include <stdio.h>
#define endl printf("\n")
#define pr printf
#define sc scanf
#define for(i,a,b) for(int i = a; i < b ; i++)

int main() {
    int m,n;
    back: pr("nhap kich co cua ma tran: ");
    sc("%d%d", &m, &n);
    if(m < 1 || n < 1)
    {
        pr("vui long nhap lai.\n");
        goto back;
    }
    pr("nhap gia tri cho cac phan tu trong ma tran\n");
    float matrix[m][n];
    for(i,0,m)
    {
        for(j,0,n)
        {
            sc("%f", &matrix[i][j]);
        }
    }
    pr("ma tran ban vua nhap la:\n");
    for(i,0,m)
    {
        for(j,0,n)
        {
            pr("%.2f ", matrix[i][j]);
        }
        endl;
    }
    endl;
    
    //1,
    int dir_max = 0;
    float max = matrix[0][0];
    for(i,0,m)
    {
        for(j,0,n)
        {
            if(max < matrix[i][j])
            {
                max = matrix[i][j];
                dir_max = j;
            }
        }
    }
    pr("gia tri lon nhat %f nam o cot %d\n\n", max, dir_max+1);
    //2,
    max = 0;
    float tich = 1;
    for(hang,0,m)
    {
        float total = 0;
        for(cot,0,n)
        {
            if(matrix[hang][cot] > 0) 
            {
                total+=matrix[hang][cot];
                tich*=matrix[hang][cot];
            }
        }
        pr("tong cac phan tu duong o hang %d la: %f\n", hang+1, total);
        if(max < total)
        {
            max = total;
            dir_max = hang;
        }
    }
    pr("hang %d co tong cac phan tu duong lon nhat\n\n", ++dir_max);
    //3,
    pr("tich cac phan tu duong trong ma tran = %f", tich);
    
    return 0;
}