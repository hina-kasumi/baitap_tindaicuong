/*33, Nhập dãy n số thực từ bàn phím. In các số dương trên một dòng và các số âm trên một 
dòng. Nhập từ bàn phím số thực M, đếm và in ra màn hình các số lớn hơn M*/
void show(int dem)
{
    if (dem==0) printf("khong co gia tri nao thoa man");
}
#include<stdio.h>
int main()
{
    int n,dem,i;
    //nhap n
    back: printf("nhap so n: ");
    scanf("%d",&n);
    if(n<=0) goto back;
    //nhap day
    printf("nhap day %d so thuc: ",n);
    float day[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%f",&day[i]);
    }
    //dem so am
    dem=0;
    printf("so am trong day la: \n");
    for ( i = 0; i < n; i++)
    {
        if (day[i]<0){printf("%f ",day[i]);dem++;}
    }
    show(dem);
    //dem so duong
    dem=0;
    printf("\nso duong trong day la: \n");
    for ( i = 0; i < n; i++)
    {
        if (day[i]>0){printf("%f ",day[i]);dem++;}
    }
    show(dem);
    //nhap m
    printf("\nnhap so thuc m: ");
    float m;
    scanf("%f",&m);
    //kiem tra gia gia tri dem
    dem=0;
    for ( i = 0; i < n; i++)
    {
        if (day[i]>m) dem++;
    }
    if(dem==0) goto skip;
    //so lon hon m
    printf("cac so trong day lon hon %f la: \n",m);
    for ( i = 0; i < n; i++)
    {
        if (day[i]>m) printf("%f ",day[i]);
    }
    if(dem!=0)printf("\nco tong cong %d so lon hon %f",dem,m);
    skip: show(dem);
    return 0;
}