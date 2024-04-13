#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define endl printf("\n")
#define endll printf("\n\n")

int NhapGiaTriTuFile(){
    FILE *file; //khai báo con trỏ tập tin
    int num;
    file = fopen("input.txt", "r");
    //kiểm tra xem tập tin có mở thành công không
    if (file == NULL)
    {
        printf("khong the mo tap tin.\n");
        return 0;
    }
    //đọc dữ liệu từ tập tin
    fscanf(file, "%d", &num);
    //dóng file
    fclose(file);

    return num;
}

void InGiaTriRaFile(int num){
    FILE *file;
     //mở tập tin để ghi
    file = fopen("output.txt", "w");
    //kiểm tra xem tập tin có mở thành công không
    if (file == NULL)
    {
        printf("khong the mo tap tin.\n");
        return;
    }

    //ghi dữ liệu vào tập tin
    fprintf(file, "%d", num);
    //đóng tập tin sau khi ghi
    fclose(file);
}
int main()
{
    

    InGiaTriRaFile(NhapGiaTriTuFile());
    return 0;

}
