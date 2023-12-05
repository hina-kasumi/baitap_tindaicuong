/*15. Viết chương trình nhập vào một số nguyên n gồm ba chữ số. (Giả sử 3 chữ số của n khác nhau) Xuất 
ra màn hình chữ số lớn nhất ở vị trí nào?*/
#include<stdio.h>
int main()
{
    //nhap so nguyen n co 3 chu so
    short n,a[3],max=0,dirmax;
    printf("nhap mot so tu nhien co 3 chu so: ");
    scanf("%hd", &n);
    //tim gia tri tung phan tu trong so nguyen co 3 chu so n
    //truong hop n>99
    if(n>99)
    {
        a[0]=(n-(n%100))/100;
        a[1]=(n-a[0]*100-(n%10))/10;
        a[2]=n-a[0]*100-a[1]*10;
    }
    //truong hop n<-99
    if(n<-99)
    {
        a[0]=(n-(n%100))/100;
        a[1]=-(n-a[0]*100-(n%10))/10;
        a[2]=-(n-a[0]*100+a[1]*10);
    }
    //tim vi tri pham tu lon nhat
    for (int i = 0; i < 3; i++)
    {
        if (max<a[i])
        {
            max=a[i];
            dirmax=i+1;
        }
    }
    //in ra ket qua
    printf("vi tri cua phan tu lon nhat trong day la: ");
    if(dirmax==1) printf("hang tram.");
    else if(dirmax==2) printf("hang chuc.");
    else printf("hang don vi.");
    return 0;
}
