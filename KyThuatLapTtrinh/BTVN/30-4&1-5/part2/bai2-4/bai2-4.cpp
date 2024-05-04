/*Bài 4. Danh sách sinh viên (SV) gồm:
    Họ tên, 
    Quê quán, 
    Học lực (Giả sử chỉ có ba loại học lực là A, B, C). 
Hãy viết hàm thực hiện các yêu cầu sau: 
1. Đọc danh sách sinh viên từ tệp trên. 
2. Xuất thông tin của từng sinh viên ra màn hình. 
3. Tìm theo họ tên thông tin một sinh viên trong danh sách. 
4. Đếm số sinh viên đạt học lực loại A 
5. Nhập vào một loại học lực từ bàn phím, in ra màn hình thông tin sinh viên đạt học lực vừa nhập*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

struct SinhVien
{
    char name[20];
    char hometown[20];
    char hocLuc;
};
void Input(SinhVien **sv, int n, FILE *fin){
    *sv = (SinhVien*) malloc(n * sizeof(SinhVien));
    for (int i = 0; i < n; i++)
    {
        fgets((*sv + i)->name, 20, fin);
        (*sv)[i].name[strlen((*sv)[i].name) - 1] = '\0';

        fgets((*sv + i)->hometown, 20, fin);
        (*sv)[i].hometown[strlen((*sv)[i].hometown) - 1] = '\0';

        fscanf(fin, "%c ", &(*sv + i)->hocLuc);
    }
}

void Output(SinhVien sv){
    printf("%10s|%10s|%2c\n", sv.name, sv.hometown, sv.hocLuc);
}

void Output(SinhVien *sv, int n){
    if (n == 0)
        return;
    Output(sv, n - 1);
    Output(sv[n - 1]);
}

//3. Tìm theo họ tên thông tin một sinh viên trong danh sách. 
int timSV(SinhVien *sv, int n, char *search){
    for (int i = 0; i < n; i++)
    {
        if(!strcmpi(sv[i].name, search))
            return i;
    }
    return -1;
}

//4. Đếm số sinh viên đạt học lực loại A 
int cntA(SinhVien *sv, int n, char loai){
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if ((sv + i)->hocLuc == loai)
            res++;
    }
    return res;
}

//5. Nhập vào một loại học lực từ bàn phím, in ra màn hình thông tin sinh viên đạt học lực vừa nhập
SinhVien *List(SinhVien *sv, int n, char hl, int *cnt){
    *cnt = 0;
    SinhVien *list = (SinhVien*) malloc(n * sizeof(SinhVien));
    for (int i = 0; i < n; i++)
    {
        if ((sv + i)->hocLuc == hl)
        {
            list[*cnt] = sv[i];
            (*cnt)++;
        }
    }
    return list;
}

int main()
{
    FILE *fin = fopen("input.txt", "r");
    int n;
    fscanf(fin, "%d ", &n);

    SinhVien *sv;
    Input(&sv, n, fin);
    fclose(fin);
    printf("danh sach sinh vien:\n");
    Output(sv, n);
    endl;

    //3. Tìm theo họ tên thông tin một sinh viên trong danh sách.
    printf("hay nhap ten sinh vien can tim: ");
    char search[20];
    gets(search);
    printf("day la thong tinh sinh vien ban tim:\n");
    Output(sv[timSV(sv, n, search)]);
    endl;
    
    //4. Đếm số sinh viên đạt học lực loại A
    printf("co %d sinh vien dat loai A.\n\n", cntA(sv, n, 'A'));

    //5. Nhập vào một loại học lực từ bàn phím, in ra màn hình thông tin sinh viên đạt học lực vừa nhập
    int cnt;
    char hl;
    printf("nhap hoc luc: ");
    scanf("%c", &hl);
    SinhVien *list = List(sv, n, hl, &cnt);
    printf("danh sach sinh vien dat hoc luc %c:\n", hl);
    Output(list, cnt);

    
    free(sv);
    return 0;
}
