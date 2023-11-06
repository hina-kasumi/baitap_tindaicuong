#include<stdio.h>
int main()
{
	int n,dem;
	printf("nhap so n ");
	scanf("%d",&n);
	float phantu[n],tong;
	for(int i=0;i<n;i++)
	{
		scanf("%f",&phantu[i]);
	}
	tong=0;
	dem=0;
	for(int i=0;i<n;i++)
	{
		if(phantu[i]<=0)
		{
			tong+=phantu[i];
			dem++;
		}
	}
	printf("%f\n",tong);
	printf("%f",tong/dem);
}
