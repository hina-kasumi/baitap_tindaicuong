#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define fendl fprintf(f, "\n")
struct NhanVien{
	int mnv;
	char ht[20];
	float luong;
	char phong;
};

void Input(NhanVien *nv, int n, FILE *f){
	if (n == 0)
		return;
	n--;
	Input(nv, n, f);
	fscanf(f, "%d ", &nv[n].mnv);
	
	fgets(nv[n].ht, 20, f);
	nv[n].ht[strlen(nv[n].ht) - 1] = '\0';
	
	fscanf(f, "%f %c ", &nv[n].luong, &nv[n].phong);
}

void Output(NhanVien nv, FILE *f){
	fprintf(f, "%10d|%10s|%10.3f|%c\n", nv.mnv, nv.ht, nv.luong, nv.phong);
}

void Output(NhanVien *nv, int n, FILE *f){
	if (n == 0)
		return;
	Output(nv, n - 1, f);
	Output(nv[n - 1], f);
}

float Tbc(NhanVien *nv, int n, char ban){
	float res = 0;
	int cnt = 0;
	for(int i = 0; i< n; i++){
		if(nv[i].phong == ban){
			res += nv[i].luong;
			cnt++;
		}
	}
	if (cnt)
		return res / cnt;
	else
		return 0;
}

char Min(NhanVien *nv, int n){
	float min = Tbc(nv, n, 'A');
	float banB = Tbc(nv, n, 'B');
	float banC = Tbc(nv, n, 'C');
	min = (min > banB)? banB:min;
	min = (min > banC)? banC:min;
	if (min == banB)
		return 'B';
	else if (min == banC)
		return 'C';
	else 
		return 'A';
}

void swap(NhanVien *a, NhanVien *b){
	NhanVien x = *a;
	*a = *b;
	*b = x;
}
int patition(NhanVien *nv, int low, int high){
	float pivot = nv[high].luong;
	int i = low - 1;
	for(int j = low; j<= high; j++){
		if(nv[j].luong > pivot){
			i++;
			swap(nv + i, nv + j);
		}
	}
	swap(nv + i + 1, nv + high);
	return i + 1;
}

void QuickSort(NhanVien *nv, int low, int high){
	if (low < high){
		int pi = patition(nv, low, high);
		QuickSort(nv, low, pi - 1);
		QuickSort(nv, pi + 1, high);
	}
}

int main(){
	FILE *f = fopen("in.txt", "r");
	int n;
	fscanf(f, "%d ", &n);
	NhanVien *nv = (NhanVien*) malloc(n * sizeof(NhanVien));
	Input(nv, n, f);
	fclose(f);
	f = fopen("out.txt", "w");
	fprintf(f, "danh sach nhanh vien:\n");
	Output(nv, n, f);
	
	fprintf(f, "phong co luong thap nhat la: %c\n", Min(nv, n));
	
	QuickSort(nv, 0, n - 1);
	fprintf(f, "sau khi xep theo luong:\n");
	Output(nv, n, f);
	
	fclose(f);
	free(nv);
}