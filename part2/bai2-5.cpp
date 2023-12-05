#include<stdio.h>
#include<math.h>
int main()
{
    int n,a[3],max=0,dirmax;
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
    for (int i = 0; i < 3; i++)
    {
        if(max<a[i]) 
        {
            max=a[i];
            dirmax=i+1;
        }
    }
    printf("phan tu lon nhat la %d o vi tri thu %d",max,dirmax);
}