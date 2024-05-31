#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define endl printf("\n")

void Input(int **x, int **y, int *n){
    FILE *f;
    char nameFile[20];
    scanf("%s", &nameFile);
    f = fopen(nameFile, "r");

    

    fscanf(f, "%d", n);
    *x = (int*) malloc(*n * sizeof(int));
    *y = (int*) malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%d%d", *x + i, *y + i);
    }
    fclose(f);
}

void Output(int *x, int *y, int n){
    if(n == 0)
        return;
    Output(x, y, n - 1);
    printf("(%d, %d)\n", x[n - 1], y[n - 1]);
}

int index(int *x, int *y, int n){
    int min = INT_MAX;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if((x[i] + y[i])%2){
            int tmp = x[i] * x[i] + y[i] * y[i];
            if(min > tmp){
                min = tmp;
                res = i;
            }
        }
    }
    return res;
}

int MahaTan(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int MahatanMin(int *x, int *y, int n){
    int min = INT_MAX;
    for (int i = 0; i < n -1 ; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = MahaTan(x[i], y[i], x[j], y[j]);
            if (min > tmp)
            {
                min = tmp;
            }
        }
    }
    return min;
}

void In(int *x, int *y, int n){
    int min = MahatanMin(x, y, n);
    printf("diem mahatanmin:\n");
    for (int i = 0; i < n -1 ; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = MahaTan(x[i], y[i], x[j], y[j]);
            if (min == tmp)
                printf("doan tao boi(%d, %d) va (%d, %d)\n", x[i], y[i], x[j], y[j]);
        }
    }
}

int main()
{
    int *x, *y, n;
    Input(&x, &y, &n);
    Output(x, y, n);

    int diem = index(x, y, n);
    if(diem == -1){
        printf("khong co diem co tinh chan le\n");
    } else {
        printf("diem co tinh chan le gan goc toa do nhat: (%d, %d)\n", x[diem], y[diem]);
    }

    In(x, y, n);

    free(x);
    free(y);
    return 0;
}
