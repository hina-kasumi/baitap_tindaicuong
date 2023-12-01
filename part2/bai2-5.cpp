/*Viết chương trình nhập vào một số nguyên n gồm ba chữ số. xuất ra màn hình chữ số lớn nhất ở vị trí nào?*/
#include <stdio.h>
int main()
{
    char n[5];
    back: gets(n);
    if(n[0]=='0' || n[1]=='0') goto back;
    int maxx = -1, vitri = 0;
    if (n[0] != '-')
    {
        for (int i = 0; i <= 3; i++)
        {
            if (n[i] > maxx)
            {
                maxx = n[i];
                vitri = i + 1;
            }
        }
    }
    else
    {
        for (int i = 2; i < 4; i++)
        {
            if (n[i] > maxx)
            {
                maxx = n[i];
                vitri = i;
            }
        }
    }
    printf("%c %d", maxx, vitri);
    return 0;
}
