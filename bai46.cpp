#include<stdio.h>
#include<math.h>
main()
{
	back: printf("nhap gia tri n: ");
	int n;
	scanf("%d",&n);
	if(n<1) goto back;
	float x,s;
	printf("nhap gia tri x:");
	scanf("%f",&x);
	s=2005;
	for(int i=1;i<=n;i++)
	{
		s+=pow(-1,i+1)*pow(x,i)/i;
	}
	printf("%f",s);
}
