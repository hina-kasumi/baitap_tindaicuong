// Nhập tọa độ của n điểm trên mặt phẳng. Tính độ dài đường gấp khúc đi từ điểm đầu lần 
//lượt đến điểm cuối
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("nhap so diem tren mat phang: ");
    scanf("%d",&n);
    printf("nhap toa do cac diem: \n");
    float x[n],y[n];
    for (int i = 0; i < n; i++)
    {
        printf("toa do diem thu %d la: ",i+1);
        scanf("%f%f",&x[i],&y[i]);
    }
    float toado,s=0,quangduong;
    for (int i = 0; i < n-1; i++)
    {
        toado=sqrt(pow(x[i]-x[i+1],2)+pow(y[i]-y[i+1],2));
        s+=toado;
        quangduong=toado;
        printf("do dai quang duong thu %d la: %f\n",i+1,quangduong);
    }
    printf("do dai quang duong duong gap khuc di duoc la: %f",s);
    
    return 0;
}
