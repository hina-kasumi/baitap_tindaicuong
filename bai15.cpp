#include<stdio.h>
main()
{
	int n,i;
	scanf("%d",&n);
	int phantu[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&phantu[i]);
	}
	printf("so chan: ");
	for(i=0;i<n;i++)
	{
		if(phantu[i]%2==0)printf("%d ", phantu[i]);
	}
	printf("\nso le: ");
	for(i=0;i<n;i++)
	{
		if(phantu[i]%2!=0)printf("%d ", phantu[i]);
	}
}
