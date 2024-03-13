#include<stdio.h>
#include<stdlib.h>
struct Diem{
	float x;
	float y;
};
void nhap(int n,Diem **diem){
	*diem = (Diem*) malloc(100 * sizeof(Diem));
	for (int i=0;i<n;i++){
		printf ("Nhap hoanh do va tung do diem %d: ",i);
		scanf ("%f%f", &(*diem + i)->x, &(*diem + i)->y);
	}
}
void xuat(int n,Diem **diem){
	for (int i=0;i<n;i++){
		printf ("(%.2f,%.2f) ",(*diem + i)->x, (*diem + i)->y);
	}
}


int main(){
	int n;
	Diem *diem;
	printf ("Nhap n: ");
	scanf ("%d",&n);
	diem=(Diem*)(malloc((n+1)* sizeof(Diem)));
	nhap(n, &diem);
	printf ("Day diem vua nhap: ");
	xuat(n,&diem);

	free(diem);
}