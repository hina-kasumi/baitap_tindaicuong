/*Câu 2: Định nghĩa một cấu trúc Sinh viên gồm các thành phần: Mã SV, tên SV, điểm, 
trường (giả sử có 3 trường là 1, 2, 3). Nhập, xuất n sinh viên.
- Thống kê tổng số điểm của từng trường, cho biết trường nào có điểm cao nhất.
- Nhập vào tên sinh viên, in ra màn hình thông tin của sinh viên đó.
- Tìm sinh viên có điểm cao nhất*/
#include<stdio.h>
#include<string.h>
#define nn printf("\n")
struct sinh_vien
{
    int MSV;
    char name[20],school[20];
    float diem;
};

void in(sinh_vien sv[],int i)
{
    printf("ma sinh vien: %d\n",&sv[i].MSV);
    printf("ten: %s\n",sv[i].name);
    printf("diem: %f\n",sv[i].diem);
    printf("truong: %s\n\n",sv[i].school);
}

int main()
{
    int n;
    printf("nhap so sinh vien can quan ly: ");
    scanf("%d",&n);
    sinh_vien sv[n];
    printf("nhap thong tin sinh vien\n");
    float diem=0;
    for (int i = 0; i < n; i++)
    {
        printf("nhap ma sinh vien: ");
        scanf("%d",&sv[i].MSV);
        printf("nhap ten: ");
        fflush(stdin);
        gets(sv[i].name);
        printf("nhap diem: ");
        scanf("%f",&sv[i].diem);
        printf("nhap truong: ");
        fflush(stdin);
        gets(sv[i].school);
        if (diem < sv[i].diem) diem = sv[i].diem;
    }
    float tong_diem,tong_max=0,check=n;
    for (int i = 0; i < check; i++)
    {
        int tong_diem = 0; 
        for (int j = n-1; j >= i; j--)
        {
            if (strcmp(sv[i].school,sv[j].school))
            {
                tong_diem+=sv[j].diem;
                if (tong_max<tong_diem) tong_max=tong_diem;
                check=j;
            }
        }
    }
    printf("truong co tong diem cao nhat la: %f",tong_max);
    return 0;
}
