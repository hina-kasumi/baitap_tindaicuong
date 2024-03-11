#include<stdio.h>
#include<math.h>
void in(int arr[][1000],int hang,int cot)
{
	printf("%d ",arr[hang][cot]);
}
main()
{
	int m,n;
	printf("nhap kich co cua ma tran: ");
	scanf("%d%d",&m,&n);
	int arr[m][1000];
	printf("nhap gia tri cho cac phan tu trong ma tran: \n");
	for(int hang=0;hang<n;hang++)
	{
		for(int cot=0;cot<n;cot++)
		{
			scanf("%d",&arr[hang][cot]);
		}
	}
	printf("ma tran ban vua nhap: \n");
	for(int hang=0;hang<n;hang++)
	{
		for(int cot=0;cot<n;cot++)
		{
			in(arr,hang,cot);
		}
		printf("\n");
	}
	//1,
	int tong=0,max=arr[0][0];
	for(int hang=0;hang<n;hang++)
	{
		for(int cot=0;cot<n;cot+=2)
		{
			tong+=arr[hang][cot];
			max=(max<arr[hang][cot])? arr[hang][cot]:max;
		}
	}
	printf("\ntong cac phan tu thuoc cot le = %d\n",tong);
	//2,
	float dem=0;
	tong=0;
	for(int hang=0;hang<n;hang++)
	{
		for(int cot=0;cot<n;cot++)
		{
			if(arr[hang][cot]%2==0 && arr[hang][cot]>10)
			{
				tong+=arr[hang][cot];
				dem++;
			}
		}
	}
	if(dem>0)printf("trung binh cong cac phan tu duong lon hon 10 trong am tran: %f\n",tong/dem);
	else printf("khong ton tai\n");
	//3,
	printf("gia tri lon nhat trong ma tran = %d",max);
}
