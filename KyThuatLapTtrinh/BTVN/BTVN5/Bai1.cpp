/*xây dựng hàm và thực hiện các công việc sau
1, nhập vào ma trận vuông A, kiểu số nguyên kích thước n * n
2, kiểm tra xem ma trận có phải ma trận tma giác trên hay không 
3, tính tích các phần tử nằm phía dưới đường chéo phụ
4, hãy cho biết các cột có tổng bằng nhau
5, nhập vào một ma trận  vuông B, kiểu số nguyên, cùng cấp với ma trận A, tính tổng 2 ma trận A và B 
6, cho biết ma trận nào có tổng lớn hơn
7, cho biết max(max(A), max(B))
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")

//Attribute
int n;


void Input (int *x){
    scanf("%d", x);
}

void Input(int ***matrix){
    *matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        *(*matrix + i) = (int*) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            Input(*(*matrix + i) + j);
        }
    }
}

void Output(int x){
    printf("%d ", x);
}
void Output(int **matrix){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            Output(*(*(matrix + i) + j));
        }
        endl;
    }
}

//2, kiểm tra xem ma trận có phải ma trận tma giác trên hay không 
bool CheckUpperTriangle(int **matrix){
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (*(*(matrix + i) + j))
                return false;
        }
    }
    return true;
}

//3, tính tích các phần tử nằm phía dưới đường chéo phụ
int MultiplyBelowSecondaryDiagonal(int **matrix){
    int res = 1;
    for (int i = 1; i < n; i++){
        for (int j = n - i; j < n; j++){
            res *= *(*(matrix + i) + j);
        }
    }
    return res;
}

//4, hãy cho biết các cột có tổng bằng nhau
void ColumnsWithEqualSums(int **matrix){
    int *sumColumns = (int*) malloc(n * sizeof(int));
    for (int column = 0; column < n; column++){
        *(sumColumns + column) = 0;
        for (int row = 0; row < n; row++){
            *(sumColumns + column) += *(*(matrix + row) + column);
        }
    }

    bool check[n];
    memset(check, false, n);
    bool isFined = false;

    for (int i = 0; i < n - 1; i++){
        bool title = true;
        if (!check[i]){
            for (int j = i + 1; j < n; j++)
            {
                if (*(sumColumns + i) == *(sumColumns + j)){
                    if (title)
                        printf("The columns equal are: %d ", i + 1);
                    title = false;
                    Output(j + 1);
                    check[j] = true;
                    isFined = true;
                }
            }
            endl;
        }
    }
    if (isFined) return;
    printf("All the sums of columns are not equal.\n");
}

//5, nhập vào một ma trận vuông B, kiểu số nguyên, cùng cấp với ma trận A, tính tổng 2 ma trận A và B 
int **AddMatrix(int **matrixA, int**matrixB){
    int **matrixRes = (int**) malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++){
        *(matrixRes + i) = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++){
            *(*(matrixRes + i) + j) = *(*(matrixA + i) + j) + *(*(matrixB + i) + j);
        }
    }
    return matrixRes;
}

//6, cho biết ma trận nào có tổng lớn hơn
int SumOfElements(int **matrix){
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res += *(*(matrix + i) + j);
        }
    }
    return res;
}

//7, cho biết max(max(A), max(B))
int CompareMatrix(int **matrixA, int **matrixB){
    int sumOfElementsA = SumOfElements(matrixA);
    int sumOfElementsB = SumOfElements(matrixB);

    return sumOfElementsA - sumOfElementsB;
}

int findMaxBothMatrix (int **matrixA, int **matrixB){
    int max = **matrixA;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            max = (max < matrixA[i][j])? matrixA[i][j]: max;
            max = (max < matrixB[i][j])? matrixB[i][j]: max;
        }
    }
    return max;
}


int main()
{
    //1, nhập vào ma trận vuông A, kiểu số nguyên kích thước n * n
    printf("Enter the size of matrix: ");
    Input(&n);

    printf("Enter value for elements in matrix:\n");
    int **matrix;
    Input(&matrix);

    printf("The matrix you entered is:\n");
    Output(matrix);
    endl;

    //2, kiểm tra xem ma trận có phải ma trận tma giác trên hay không 
    if (CheckUpperTriangle(matrix))
        printf("The matrix is upper triangular matrix.\n\n");
    else 
        printf("The matrix is not upper triangular matrix.\n\n");

    //3, tính tích các phần tử nằm phía dưới đường chéo phụ
    printf("The multiple below secondary diagonal of matrix: %d.\n\n", MultiplyBelowSecondaryDiagonal(matrix));

    //4, hãy cho biết các cột có tổng bằng nhau
    ColumnsWithEqualSums(matrix);
    endl;

    //5, nhập vào một ma trận  vuông B, kiểu số nguyên, cùng cấp với ma trận A, tính tổng 2 ma trận A và B 
    printf("Enter value for matrix B, whose size equals with matrix A:\n");
    int **matrixB;
    Input(&matrixB);

    printf("matrix B you entered is:\n");
    Output(matrixB);

    int **addMatrix = AddMatrix(matrix, matrixB);
    printf("matrix A + matrix B =\n");
    Output(addMatrix);
    endl;

    //6, cho biết ma trận nào có tổng lớn hơn
    int compareMatrix = CompareMatrix(matrix, matrixB);
    if (compareMatrix > 0)
        printf("sum of matrix A > matrix B\n\n");
    else if (compareMatrix == 0)
        printf("sum of matrix A = matrix B\n\n");
    else
        printf("sum of matrix A < matrix B\n\n");

    //7, cho biết max(max(A), max(B))
    printf("max(max(A), max(B)) = %d", findMaxBothMatrix(matrix, matrixB));



    //giải phóng bộ nhớ
    for(int i = 0; i < n; i++)
        free(*(matrix + i));
    free(matrix);
    for(int i = 0; i < n; i++)
        free(*(matrixB + i));
    free(matrixB);
    for(int i = 0; i < n; i++)
        free(*(addMatrix + i));
    free(addMatrix);
    return 0;
}
