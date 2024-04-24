#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define fendl fprintf(fileOut, "\n")

FILE *fileIn;
FILE *fileOut = fopen("out.txt", "w+");

int max(int n, int m){
    return (n < m)? m:n;
}

void ChonFile(char *nameFile){
    printf("nhap ten file\n");
    scanf("%s", nameFile);
}

void Input(int *n){
    fscanf(fileIn, "%d", n);
}
void Input(float *n){
    fscanf(fileIn, "%f", n);
}
void Input(float *arr, int n){
    for (int i = n; i >= 0; i--)
        Input(arr + i);
}

void Output(float *arr, int n){
    for (int i = n; i > 0; i--)
    {
        fprintf(fileOut, "%.2fx^%d + ", arr[i], i);
    }
    fprintf(fileOut, "%.2f",arr[0]);
}

void NhapVaXuat(float *arr, int n, char name[]){
    fprintf(fileOut, "bac cua %s: %d\n", name, n);
    Input(arr, n);
    fprintf(fileOut, "%s: ", name);
    Output(arr, n);
    fendl;
}

float Pd1 (float *arr, int n, int d1){
    float p = 0;
    for (int i = 0; i <= n; i++)
    {
        p += arr[i] * pow(d1, i);
    }
    return p;
}

float TinhS(float *px, float *qx, float d1, float d2, int n, int m){
    return  sqrt(abs(Pd1(px, n, d1) - Pd1(qx, m, d2))) - 2013;
}

float *HieuDaThuc(float *px, float *qx, int n, int m){
    int tmp = max(m, n);
    float *res = (float*)malloc((max(n, m) + 1)*sizeof(float));

    for (int i = tmp; i >= 0; i--)
    {
        *(res + i) = px[i] - qx[i];
    }
    return res;
}



int main()
{
    do{
        char nameFile[20];
        printf("vui long nhap ten file can lay du lieu: ");
        ChonFile(nameFile);
        fileIn = fopen(nameFile, "r");
    }while (fileIn == NULL);
    
    int n, m;
    Input(&n);
    Input(&m);
    float *px = (float*)malloc((max(n, m) + 1)*sizeof(float));
    float *qx = (float*)malloc((max(m, n) + 1)*sizeof(float));
    NhapVaXuat(px, n, "P(x)");
    NhapVaXuat(qx, m, "Q(x)");
    fendl;

    float d1, d2;
    Input(&d1);
    Input(&d2);
    fprintf(fileOut, "d1 = %f\nd2 = %f\n", d1, d2);
    fprintf(fileOut, "s = %f\n\n", TinhS(px, qx, d1, d2, n, m));

    fprintf(fileOut, "da thuc hieu cua P(x) - Q(x) = ");
    Output(HieuDaThuc(px, qx, n, m), max(n, m));
    

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}
