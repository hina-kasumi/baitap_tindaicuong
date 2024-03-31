/*bài 1 xây dựng hàm và thực hiện các công việc sau
1, nhập vào ma trận vuông số nguyên kích thước n*n
2, tìm giá trị lớn nhất trên đường chéo chính
3, tìm giá trị trung bình các phần tử nhỏ hơn giá trị x (x cho trước)
4, tìm dòng có tổng lớn nhất
5, sắp xếp ma trận theo tứ tự tăng dần từ trái sang phải tử trên xuống dưới*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

void Input(int *x){
    scanf("%d", x);
}

void Input(int ***matrix, int n){
    *matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(*matrix + i) = (int*) malloc (n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Input(*(*matrix + i) + j);
        }
    }
    
}


void Output(int **matrix , int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        endl;
    }
}

int *GiaTriDuongCheo(int **matrix, int n){
    int *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = *(*(matrix + i) + i);
    }
    return arr;
}

int Max(int *arr, int n){
    int max = *arr;
    for (int i = 0; i < n; i++)
    {
        max = (max < *(arr + i))? *(arr + i):max;
    }
    return max;
}

int Dir(int *arr, int n){
    int max = *arr;
    int dir = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
            dir = i;
        }
    }
    return dir;
}

//3, tìm giá trị trung bình các phần tử nhỏ hơn giá trị x (x cho trước)
float TBCnhoHonX(int **matrix, int n, int x, int *count){
    float tbc = 0;
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(*(matrix + i) + j) > x)
            {
                tbc += (float) *(*(matrix + i) + j);
                (*count) ++;
            }
        }
    }
    return tbc/(*count);
}

int Tong(int *arr, int n){
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += *(arr + i);
    }
    return result;
}

//4, tìm dòng có tổng lớn nhất
int DongLonNhat(int **matrix, int n){
    int *tongDong = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(tongDong + i) = Tong(*(matrix + i), n);
    }
    return Dir(tongDong, n);
}

void Sort(int *arr, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(*(arr + i) > *(arr + j))
            {
                int tmp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = tmp;
            }
        }
    }
}
void Sort(int **matrix, int n){
    int *arr = (int*) malloc((n * n) * sizeof(int));
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(arr + tmp) = *(*(matrix + i) + j);
            tmp++;
        }
    }
    Sort(arr, n*n);
    tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           *(*(matrix + i) + j) = *(arr + tmp);
           tmp++;
        }
    }
}


int main()
{
    int n;
    printf("nhap kich co ma tran: ");
    Input(&n);

    int **matrix;
    printf("nhap gia tri cho ma tran:\n");
    Input(&matrix, n);

    printf("ma tran ban vua nhap la:\n");
    Output(matrix, n);

    //2, tìm giá trị lớn nhất trên đường chéo chính
    int *arr = GiaTriDuongCheo(matrix, n);
    printf("\ngia tri lon nhat tren duong cheo chinh: %d\n\n", Max(arr, n));

    //3, tìm giá trị trung bình các phần tử nhỏ hơn giá trị x (x cho trước)
    int x;
    int count;
    printf("nhap x: ");
    Input(&x);
    float result = TBCnhoHonX(matrix, n, x, &count);
    if (count)
        printf("tbc cac so lon hon %d la: %f\n\n", x, result);
    else
        printf("khong co gia tri nao lon hon %d.\n\n", x);

    //4, tìm dòng có tổng lớn nhất
    printf("dong %d co tong lon nhat.\n\n", DongLonNhat(matrix, n));

    
    
    //5, sắp xếp ma trận theo tứ tự tăng dần từ trái sang phải tử trên xuống dưới
    Sort(matrix, n);
    printf("ma tran sau khi dc sap xep:\n");
    Output(matrix, n);
    //giải phóng ma trận
    free(matrix);
    for (int i = 0; i < n; i++)
    {
        free(*matrix + i);
    }
    return 0;
    /*
    4
    2 6 8 3
    4 6 1 7
    88 5 3 1
    6 3 4 5*/
}

