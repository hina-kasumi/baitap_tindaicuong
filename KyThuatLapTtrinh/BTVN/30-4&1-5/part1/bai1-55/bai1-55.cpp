/*Viết chương trình tạo file văn bản có tên là “MATRIX.INP” có cấu trúc như sau: 
- Dòng đầu ghi hai số m, n. 
- Trong m dòng tiếp theo mỗi dòng ghi n số và các số các nhau một khoảng 
cách. 
- Hãy kiểm tra xem trong file đó có bao nhiêu số nguyên tố. Kết quả cần 
ghi vào file “MATRIX.OUT” có nội dung là một số nguyên đó là số 
lượng các số nguyên tố trong file “MATRIX.INP”.*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n")

void File(FILE **fin, FILE **fout){
    *fin = fopen("MATRIX.INP", "r");
    *fout = fopen("MATRIX.OUT", "w");
}

void Input(int ***matrix, int m, int n, FILE *fin){
    *matrix = (int**) malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++){
        *(*matrix + i) = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++){
            fscanf(fin, "%d", *(*matrix + i) + j);
        }
    }
}

bool isPrime(int x){
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0)
            return false;
    }
    return true;
}

int CntPrime(int **matrix, int m, int n){
    int cnt = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(isPrime(matrix[i][j]))
                cnt++;
        }   
    }
    return cnt;
}

int main()
{
    FILE *fin, *fout;
    File(&fin, &fout);

    int m, n;
    fscanf(fin, "%d%d", &m, &n);

    int **matrix;
    Input(&matrix,  m, n, fin);

    fprintf(fout, "%d", CntPrime(matrix, m ,n));

    for (int i = 0; i < m; i++){
        free(matrix[i]);
    }
    free(matrix);
    fclose(fin);
    fclose(fout);
    return 0;
}
