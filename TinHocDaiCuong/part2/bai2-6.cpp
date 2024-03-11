/*. Viết chương trình nhập vào số nguyên n gồm ba chữ số. Xuất ra màn hình theo thứ tự tăng dần của các 
chữ số.*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,a[3];
    back: scanf("%d",&n);
    if(n<100 && n>-100) goto back;
    //phan tich gia tri tung phan theo he 10
    //truong hop duong
    if (n>99)
    {
        a[0]=(n-(n%100))/100;
        a[1]=(n-a[0]*100-(n%10))/10;
        a[2]=n-a[0]*100-a[1]*10;
    }
    //truong hop am
    else if (n<-99)
    {
        a[0]=(n-(n%100))/100;
        a[1]=(-n+a[0]*100+(n%10))/10;
        a[2]=-n+a[0]*100-a[1]*10;
    }
    
    //sap xep cac phan tu theo gia tri tu be den lon
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    //in ra ket qua
    for (int i = 0; i < 3; i++)printf("%d ",a[i]);
    return 0;
}
