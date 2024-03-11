//3. Tính giai thừa của số nguyên dương n.
#include<stdio.h>
int main()
{
    int n,vo_van_hoa=0,result=1;
    printf("nhap so nguyen duong muon tim giai thua: ");

    back: scanf("%d",&n);
    if(n<1)
    {
        printf("tau bao la so nguyen duong co ma.\n");
        vo_van_hoa++;
        if(vo_van_hoa>=5) printf("may nhon voi tau a.\n");
        goto back;
    }
    for (int i = 1; i <= n; i++) result*=i;
    printf("giai thua cua %d la: %d",n,result);
    return 0;
}
