/*ma tran nguyen m hang n cot nhap va in ra
- tính trung bình cộng các phần tử chẵn
- tnhs trung bình nhân*/
#include<stdio.h>
#include<math.h>
#define endl printf("\n");

double tinh(int matrix[][(int)1e5], int m, int n, int debai)
{
    double tich = 1;
    double average = 0;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]%2==0)
            {
                average+=1.0*matrix[i][j];
                count++;
            }
            tich*=1.0*matrix[i][j];
        }
    }
    tich = pow(tich, 1.0/(m*n));
    if(debai == 2) return tich;
    else if (debai == 1) return average/count;
    
}

/*
3 4
1 2 3 4 5 1 7 8 9 1 11 9
*/


int main()
{
    //nhap kich c ma tran
    int m, n;
    back: printf("nhap kich co cua ma tran: ");
    scanf("%d%d", &m, &n);
    if (m<1 || n<1)
    {
        printf("vui long nhap lai.\n");
        goto back;
    }
    
    //nhap ma tran
    int matrix[m][(int) 1e5];
    printf("nhap gia tri cho cac phan tu trong ma tran:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    

    //in ma tran
    printf("ma tran ban vua nhap la:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        endl;
    }

    //1, trung binh cong phan tu chan
    printf("trung binh cong cac phan tu chan trong ma tran la: %lf\n\n", tinh(matrix, m, n, 1));

    //2, trung binh tich
    printf("trung binh tich cac phan tu trong ma tran: %lf", tinh(matrix, m, n, 2));

    return 0;
}
