// Nhập tọa độ của n điểm trên mặt phẳng. Tính độ dài đường gấp khúc đi từ điểm đầu lần 
//lượt đến điểm cuối
#include<stdio.h>
#include<math.h>
//ham nhap n
int nhap_n()
{
	int n;
	scanf("%d",&n);
	return n;
}
//ham in ra
float do_dai(int n, float x[], float y[])
{
	float toado,s=0;
	for (int i = 0; i < n; i++)
	{
		toado=sqrt(pow(x[i]-x[i+1],2)+pow(y[i]-y[i+1],2));
		s+=toado;
	}
	return s;
}
//ham nhap mang
void nhap_mang(int n,float x[],float y[])
{
	for (int i = 0; i < n; i++)
    {
        printf("toa do diem thu %d la: ",i+1);
        scanf("%f%f",&x[i],&y[i]);
    }	
}
//ham chinh
int main()
{
    printf("nhap so diem tren mat phang: ");
    int n=nhap_n();
    printf("nhap toa do cac diem: \n");
    float x[n],y[n];
    nhap_mang(n,x,y);
    printf("do dai quang duong duong gap khuc di duoc la: %f",do_dai(n,x,y));
    return 0;
}
