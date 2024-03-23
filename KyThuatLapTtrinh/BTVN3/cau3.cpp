/*viết ma trận A các số nguyên tố có m hàng và n cột. viết hàm thực thi sau.
1, nhập và in A ra màn hình
2, tính trung bình cộng các phần tử chẵn trong A
3, tính tronh bình cộng các phần tử lẻ trong ma trận
4, tính tổng từng hàng
5, cho biết hàng nào có tổng lớn nhất
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

void Input(int *x){
    scanf("%d",x);
}

void Input(int ***matrix, int m, int n){
    *matrix = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        *(*matrix + i) = (int*) malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", *(*matrix + i) + j);
            //*matrix = giá trị của con trỏ matrix = địa chỉ của mảng con trỏ
            //**matrix = giá trị của phần tử đầu tiên của mảng con trỏ = địa chỉ của mảng các giá trị
            //***matrix = giá trị của mảng các giá trị.
        }
    }
}

void Output(int **matrix, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
            //matrix = là con trỏ chứa vị trí của mảng các con trỏ
            //*matrix = giá trị của con trỏ đầu tiên = con trỏ chứa vị trí của mảng các giá trị
            
        }
        endl;
    }
}

float TBC(int *arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return 1.0*sum/n;
}

float PhanTuChan(int **matrix, int m, int n, int *count){
    int *list = (int*) malloc(n * sizeof(int));
    *count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(*(*(matrix + i) + j) % 2 == 0){
                *(list + *count) = *(*(matrix + i) + j);
                (*count) ++;
            }
        }
    }
    return TBC(list, *(count));
}

float PhanTuLe(int **matrix, int m, int n, int *count){
    int *list = (int*) malloc(n * sizeof(int));
    *count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(*(*(matrix + i) + j) % 2){
                *(list + *count) = *(*(matrix + i) + j);
                (*count) ++;
            }
        }
    }
    return TBC(list, *(count));
}

int *TongTungHang(int **matrix, int m, int n){
    int *list = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        *(list + i) = 0;
        for (int j = 0; j < n; j++)
        {
            *(list + i) += *(*(matrix + i) + j);
        }
    }
    return list;
}

int Max(int *arr, int n){
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
    return dir + 1;
}

int main()
{
    int m, n;
    printf("nhap kich co cho ma tran: ");
    Input(&m);
    Input(&n);

    int **matrix;
    printf("nhap gia tri cho cac phan tu trong ma tran:\n");
    Input(&matrix, m, n);

    printf("ma tran ban vua nhap la: \n");
    Output(matrix, m, n);

    int count;
    float result = PhanTuChan(matrix, m, n, &count);
    if (count)
    {
        printf("\ntbc cac phan tu chan: %f\n\n", result);
    }
    else
        printf("\nkhong co phan tu chan trong ma tran.\n\n");
    
    result = PhanTuLe(matrix, m, n, &count);
    if (count)
    {
        printf("tbc cac phan tu le: %f\n\n", result);
    }
    else
        printf("khong co phan tu le trong ma tran.\n\n");

    int *list = (int*) malloc (m * sizeof(int));
    list = TongTungHang(matrix, m, n);
    for (int i = 0; i < m; i++)
    {
        printf("tong dong %d: %d\n", i + 1, *(list + i));
    }
    
    printf("hang %d co tong lon nhat.", Max(list, m));
    return 0;
}
