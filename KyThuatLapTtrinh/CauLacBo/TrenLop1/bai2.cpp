#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define endl printf("\n")

struct HoGiaDinh
{
    char name[20];
    char diaChi[20];
    int maCT;
    float soNuoc;
};

void Input(HoGiaDinh *gd, FILE *f){
    fgets(gd->name, 20, f);
    gd->name[strlen(gd->name) - 1] = '\0';

    fgets(gd->diaChi, 20, f);
    gd->diaChi[strlen(gd->diaChi) - 1] = '\0';

    fscanf(f, "%d%f ", &gd->maCT, &gd->soNuoc);
}

void Input(HoGiaDinh *gd, int n, FILE *f){
    if(n == 0)
        return;
    Input(gd, n - 1, f);
    Input(gd + n - 1, f);
}

void Output(HoGiaDinh gd){
    printf("%10s|%10s|%10d|%10.2f\n", gd.name, gd.diaChi, gd.maCT, gd.soNuoc);
}


void Output(HoGiaDinh *gd, int n){
    if(n == 0)
        return;
    Output(gd, n - 1);
    Output(gd[n - 1]);
}

void Output(HoGiaDinh gd, FILE *f){
    fprintf(f, "%10s|%10s|%10d|%10.2f\n", gd.name, gd.diaChi, gd.maCT, gd.soNuoc);
}


void Hanoi(HoGiaDinh *gd, int n){
    FILE *f = fopen("HaNoi.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        if (!strcmpi((gd + i)->diaChi, "Hanoi"))
        {
            Output(gd[i], f);
        }
    }
    fclose(f);
}

void sort(HoGiaDinh *gd, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            
            if(strcmp((gd + i)->name, (gd + j)->name) > 0){
                HoGiaDinh x = gd[i];
                gd[i] = gd[j];
                gd[j] = x;
            }
            if(strlen(gd[i].name) > strlen(gd[j].name)){
                HoGiaDinh x = gd[i];
                gd[i] = gd[j];
                gd[j] = x;
            }
        }
    }
}

int main()
{
    FILE *f = fopen("NuocTieuThu.txt", "r");
    int n;
    fscanf(f, "%d ", &n);
    HoGiaDinh *gd = (HoGiaDinh*) malloc(n * sizeof(HoGiaDinh));
    Input(gd, n, f);
    Output(gd, n);
    fclose(f);

    endl;

    Hanoi(gd, n);
    endl;

    sort(gd, n);
    Output(gd, n);
    return 0;
}
