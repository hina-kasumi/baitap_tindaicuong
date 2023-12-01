#include<stdio.h>
#include<math.h>
main()
{
	int n;
	float x,tu,mau,result;
	back: printf("nhap nguyen duong n: ");
	scanf("%d",&n);
	if(n<=0)goto back;
	printf("nhap so thuc x: ");
	scanf("%f",&x);
	result=exp(x);
	for(int i=1;i<=n;i++)
	{
		tu=x+i;
		mau=i+1;
		result+=tu/mau;
	}
	
	printf("gia tri cua bieu thuc la: %f",result);
}
