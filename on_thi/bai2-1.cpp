#include<stdio.h>
#include<math.h>
struct do_thi
{
	float x,y;
};
void in(do_thi toa_do[],int i)
{
	printf("(%f,%f) ",toa_do[i].x,toa_do[i].y);
}
main()
{
	int n,dem=0,dir;
	float max=0;
	printf("nhap n: ");
	scanf("%d",&n);
	do_thi toa_do[n];
	printf("nhap toa do: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&toa_do[i].x);
		scanf("%f",&toa_do[i].y);
		if(toa_do[i].x<0 && toa_do[i].y<0) dem++;
		float a=sqrt(pow(toa_do[i].x,2)+pow(toa_do[i].y,2));
		if(max<a)
		{
			max=a;
		} 
	}
	printf("cac diem ma ban da nhap: ");
	for(int i=0;i<n;i++)
	{
		in(toa_do,i);
	}
	//1,
	printf("\nco %d diem thuoc goc phan tu thu 3.\n",dem);
	//2,
	printf("nhung diem xa O nhat: ");
	for(int i=0;i<n;i++)
	{
		float a=sqrt(pow(toa_do[i].x,2)+pow(toa_do[i].y,2));
		if(a==max)
		{
			in(toa_do,i);
		}
	}
	//3,
	dem=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(toa_do[i].y*toa_do[j].y<0) dem++;
		}
	}
	printf("\nco %d doan thang cat truc hoang.",dem);
}
