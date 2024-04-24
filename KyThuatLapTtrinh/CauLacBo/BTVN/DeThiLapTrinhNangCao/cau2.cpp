#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define fendl fprintf(fout, "\n")

FILE *fin = fopen("input.txt", "r");
FILE *fout = fopen("out.txt", "w+");

struct Oto
{
    int BKS;
    int TT;
    char Cty;
};
void Input(int *x){
    fscanf(fin, "%d", x);
}

void Input(Oto *oto){
    fscanf(fin, "%d%d %c", &oto->BKS, &oto->TT, &oto->Cty);
}

void Input(Oto **oto, int n){
    *oto = (Oto*) malloc(n * sizeof(Oto));
    for (int i = 0; i < n; i++)
    {
        Input(*oto + i);
    }
}

void Output(Oto oto){
    fprintf(fout, "%10d|%10d|%5c\n", oto.BKS, oto.TT, oto.Cty);
}
void Output(Oto *oto, int n){
    for (int i = 0; i < n; i++)
    {
        Output(*(oto + i));
    }
}

//thống kê bks của oto công ty B chia hết cho 3
int ThongKe(Oto *oto, int n, char cty){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((oto + i)->BKS % 3 == 0 && (oto + i)->Cty == cty){
            count++;
        }
    }
    return count;
}

//Quick sort
void swap(Oto *oto1, Oto *oto2){
    Oto tmp = *oto1;
    *oto1 = *oto2;
    *oto2 = tmp;
}
int pter(Oto *oto, int low, int high){
    Oto pivot = oto[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (oto[j].TT < pivot.TT)
        {
            i++;
            swap(&oto[i], &oto[j]);
        }
    }
    swap(&oto[i + 1], &oto[high]);
    return (i + 1);
}

void Sort(Oto *oto, int low, int high){
    if (low < high)
    {
        int pi = pter(oto, low, high);
        Sort(oto, low, pi - 1);
        Sort(oto, pi + 1, high);
    }
}

int main()
{
    int n;
    Input(&n);
    fprintf(fout, "co %d oto can quan ly.\n", n);

    Oto *oto;
    Input(&oto, n);

    fprintf(fout, "danh sach oto can quan ly la:\n");
    Output(oto, n);

    fprintf(fout, "\nso oto co BKS chia het cho 3 = %d\n\n", ThongKe(oto, n, 'B'));

    Sort(oto, 0, n - 1);
    fprintf(fout, "3 oto trong tai nho nhat la:\n");
    Output(oto, 3);
    


    fclose(fin);
    fclose(fout);
    return 0;
}
