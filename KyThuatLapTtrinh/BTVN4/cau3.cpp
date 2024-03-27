/*xây dựng cấu trúc đa thức gồm 1 số nguyên n là bậc của đa thức và một con trỏ kiểu số thực
là các hệ số của đa thức. Xây dựng các hàm:
1, nhập, xuất mọt đa thức Px bậc n
2, nhập số thực x, tính S
3, nhập vào đa thức Qx bậc n, in ra màn hình hệ số của đa thức hiệu trong trường hợp khác bậc
4, tìm hệ số lớn nhất của đa thức
5, tính tổng các hệ số âm có trong đa thức.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

void Input(int *x){
    scanf("%d", x);
}

void Input(float *x){
    scanf("%f", x);
}

void Input(float **hesoP, int n){
    *hesoP = (float*) malloc((n + 1) * sizeof(float));
    for (int i = n; i >= 0; i--)
    {
        printf("x^%d: ", i);
        Input(*hesoP + i);
    }
}

void Output(float *hesoP, int n){
    for (int i = n; i > 0 ; i--)
    {
        printf("%.2f x^%d + ", *(hesoP + i), i);
    }
    printf("%.2f\n\n", *hesoP);
}

float TinhS(float *hesoP, int n, float x){
    float S = *hesoP + 2023;
    for (int i = n; i > 0; i--)
    {
        S += (pow(x, i) + i * pow(x, i - 1)) * (*(hesoP + i));
    }
    return sqrt(S) + x;
}

int SoLonHon(int x, int y){
    return (x > y)? x:y;
}

int SoBeHon(int x, int y){
    return (x > y)? y:x;
}

void GanSo(int a, int b,float *dathucHieu, float *hesoP){
    for (int i = a + 1; i <= b; i++)
    {
        *(dathucHieu + i) = *(hesoP + i);
    }
}

float *DaThucHieu(float *hesoQ, int m, float *hesoP, int n){
    int soLon = SoLonHon(m, n);
    int soBe = SoBeHon(m, n);

    float *dathucHieu = (float*) malloc((soLon + 1) * sizeof(float));
    
    for (int i = 0; i <= soBe; i++)
    {
        *(dathucHieu + i) = *(hesoP + i) - *(hesoQ + i);
    }
    
    if (n > m) 
        GanSo(soBe, soLon, dathucHieu, hesoP);
    else if (m > n)
        GanSo(soBe, soLon, dathucHieu, hesoQ);
    return dathucHieu;
}

float Max(float *arr, int n){
    int max = *arr;
    for (int i = 0; i <= n; i++)
    {
        max = (max < *(arr + i))? *(arr + i):max;
    }
    return max;
}


float TongSoAm(float *arr, int n){
    float result = 0;
    for (int i = 0; i <= n; i++)
    {
        if (*(arr + i) < 0)
            result += *(arr + i);
    }
    return result;
}

int main()
{
    int n;
    printf("nhap so bac cua da thuc P(x): ");
    Input(&n);

    float *hesoP;
    printf("nhap he so cho da thuc Px:\n");
    Input(&hesoP, n);

    printf("da thuc ban vua nhap la: ");
    Output(hesoP, n);

    //2,
    float x;
    printf("nhap so thuc x: ");
    Input(&x);

    printf("S = %f\n\n", TinhS(hesoP, n, x));

    //3, nhập vào đa thức Qx bậc n, in ra màn hình hệ số của đa thức hiệu trong trường hợp khác bậc
    int m;
    printf("nhap bac cua Qx: ");
    Input(&m);
    printf("nhap he so cho da thuc Qx:\n");
    float *hesoQ;
    Input(&hesoQ, m);
    printf("da thuc Qx ban vua nhap la: ");
    Output(hesoQ, m);

    if (m != n){
        printf("da thuc hieu cua Px va Qx la: ");
        float *dathuchieu = DaThucHieu(hesoQ, m, hesoP, n);
        Output(dathuchieu, SoLonHon(n, m));
        free(dathuchieu);
    }
    else
        printf("bac cua Px va Qx bang nhau ne khong co da thuc hieu.\n\n");

    printf("he so lon nhat cua Px: %.2f\n\n", Max(hesoP, n));

    float tongSoAm = TongSoAm(hesoP, n);
    if (tongSoAm < 0)
        printf("tong cac he so am cua Px = %f\n\n", tongSoAm);
    else
        printf("khong co so am trong da thuc Px.\n\n");

    free(hesoQ);
    free(hesoP);
    return 0;
}
