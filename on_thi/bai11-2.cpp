/*Câu 2: Nhập, xuất vào một ma trận thực cấp mxn, thực hiện các yêu cầu sau:
- Tìm giá trị lớn nhất của ma trận, cho biết các giá trị đó nằm ở cột nào.
- Tính tổng các phần tử dương của từng hàng, cho biết hàng nào có tổng lớn nhất.
- Tính tích các giá trị dương của ma trận*/
#include<stdio.h>
#define nn printf("\n");

double tong (int n,double matrix[][1000],int hang)
{
    double tinh=0;
    for (int cot = 0; cot < n; cot++)
    {
        if(matrix[hang][cot]>0) tinh+=matrix[hang][cot];
    }
    return tinh;
}

int main()
{
    int m,n;
    back: printf("nhap kich co cua ma tran: ");
    scanf("%d%d",&m,&n);
    if (n<1 || m<1) goto back;
    double matrix[m][1000],max=0;
    printf("nhap gia tri cho cac phan tu trong ma tran:\n");
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            scanf("%lf",&matrix[hang][cot]);
        }
    }
    max=matrix[0][0];
	double tich=1;
    int dir_hang,dir_cot;
    //0,
    printf("ma tran ban vua nhap la:\n");
    for (int hang = 0; hang < m; hang++)
    {
        for (int cot = 0; cot < n; cot++)
        {
            printf("%.2lf ",matrix[hang][cot]);
            if(max<matrix[hang][cot])
            {
                max=matrix[hang][cot];
                dir_hang=hang+1;
                dir_cot=cot+1;
            }
            if(matrix[hang][cot]>0) tich*=matrix[hang][cot];
        }
        nn;
    }
    //1,
    nn;
    printf("%.2lf la gia tri lon nhat cua ma tran nam o hang %d, cot %d\n", max, dir_hang, dir_cot);
    //2,
    int tinh,dir=0;
    for (int i = 0; i < n; i++)
    {
        max+=matrix[0][i];
    }
    for (int hang = 0; hang < m; hang++)
    {
        tinh=0;
        printf("tong cac gia tri duong o hang %d = %.2lf\n",hang+1,tong(n,matrix,hang));
        for (int cot = 0; cot < n; cot++) tinh+=matrix[hang][cot];
        if (max<tinh)
        {
            max=tinh;
            dir=hang;
        }
    }
    nn;
    printf("hang %d la hang co tong lon nhat.",dir+1);
    //3,
    printf("\ntich cac gia tri duong co trong ma tran = %.2lf",tich);
    return 0;
}
