//Viết chương trình nhập vào số nguyên dương, in ra số chẵn hay lẻ.
#include<stdio.h>
int main()
{
    int x;
    back: printf("nhap mot so nguyen duong: ");
    scanf("%d",&x);
    if(x<1) goto back;
    if(x%2==0) printf("day la so chan.");
    else printf("day la so le.");
    return 0;
}