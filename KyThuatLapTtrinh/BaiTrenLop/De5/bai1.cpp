#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define endl printf("\n")

void Input(float **x, float **y, int *n){
    FILE *f;
    do {
        printf("nhap ten file: ");
        char nameFile[20];
        scanf("%s", nameFile);
        f = fopen(nameFile, "r");
    } while (f == NULL);

    fscanf(f, "%d", n);
    *x = (float*) malloc(*n * sizeof(float));
    *y = (float*) malloc(*n * sizeof(float));
    for (int i = 0; i < *n; i++)
        fscanf(f, "%f%f", *x + i, *y + i);
    
    
    fclose(f);
}

void Output(float x, float y){
    printf("(%.2f, %.2f)\n", x, y);
}

void Output(float *x, float *y, int n){
    if (n == 0)
        return;
    Output(x, y, n - 1);
    Output(x[n - 1], y[n - 1]);
}

int location(float *x, float *y, int n){
    float max = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        float tmp = x[i] * x[i] + y[i] * y[i];
        if(max < tmp){
            max = tmp;
            res = i;
        }
    }
    return res;
}

int CntLine(float *x, float *y, int n){
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] < 0 && y[i] < 0 && y[j] < 0 && x[j] < 0)
                res++;
        }
    }
    return res;
}

int main()
{
    FILE *f;
    
    
    int n;
    float *x, *y;
    Input(&x, &y, &n);

    printf("danh sach cac diem tren do thi:\n");
    Output(x, y, n);

    printf("diem xa goc toa do nhat la: ");
    int diemXa = location(x, y, n);
    Output(x[diemXa], y[diemXa]);

    int soDiem = CntLine(x, y, n);
    if(soDiem){
        printf("co %d doan thang thoa man.\n", soDiem);
    }
    else
        printf("khong co doan thang thoa man.\n");

    free(x);
    free(y);
    return 0;
}
