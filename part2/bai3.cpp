#include<stdio.h>
struct in4
	{
		char name[20];
		char hometown[20];
		char school[20];
		int sbd;
		float toan,ly,hoa;
	};
void show(int i, in4 hsg[])
{
	printf("\nten: %s",hsg[i].name);
	printf("\ntque: %s",hsg[i].hometown);
	printf("\nten truong: %s",hsg[i].school);
	printf("\nsbd: %d",hsg[i].sbd);
	printf("\ndiem toan: %f",hsg[i].toan);
	printf("\n diem ly: %f",hsg[i].ly);
	printf("\ndiem hoa: %f",hsg[i].hoa);
}
int main()
{
	
	int so_phieu_diem=20;
	in4 hsg[so_phieu_diem];
	float tong_diem[so_phieu_diem];
	printf("nhap thong tin thi sinh.\n");
	for (int i = 0; i < so_phieu_diem; i++)
	{
		printf("nhap ten: ");
		fflush(stdin);
		gets(hsg[i].name);
		printf("nhap que quan: ");
		fflush(stdin);
		gets(hsg[i].hometown);
		printf("nhap ten truong: ");
		fflush(stdin);
		gets(hsg[i].school);
		printf("nhap so bao danh: ");
		scanf("%d",hsg[i].sbd);
		printf("nhap diem toan: ");
		scanf("%f",hsg[i].toan);
		printf("nhap diem ly: ");
		scanf("%f",hsg[i].ly);
		printf("nhap diem hoa: ");
		scanf("%f",hsg[i].hoa);
		tong_diem[i] = hsg[i].toan+hsg[i].ly+hsg[i].hoa;

	}
	
	printf("nhung sinh vien co tong diem lon hon 15");
	for (int i = 0; i < so_phieu_diem; i++)
	{
		float tong_diem=hsg[i].toan+hsg[i].ly+hsg[i].hoa;
		if (tong_diem>15)
		{
			printf("\n");
			show(i,hsg);
		}
	}
	for (int i = 0; i < so_phieu_diem-1; i++)
	{
		for (int j = i+1; j < so_phieu_diem; j++)
		{
			if (tong_diem[i]<tong_diem[j])
			{
				in4 temp = hsg[i];
				hsg[i]= hsg[j];
				hsg[j] = temp;
			}
		}
	}
	for (int i = 0; i < so_phieu_diem; i++)
	{
		printf("\n");
		show(i,hsg);
	}
	for (int i = 0; i < so_phieu_diem; i++)
	{
		
	}
	
	return 0;
}
