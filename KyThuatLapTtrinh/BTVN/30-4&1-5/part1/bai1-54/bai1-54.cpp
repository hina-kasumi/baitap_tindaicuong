/*Cho mảng các số nguyên, hãy sắp xếp mảng theo thứ tự tăng dần. Dữ liệu vào: tập tin văn bản ARRAY.INP gồm 2 dòng 
- Dòng 1 chứa số nguyên n (n < = 100). 
- Dòng 2 chứa n số nguyên.
 
Kết quả: Đưa ra tập tin văn bản ARRAY.OUT gồm hai dòng 
- Dòng 1 chứa n phần tử của mảng các số nguyên. 
Dòng 2 chứa n số nguyên được xếp tăng dần.*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n")

void File(FILE **fin, FILE **fout){
    *fin = fopen("ARRAY.INP", "r");
    *fout = fopen("ARRAY.OUT", "w");
}

void Input(int **arr, int n, FILE *fin){
    *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        fscanf(fin, "%d", *arr + i);
    }
}

void Output(int *arr, int n, FILE *fout){
    if (n == 0)
        return;

    Output(arr, n - 1, fout);
    fprintf(fout, "%d ", arr[n - 1]);
}

int main()
{
    FILE *fin;
    FILE *fout;
    File(&fin, &fout);

    int n;
    fscanf(fin, "%d", &n);

    int *arr;
    Input(&arr, n ,fin);

    Output(arr, n , fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
