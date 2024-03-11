#include<stdio.h>

void show(int *a)
{
	scanf("%d",a);
}

int main()
{
	int a;
	show(&a);
	printf("%d",a);
	return 0;
}
