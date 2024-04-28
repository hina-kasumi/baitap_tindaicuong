/*Áp dụng kiểu dữ liệu mảng để viết chương trình kiểm tra ngày tháng năm 
có hợp lệ không (ngày, tháng và năm được nhập từ bàn phím). */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

bool kiemTra(int *date){
	if (*date < 1 || *date > 31)
		return false;
	else if (date[1] < 1 || date[1] > 12)
		return false;
	else if (date[2] < 0)
		return false;
		
	return true;
}

bool Input(int **date){
	*date = (int*) malloc(3 * sizeof(int));
	scanf("%d/%d/%d",*date, *date + 1, *date + 2);
	return kiemTra(*date);
}

void Output(int *date){
	printf("%0d/%0d/%d",date[0], date[1], date[2]);
}

int main(){
	int *date;
	printf("nhap ngay bat ky: ");
	while(!Input(&date))
		printf("ngay khong dung vui long nhap lai.\n");
	
	printf("ngay ban vua nhap la: ");
    Output(date);
    
    free(date);
    return 0;
}
