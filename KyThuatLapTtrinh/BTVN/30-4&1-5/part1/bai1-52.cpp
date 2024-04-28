/*Viết chương trình nhập vào ma trận vuông số nguyên kích thước n.
Thực hiện các yêu cầu sau:
- Tìm giá trị lớn nhất trên đường chéo chính
- Tính giá trị trung bình các phần tử nhỏ hơn giá trị x (x cho trước)
- Tìm dòng có tổng lớn nhất
- Sắp xếp ma trận theo thứ tự tăng dần từ trái sang phải và từ trên xuống dưới  */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

void Input(int ***matrix, int n){
    *matrix = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++){
        *(*matrix + i) = (int*) malloc (n * sizeof(int));
        for (int j = 0; j < n; j++){
               scanf("%d", *(*matrix + i) + j);
        }
    }
}

void Output(int *arr, int n){
    if (n == 0)
        return;
    Output(arr, n - 1);
    printf("%d ", arr [n - 1]);
}

void Output(int **matrix, int m, int n){
    if (m == 0)
       return;

    Output(matrix, m - 1, n);
    Output(*(matrix + m - 1), n);
    endl;
}

//1, tìm giá trị lớn nhất trên đường chéo chính
int Max(int **matrix, int n){
    n--;
    if (n == 0)
        return matrix[n][n];
    
    int max = Max(matrix, n);
    return (matrix[n][n] < max)? max:matrix[n][n];
}

//2, Tính giá trị trung bình các phần tử nhỏ hơn giá trị x (x cho trước)
float tbcLonHonX(int **matrix, int n, int x){
    float tbc = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(matrix[i][j] < x){
                tbc+= (float) matrix[i][j];
                cnt++;
            }
        }
    }
    return tbc / cnt;
}

int Tong(int *arr, int n){
    if (n == 1)
        return arr[0];
    return arr[n - 1] + Tong(arr, n - 1); 
}

int TongLonNhat(int **matrix, int m, int n){
    m--;
    if (m == 0)
        return Tong(*matrix, n);
    
    int max = TongLonNhat(matrix,m, n);
    int giaTri = Tong(matrix[m], n);
    return (max < giaTri)? giaTri:max;
}

int main()
{
    int n;
    printf("nhap kich co ma tran vuong: ");
    scanf("%d", &n);

    int **matrix;
    printf("nhap gia tri cho cac phan tu cho ma tran:\n");
    Input(&matrix, n);

    printf("ma tran ban vua nhap la:\n");
    Output(matrix, n, n);

    //1, Tìm giá trị lớn nhất trên đường chéo chính
    printf("\ngia tri lon nhat tren duong cheo chinh la: %d\n\n", Max(matrix, n));

    //2, Tính giá trị trung bình các phần tử nhỏ hơn giá trị x (x cho trước)
    int x;
    printf("nhap x: ");
    scanf("%d", &x);
    printf("tbc cac so nho hon %d la: %f\n\n", x, tbcLonHonX(matrix, n, x));

    //3, Tìm dòng có tổng lớn nhất
    printf("gia tri lon nhat trong tong cua dong la: %d\n\n", TongLonNhat(matrix, n , n));
    



    //giải phóng bộ nhớ
    for (int i = 0; i < n; i++){
        free(*(matrix + i));
    }
    free(matrix);
    return 0;
}
