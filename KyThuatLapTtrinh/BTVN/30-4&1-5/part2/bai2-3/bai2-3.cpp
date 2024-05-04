/*Bài 3  Một ma trận vuông A lưu trong tệp văn bản (tên tệp nhập từ bàn phím) có dạng: dòng đầu chứa cấp 
của ma trận, các dòng tiếp theo là các hàng của ma trận. Hãy xây dựng hàm thực hiện các yêu cầu sau: 
1. Đọc dữ liệu của ma trận A từ tệp trên. 
2. Tính trung bình cộng các phần tử nằm phía dưới đường chéo phụ của ma trận A. 
3. Kiểm tra xem ma trận A có là ma trận tam giác trên không. 
4. Kiểm tra xem ma trận có là ma trận đối xứng hay không 
5. Tính tổng từng hàng, cho biết hàng nào có tổng lớn nhất*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

void Input(int ***matrix, int *n, FILE *fin){
    fscanf(fin, "%d", n);
    *matrix = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *n; i++)
    {
        *(*matrix + i) = (int*) malloc(*n * sizeof(int));
        for (int j = 0; j < *n; j++)
        {
            fscanf(fin, "%d", *(*matrix + i) + j);
        }
    }
}

void OutArray(int *arr, int n){
    if(n == 0)
        return;
    OutArray(arr, n - 1);
    printf("%d ", arr[n - 1]);
}

void OutMatrix(int **matrix, int m, int n){
    if(m == 0)
        return;
    OutMatrix(matrix, m - 1, n);
    OutArray(matrix[m - 1], n);
    endl;
}
//2. Tính trung bình cộng các phần tử nằm phía dưới đường chéo phụ của ma trận A. 
float TbcDuoi(int **matrix, int n){
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            res += matrix[i][j];
        }
    }
    return 1.0 * res / n;
}

//3. Kiểm tra xem ma trận A có là ma trận tam giác trên không. 
bool isTamGiaTren(int **matrix, int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j])
                return false;
        }
    }
    return true;
}

//4. Kiểm tra xem ma trận có là ma trận đối xứng hay không 
bool DoiXung(int **matrix, int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}

int TongHang(int *a, int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i];
    return res;
}

int Max(int **matrix, int m, int n){
    if (m == 0)
        return TongHang(*matrix, n);
    m--;
    int max = Max(matrix, m, n);
    int tmp = TongHang(matrix[m], n);
    return (max< tmp)? tmp:max;
}

int main()
{
    FILE *fin;
    char nameFile[20];
    do
    {
        printf("vui long nhap ten file chua du lieu ban muon doc: ");
        gets(nameFile);
        fin = fopen(nameFile, "r");
    } while (fin == NULL);
    
    int **matrix, n;
    Input(&matrix, &n, fin);
    printf("ma tran:\n");
    OutMatrix(matrix, n, n);
    
    //2. Tính trung bình cộng các phần tử nằm phía dưới đường chéo phụ của ma trận A. 
    printf("\ntrung binh cong duoi duong cheo chinh = %f\n\n", TbcDuoi(matrix, n));

    //3. Kiểm tra xem ma trận A có là ma trận tam giác trên không. 
    if(isTamGiaTren(matrix, n))
        printf("day la ma tran tam giac tren.\n\n");
    else
        printf("day khong phai ma tran tam giac tren.\n\n");
    
    if(DoiXung(matrix, n))
        printf("ma tran nay doi xung.\n\n");
    else
        printf("ma tran nay khong doi xung.\n\n");

    printf("hang co tong lon nhat co gia tri la: %d", Max(matrix, n, n));



    fclose(fin);
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}
