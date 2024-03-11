//2. Viết chương trình nhập vào giờ, phút và giây, hãy đổi sang giây và in kết quả ra màn hình.
#include<stdio.h>
int main()
{
    back: printf("gio phut giay ");
    int hour,minute,second;
    scanf("%d%d%d",&hour,&minute,&second);
    if(hour<0 || minute<0 || second<0) goto back;
    printf("= %d",second+minute*60+hour*3600);
    return 0;
}
