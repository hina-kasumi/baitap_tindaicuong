/*nhập giá trị cho 2 mảng
1, in mảng
2, tìm giá trị lớn nhất của dãy a và b
3, sắp xếp và in ra*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
void openFile(FILE **fin){
    *fin = fopen("input.txt", "r");
}

void Input(int **a, int n, FILE *fin){

    *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(fin, "%d", *a + i);
}
void Output(int *a, int n){
    if(n == 0)
        return;
    Output(a, n - 1);
    printf("%d ", *(a + n - 1));
}

int Max(int *a, int n){
    if(n == 0)
        return *a;
    n--;
    int max = Max(a, n);
    return (max < a[n])? a[n]:max;
}
void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}
void QuickSort(int *a, int low, int high){
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j <= high; j++)
        {
            if (a[j] < pivot){
                i++;
                swap(a + j, a + i);
            }
        }
        swap(a + i + 1, a + high);
        int pi = i + 1;
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
    
}
int main()
{
    FILE *fin;
    openFile(&fin);

    int *a, n;
    fscanf(fin, "%d", &n);
    int *b, m;
    fscanf(fin, "%d", &m);
    Input(&a, n, fin);
    Input(&b, m, fin);

    printf("mang thu nhat: ");
    Output(a, n);
    endl;
    printf("mang thu hai: ");
    Output(b, m);
    endl;

    printf("\ngia tri lon nhat mang a al: %d\n", Max(a, n));
    printf("gia tri lon nhat mang a al: %d\n\n", Max(b, m));

    QuickSort(a, 0, n - 1);
    QuickSort(b, 0, m - 1);

    printf("mang thu nhat sau khi sap xep: ");
    Output(a, n);
    endl;
    printf("mang thu hai sau khi sap xep: ");
    Output(b, m);

    free(a);
    free(b);

    fclose(fin);
    return 0;
}
