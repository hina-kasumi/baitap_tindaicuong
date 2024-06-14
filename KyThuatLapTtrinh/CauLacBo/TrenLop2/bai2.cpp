#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n")

struct goods
{
    char loai;
    float kl;
    int tgbq;
};

void Input(goods **hang, int n, FILE *f){
    *hang = (goods*) malloc(n * sizeof(goods));
    for (int i = 0; i < n; i++)
    {
        fscanf(f, " %c %f %d ", &(*hang + i)->loai, &(*hang + i)->kl, &(*hang + i)->tgbq);
    }
}
void Output(goods hang){
    printf("%2c%10.2f%10d\n", hang.loai, hang.kl, hang.tgbq);
}
void Output(goods *hang, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%2c%10.2f%10d\n", (hang + i)->loai, (hang + i)->kl, (hang + i)->tgbq);
    }
}

void sort(goods *hang, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(hang[i].kl > hang[j].kl && hang[i].loai == 'A' && hang[j].loai == 'A'){
                goods x = hang[i];
                hang[i] = hang[j];
                hang[j] = x;
            }
        }
    }
}
void sortsgbq(goods *hang, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(hang[i].tgbq < hang[j].tgbq){
                goods x = hang[i];
                hang[i] = hang[j];
                hang[j] = x;
            }
        }
    }
}

void InRaFile(goods *hang, int n){
    FILE *f = fopen("X.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (hang[i].tgbq > 180 && hang[i].loai == 'T')
        {
            fprintf(f, "%2c%10.2f%10d\n", (hang + i)->loai, (hang + i)->kl, (hang + i)->tgbq);
        }
    }
    fclose(f);
}
void Output(goods *hang, int n, char dk){
    for (int i = 0; i < n; i++)
    {
        if(hang[i].loai == dk)
            Output(hang[i]);
    }
}

int main()
{
    FILE *f = fopen("commodity.txt", "r");
    int n;
    fscanf(f, "%d ", &n);
    goods *hang;
    Input(&hang, n, f);
    fclose(f);
    Output(hang, n);

    sort(hang, n);
    printf("sau khi xep theo kl:\n");
    Output(hang, n, 'A');


    sortsgbq(hang, n);
    printf("hang t giam dan:\n");
    Output(hang, n, 'T');


    InRaFile(hang, n);
    return 0;
}
