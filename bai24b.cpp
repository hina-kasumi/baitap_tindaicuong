#include<stdio.h>
int main()
{
	float a,n,tu,mau,ketqua;
	scanf("%f",&n);
	for(float i=0;i<=n;i++)
	{
		tu=2*i+1;
		printf("gia tri tu thu %.0f la: %f\n",i+1,tu);
		mau=1;
		for(a=1;a<=i+1;a++)
		{
			mau*=a;
			printf("gia tri mau thu %.0f la: %f\n",i+1,mau);
		}
		ketqua+=tu/mau;
		printf("gia tri ketqua thu %.0f la: %f\n",i+1,ketqua);
	}
	printf("ket qua cuoi cung la: %f",ketqua);
}
