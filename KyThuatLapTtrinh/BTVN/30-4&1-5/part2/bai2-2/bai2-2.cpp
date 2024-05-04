/*struct nhân viên: 
    - MNV(mã nhân viên).
    - HT (họ tên).
    - lương
    - PHONG (phòng ban)
1, tính lương trung bình từng phòng và phòng nào thấp nhất
2, in danh sách theo giảm dần của lương
3, lưu vào tệp kq.txt*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fendl fprintf(fin, "\n")
void openFile(FILE **fin, FILE **fout){
    *fin = fopen("input.txt", "r");
    *fout = fopen("kq.txt", "w");
}

struct NhanVien
{
    int MNV;
    char name[20];
    float salary;
    char phong[20];
};

void Input(NhanVien *nv, int n, FILE *fin, FILE *fout){
    for (int i = 0; i < n; i++)
    {
        fscanf(fin, "%d ", &(nv + i)->MNV);

        fgets((nv + i)->name, 20, fin);
        (nv + i)->name[strlen((nv + i)->name) - 1] = '\0';

        fscanf(fin, "%f ", &(nv + i)->salary);

        fgets((nv + i)->phong, 20, fin);
        (nv + i)->phong[strlen((nv + i)->phong) - 1] = '\0';
    }
}

void Output(NhanVien nv, FILE *fout){
    fprintf(fout, "%d|%10s|%10.2f|%10s\n", nv.MNV, nv.name, nv.salary, nv.phong);
}
void Output(NhanVien *nv, int n, FILE *fout){
    for (int i = 0; i < n; i++)
    {
        Output(*(nv + i), fout);
    }
}

//1, tính lương trung bình từng phòng và phòng nào thấp nhất
NhanVien *luongtb(NhanVien *nv, int n, int *cnt){
    *cnt = 0;
    bool checked[n] = {0};
    NhanVien *list = (NhanVien*) malloc(n * sizeof(NhanVien));
    for (int i = 0; i < n; i++)
    {
        if(!checked[i]){
            *(list + i) = *(nv + i);
            int tmp = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (!strcmp((nv + i)->phong, (nv + j)->phong)){
                    checked[j] = true;
                    (list + *cnt)->salary += (nv + j)->salary;
                    tmp++;
                }
            }
            (list + *cnt)->salary /= tmp;
            (*cnt)++;
        }
    }
    
    return list;
}

void swap(NhanVien *a, NhanVien *b){
    NhanVien x = *a;
    *a = *b;
    *b = x;
}
void QuickSort(NhanVien *nv, int lo, int hi){
    if(lo < hi){
        float pivot = (nv + hi)->salary;
        int i = lo - 1;
        for (int j = lo; j <= hi; j++)
        {
            if((nv + j)->salary > pivot){
                i++;
                swap(nv + i, nv + j);
            }
        }
        swap(nv + i + 1, nv + hi);
        int pi = i + 1;

        QuickSort(nv, lo, pi - 1);
        QuickSort(nv, pi + 1, hi);
    }
}

int main()
{
    FILE *fin, *fout;
    openFile(&fin, &fout);

    int n; 
    fscanf(fin, "%d", &n);
    
    NhanVien *nv = (NhanVien*) malloc(n * sizeof(NhanVien));
    Input(nv, n, fin, fout);
    fprintf(fout, "danh sach nhan vien:\n");
    Output(nv, n, fout);

    int cnt;
    NhanVien *list = luongtb(nv, n, &cnt);
    fprintf(fout, "\nluong trung binh cua cac phong ban la:\n");
    for (int i = 0; i < cnt; i++)
        fprintf(fout, "%s: %.3f\n", list[i].phong, list[i].salary);

    fprintf(fout, "\ndanh sach nhan vien sau khi sap xep la:\n");
    QuickSort(nv, 0, n - 1);
    Output(nv, n, fout);
    

    fclose(fin);
    fclose(fout);
    free(nv);
    free(list);
    return 0;
}
