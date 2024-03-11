/*3. Viết chương trình nhập vào thời gian của một công việc nào đó tính bằng giây. Hãy chuyển đổi và in ra
màn hình thời gian trên dưới dạng bao nhiêu giờ, bao nhiêu phút, bao nhiêu giây*/
#include<stdio.h>
int main()
{
    back: printf("thoi gian lam viec tinh bang giay = ");
    int seccond;
    scanf("%d",&seccond);
    if(seccond<0) goto back;
    int gio=seccond/3600,phut=seccond/60;
    printf("%d h, %d m, %d",gio,phut-gio*60,seccond-phut*60);
    return 0;
}
