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
	tu=1;mau=0;
	for(int i=1;i<=n;i++)
	{
		tu+=(i*pow(x,i));
		mau+=n;
	}
	result=tu/mau;
	printf("gia tri cua bieu thuc la: %f",result);
}
