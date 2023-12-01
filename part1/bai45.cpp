#include<stdio.h>
main()
{
	int n;
	back: printf("nhap n: ");
	scanf("%d",&n);
	if(n<1) goto back;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int chan=0,le=0,max;
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0) chan++;
		else le++;
		if(arr[i]%2==0) max=arr[i]; 
	}
	if(le==chan) printf("le(%d) = chan(%d)",le,chan);
	else if(le<chan) printf("le(%d) < chan(%d)",le,chan);
	else printf("le(%d) > chan(%d)",le,chan);
	//tim so chan lon nhat
	for(int i=0;i<n;i++)
	{
		if(max<arr[i] && arr[i]%2==0) max=arr[i];
	}
	printf("\nso chan lon nhat la: %d",max);
}
