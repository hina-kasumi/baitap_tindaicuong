#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define endl printf("\n")
#define endll printf("\n\n")
FILE *file;

void MoFile(){
    file = fopen("input.txt", "r"); //mở file input.txt
}

void DongFile(){
    fclose(file); // dóng file input.txt
}

void Input(int *x){
    fscanf(file, "%d", x);
}

void Input(int **arr, int n){
    *arr = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        Input(*arr + i);
    }
}

int main()
{
    MoFile();
    int n;
    Input(&n);

    int m;
    Input(&m);

    int *px;
    Input(&px, n);

    int *qx;
    Input(&qx, m);

    


    DongFile();

    return 0;
}
