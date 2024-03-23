/*xây dựng cấu trúc dãy nguyên, trong đó có các thành phần gồm:
số phần tử và một con trỏ chứa các hệ số của dãy số;
và các hàm nhập dãy số, tìm max dãy số, tính tổng dãy số, tính trung bình công các phần tử lớn hơn x
viết hàm main() để
1, nhập vào một dãy số nguyên
2, tìm max dãy số
3, tính tổng dãy số
4, nhập một số thực x, tính trung bình cộng các phần tử lớn hơn x.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

struct Arr
{
    int n;
    int *arr;
};

void Input(int *x){
    scanf("%d", x);
}

void Input1(int **arr, int n){
    *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", *arr + i);
    }
}

void Input2(Arr *a){
    a->arr = (int*) malloc(a->n * sizeof(int));
    for (int i = 0; i < a->n; i++)
    {
        scanf("%d", a->arr + i);
    }
}

void Input3(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    
}

void Output(Arr a){
    for (int i = 0; i < a.n; i++)
    {
        printf("%d ", *(a.arr + i));
    }
}

int Max(Arr a){
    int max = *a.arr;
    for (int i = 0; i < a.n; i++)
    {
        max = (max < *(a.arr + i))? *(a.arr + i):max;
    }
    return max;
}

int Sum(Arr a){
    int sum = 0;
    for (int i = 0; i < a.n; i++)
    {
        sum += *(a.arr + i);
    }
    return sum;
}

void *List(Arr a, Arr *b, int x){
    b->n = 0;
    b->arr = (int*) malloc(a.n * sizeof(int));
    for (int i = 0; i < a.n; i++)
    {
        if (*(a.arr + i) > x)
        {
            *(b->arr + b->n) = *(a.arr + i);
            b->n ++;
        }
    }
}

int main()
{
    Arr a;
    
    printf("nhap so phan tu cos trong day: ");
    Input(&a.n);

    printf("nhap gia tri cho cac phan tu trong day: ");
    //Input1(&a.arr, a.n);
    Input2(&a);
    //a.arr = (int*) malloc(a.n * sizeof(int));
    //Input3(a.arr, a.n);

    printf("day so ban vua nhap la: ");
    Output(a);

    printf("\n\ngia tri lon nhat trong day so la: %d\n\n", Max(a));

    printf("tong cac so trong day la: %d\n\n", Sum(a));

    int count;
    int x;
    printf("nhap x: ");
    Input(&x);
    Arr list;
    List(a, &list, x);
    if (list.n)
    {
        printf("tong gia tri > %d la: %d", x, Sum(list));
    }
    else
        printf("khong co gia tri nao lon hon x");

    free(list.arr);
    free(a.arr);
    return 0;
}
