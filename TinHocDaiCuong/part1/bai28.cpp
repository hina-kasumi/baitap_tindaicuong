#include<stdio.h>
#include<math.h>
main()
{
	int n;
	float x,phantu,s;
	back: printf("nhap nguyen duong n: ");
	scanf("%d",&n);
	if(n<=0)goto back;
	printf("nhap so thuc x: ");
	scanf("%f",&x);
	phantu=0;
	float a[n],mau,tu;
	printf("nhap so thuc day a: ");
	for(int i=0;i<n;i++){scanf("%f",&a[i]);}
	for(int i=0;i<n;i++)
	{
		mau=1;
		tu=pow(-1,i+1)*pow(x,i+1);
		tu=tu*a[i];
		printf("phan tu tu %d co gia tri la: %f\n",i+1,tu);
		for(int j=1;j<=i+1;j++)
		{
			mau*=j;
			
		}
		printf("phan tu %d co gia tri la: %f\n",i+1,mau);
		s+=tu/mau;
	}
	printf("gia tri s la: %f",s);
}
