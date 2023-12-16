//tim uoc chung lon nhat cua 2 so nguyen duong
#include<stdio.h>
int uoc_chung(int a,int b)
{
	int r = a%b;
	if(r==0) return b;
	return uoc_chung(a,r);
}
main()
{
	int a,b,c;
	printf("nhap 2 so nguyen duong muon tim uoc chung ");
	scanf("%d%d",&a,&b);
	printf("uoc chung lon nhat cua %d va %d la %d",a,b,uoc_chung(a,b));
}
