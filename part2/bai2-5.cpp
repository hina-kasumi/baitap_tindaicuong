/*Viết chương trình nhập vào một số nguyên n gồm ba chữ số. xuất ra màn hình chữ số lớn nhất ở vị trí nào?*/
#include<stdio.h>
int main()
{
    char n[4];
    gets(n);
    int maxx = -1, vitri = 0;
    for(int i = 0; i <= 3; i++){
        if(n[i]> maxx){
            maxx = n[i];
            vitri = i+1;
        }
    }
        printf("%c %d", maxx, vitri);
    
    return 0;
}
