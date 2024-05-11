#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")



struct BenhNhan{
	char name[20];
	char benh;
	int namMac;
	int namXuat;
};

void Input(BenhNhan *bn, int n, FILE *f){
	for(int i = 0;i < n; i++){
		fgets((bn + i)->name, 20, f);
		(bn + i)->name[strlen((bn + i)->name) - 1] = '\0';
		
		fscanf(f, "%c%d%d ", &(bn + i)->benh, &(bn + i)->namMac, &(bn + i)->namXuat);
	}
}

void Output(BenhNhan *bn, int n){
	FILE *a = fopen("BenhA.txt", "w+");
	FILE *b = fopen("BenhB.txt", "w+");
	FILE *c = fopen("BenhC.txt", "w+");
	for(int i = 0;i < n; i++){
		if(bn[i].benh == 'A')
			fprintf(a, "%10s|%5c|%5d|%5d\n",bn[i].name, bn[i].benh, bn[i].namMac, bn[i].namXuat);
		else if(bn[i].benh == 'B')
			fprintf(b, "%10s|%5c|%5d|%5d\n",bn[i].name, bn[i].benh, bn[i].namMac, bn[i].namXuat);
		else if(bn[i].benh == 'C')
			fprintf(c, "%10s|%5c|%5d|%5d\n",bn[i].name, bn[i].benh, bn[i].namMac, bn[i].namXuat);
	}
	fclose(a);
	fclose(b);
	fclose(c);
}

void sort(BenhNhan *bn, int n){
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(bn[i].namMac > bn[j].namMac){
				BenhNhan x = bn[i];
				bn[i] = bn[j];
				bn[j] = x;
			}
		}
	}
}

void OutTer(BenhNhan *bn, int n){
	for (int i = 0; i < n; i++)
	{
		printf("%10s|%5c|%5d|%5d\n",bn[i].name, bn[i].benh, bn[i].namMac, bn[i].namXuat);
	}
}

float tgTb(BenhNhan *bn, int n){
	float res = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (bn[i].benh == 'C'){
			res += bn[i].namXuat - bn[i].namMac;
			cnt++;
		}
	}
	return res / cnt;
}

int main(){
	FILE *f = fopen("input.txt", "r");
	int n;
	fscanf(f, "%d ", &n);
	BenhNhan *bn = (BenhNhan*) malloc(n * sizeof(BenhNhan));
	Input(bn, n, f);
	Output(bn, n);

	sort(bn, n);
	printf("danh sach sau khi xep theo nam mac:\n");
	OutTer(bn, n);

	printf("thoi gian trung binh mac cua benh C: %f", tgTb(bn, n));

	
	free(bn);
	fclose(f);
}