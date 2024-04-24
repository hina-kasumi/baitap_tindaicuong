#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define fendl fprintf(fout, "\n")
void Input(int *x, FILE *fin){
    fscanf(fin, "%d", x);
}
void Input(int **arr, int n, FILE *fin){
    *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        Input(*arr + i, fin);
}
void Input(int ***matrix, int m, int n, FILE *fin){
    *matrix = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        Input(*matrix + i, n, fin);
    }
    
}
void Output(int n, FILE *fout){
    fprintf(fout, "%d ", n);
}

void Output(int *arr, int n, FILE *fout){
    for (int i = 0; i < n; i++)
        Output(*(arr + i), fout);
}
void Output(int **matrix, int m, int n, FILE *fout){
    for (int i = 0; i < m; i++)
    {
        Output(*(matrix + i), n, fout);
        fendl;
    }
    
}
int main()
{
    char nameFile[20];
    scanf("%s", nameFile);
    FILE *fin = fopen(nameFile, "r");
    FILE *fout = fopen("out.txt", "w");
    
    int m, n;
    Input(&m, fin);
    Input(&n, fin);

    int **matrix;
    Input(&matrix, m, n, fin);
    Output(matrix, m, n, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
