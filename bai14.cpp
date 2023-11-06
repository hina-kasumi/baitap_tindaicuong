#include<stdio.h>
main()
{
	int n,i;
	float tich=1,tong=0;
	scanf("%d",&n);
	float phantu[n];
	for(i=0;i<n;i++)
	{
		scanf("%f",&phantu[i]);
	}
	for(i=0;i<n;i++)
	{
		tich*=phantu[i];
		tong+=phantu[i];
	}
	printf("%f\n",tich);
	printf("%f",tong);
}
