#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define endl printf("\n")

struct NhanVien
{
    char name[20];
    float luong;
    int maCV;
};

void Input(NhanVien **nv, int *n){
    scanf("%d", n);
    *nv = (NhanVien*) malloc(*n * sizeof(NhanVien));
    for (int i = 0; i < *n; i++)
    {
        fflush(stdin);
        printf("ten nhan vien: ");
        gets((*nv + i)->name);

        printf("luong: ");
        scanf("%f", &(*nv + i)->luong);
        printf("ma cong viec: ");
        scanf("%d", &(*nv + i)->maCV);
        endl;
    }
}

void Output(NhanVien nv, FILE *f){
    fprintf(f, "%s\n%f\n%d\n", nv.name, nv.luong, nv.maCV);
}

void Output(NhanVien *nv, int n, FILE *f){
    if (n == 0)
        return;
    Output(nv, n - 1, f);
    Output(nv[n - 1], f);
}

float TBluong(NhanVien *nv, int n, int ma){
    float res = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(nv[i].maCV == ma){
            res += nv[i].luong;
            cnt++;
        }
    }
    if (cnt)
        return res / cnt;
    else
        return -1;
}

void In(NhanVien *nv, int n){
    for (int i = 1; i <= 3; i++){
        float tbluong = TBluong(nv, n, i);
        if (tbluong > -1)
            printf("trung binh luong cv %d la: %f\n", i, tbluong);
        else
            printf("khong co ai lam cong viec %d.\n", i);
        
    }
}

int main()
{
    FILE *f = fopen("output.txt", "w");
    int n;
    NhanVien *nv;
    printf("nhap danh sach nhan vien:\n");
    Input(&nv, &n);

    In(nv, n);


    
    if (f == NULL)
        printf("error");
    Output(nv, n, f);
    
    free(nv);
    fclose(f);
    return 0;
}
