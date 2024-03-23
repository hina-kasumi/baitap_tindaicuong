/*xây dựng cấu trúc 
CTY gồm các phần mã công ty, tên công ty, năm thành lập, số nhân viên và các hàm cần thiết
viết hàm main thực hiện
1, nhập vào n công ty và in ra màn hình
2, tìm các công ty thành lập lâu năm nhất
3, in ra các công ty nhiều hơn X Devloper và thành lạp trước năm Y, với x, x nhập từ bàn phím*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")
struct Company
{
    int code;
    char name[20];
    int year;
    int soNhanVien;
};

void Input (int *x){
    scanf("%d", x);
}

void Input(Company **cty, int n){
    *cty = (Company*) malloc(n * sizeof(Company));
    for (int i = 0; i < n; i++)
    {
        printf("ma cong ty: ");
        scanf("%d", &(*cty + i)->code);

        printf("ten cong ty: ");
        fflush(stdin);
        gets((*cty + i)->name);

        printf("nam thanh lap: ");
        scanf("%d", &(*cty + i)->year);

        printf("so nhan vien: ");
        scanf("%d", &(*cty + i)->soNhanVien);
        endl;
    }
}


void Output(Company *cty, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%10d|%10s|%10d|%10d\n", (cty + i)->code, (cty + i)->name, (cty + i)->year, (cty + i)->soNhanVien);
    }
}

int Min(Company *cty, int n){
    int min = cty->year;
    for (int i = 0; i < n; i++)
    {
        if (min > (cty + i)->year)
        {
            min = (cty + i)-> year;
        }
    }
    return min;
}

Company *CtyLauNhat(Company *cty, int n, int *count){
    int min = Min(cty, n);
    Company *list = (Company*) malloc(n * sizeof(Company));
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((cty + i)->year == min)
        {
            *(list + *count) = *(cty + i);
            (*count)++;
        }
    }
    return list;
}

Company *Find(Company *cty, int n, int *count, int x, int y){
    Company *list = (Company*) malloc(n * sizeof(Company));
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((cty + i)->soNhanVien > x && (cty + i)->year < y)
        {
            *(list + *count) = *(cty + i);
            (*count)++;
        }
    }
    return list;
}

int main()
{
    int n;
    printf("nhap so cong ty can quan ly: ");
    Input(&n);

    Company *cty;
    printf("nhap thong tin cua cac cong ty:\n");
    Input(&cty, n);

    printf("danh sach cong ty ban vua nhap:\n");
    Output(cty, n);

    int count;
    Company *list = CtyLauNhat(cty , n, &count);
    printf("danh sach cong ty lau nhat: \n");
    Output(list, count);

    printf("nhap so nhan vien: ");
    int x;
    Input(&x);
    int y;
    printf("nhap nam thanh lap: ");
    Input(&y);
    list = Find(cty, n , &count, x, y);
    Output(cty, count);

    free(cty);
    free(list);
    return 0;
}