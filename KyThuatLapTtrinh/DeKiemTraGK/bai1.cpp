#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define endl printf("\n")

struct Time
{
    int hour;
    int minute;
    int second;
};

struct ChuyenTau
{
    int maTau;
    char gaDi[20], gaDen[20];
    Time tgKhoiHanh, tgDen;
    char loai;
};

void Input(Time *time, FILE *f)
{
    fscanf(f, "%d%d%d", &time->hour, &time->minute, &time->second);
}

void Input(ChuyenTau **tau, int *n)
{
    FILE *f = fopen("X.txt", "r");
    fscanf(f, "%d", n);
    *tau = (ChuyenTau *)malloc(*n * sizeof(ChuyenTau));
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%d ", &(*tau + i)->maTau);

        fgets((*tau + i)->gaDi, 20, f);
        (*tau + i)->gaDi[strlen((*tau + i)->gaDi) - 1] = '\0';

        fgets((*tau + i)->gaDen, 20, f);
        (*tau + i)->gaDen[strlen((*tau + i)->gaDen) - 1] = '\0';

        Input(&(*tau + i)->tgKhoiHanh, f);

        Input(&(*tau + i)->tgDen, f);

        fscanf(f, " %c", &(*tau + i)->loai);
    }
    fclose(f);
}

void Output(Time time)
{
    printf(" %2d:%2d:%2d ", time.hour, time.minute, time.second);
}

void Output(ChuyenTau tau)
{
    printf("%10d|%10s|%10s|", tau.maTau, tau.gaDi, tau.gaDen);
    Output(tau.tgKhoiHanh);
    printf("|");
    Output(tau.tgDen);
    printf("|%c\n", tau.loai);
}

void Output(ChuyenTau *tau, int n)
{
    if (n == 0)
        return;
    Output(tau, n - 1);
    Output(tau[n - 1]);
}

Time TgDiChuyen(Time di, Time den)
{
    Time res = {
        den.hour - di.hour, den.minute - di.minute, den.second - di.second};
    if (res.second < 0)
    {
        res.second += 60;
        res.minute--;
    }
    if (res.minute < 0)
    {
        res.minute += 60;
        res.hour--;
    }
    if (res.hour < 0)
        res.hour += 24;

    return res;
}

void tgDiChuyenLoaiTauA(ChuyenTau *tau, int n, char dk)
{
    for (int i = 0; i < n; i++)
    {
        if (tau[i].loai == dk)
        {
            Output(TgDiChuyen(tau[i].tgKhoiHanh, tau[i].tgDen));
            endl;
        }
    }
}

int compareTime(Time t1, Time t2)
{
    if (t1.hour > t2.hour)
        return 1;
    else if (t1.hour < t2.hour)
        return -1;

    if (t1.minute > t2.minute)
        return 1;
    else if (t1.minute < t2.minute)
        return -1;

    if (t1.second > t2.second)
        return 1;
    else if (t1.second < t2.second)
        return -1;

    return 0;
}

ChuyenTau TauDiLauNhat(ChuyenTau *tau, int n)
{
    ChuyenTau res = *tau;
    Time max = TgDiChuyen(tau[0].tgKhoiHanh, tau[0].tgDen);
    for (int i = 0; i < n; i++)
    {
        Time tgDi = TgDiChuyen(tau[i].tgKhoiHanh, tau[i].tgDen);
        if (compareTime(max, tgDi) < 0)
        {
            max = tgDi;
            res = tau[i];
        }
    }
    return res;
}

void CungGaDiDen(ChuyenTau *tau, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool cungDi = !strcmpi(tau[i].gaDi, tau[j].gaDi);
            bool cungDen = !strcmpi(tau[i].gaDen, tau[j].gaDen);
            if(cungDi && cungDen){
                printf("%d %d\n", tau[i].maTau, tau[j].maTau);
            }
        }
    }
}

ChuyenTau CungGaDiDenMax(ChuyenTau *tau, int n)
{
    ChuyenTau res = *tau;
    res.tgKhoiHanh = {0, 0 , 0};
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool cungDi = !strcmpi(tau[i].gaDi, tau[j].gaDi);
            bool cungDen = !strcmpi(tau[i].gaDen, tau[j].gaDen);
            if(cungDi && cungDen){
                if(compareTime(res.tgKhoiHanh, tau[i].tgKhoiHanh) < 0)
                    res = tau[i];
                if(compareTime(res.tgKhoiHanh, tau[j].tgKhoiHanh) < 0)
                    res = tau[j];
            }
        }
    }
    return res;
}

ChuyenTau Find(ChuyenTau *tau, int n){
    char di[20], den[20];
    gets(di);
    gets(den);
    ChuyenTau res;
    res.tgDen = {24, 0, 0};
    res.tgKhoiHanh = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        if (!strcmpi(di, tau[i].gaDi) && 
        !strcmpi(den, tau[i].gaDen) && 
        compareTime(TgDiChuyen(res.tgKhoiHanh, res.tgDen), TgDiChuyen(tau[i].tgKhoiHanh, tau[i].tgDen)) >0
        ){
            res = tau[i];
        }
    }
    return res;
}

int main()
{
    int n;
    ChuyenTau *tau;
    Input(&tau, &n);
    printf("thong tin chuyen tau la:\n");
    Output(tau, n);
    endl;
    printf("thoi gian di chuyen loai tau a:\n");
    tgDiChuyenLoaiTauA(tau, n, 'A');

    printf("\ntau di lau nhat:\n");
    Output(TauDiLauNhat(tau, n));
    endl;
    printf("tau co cung ga di va ga den la:\n");
    CungGaDiDen(tau, n);
    printf("chuyen co chung di den co thoi gian khoi hanh muon nhat:\n");
    Output(CungGaDiDenMax(tau, n));

    printf("tim:\n");
    Output(Find(tau, n));
    free(tau);
    return 0;
}