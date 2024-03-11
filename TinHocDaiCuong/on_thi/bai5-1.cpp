/*Câu 1: Nhập, xuất vào một dãy có n điểm, thực hiện các yêu cầu sau:
- Đếm số đoạn thẳng thuộc góc phần tư thứ 3.
- Nhập bán kính R, đếm và in ra màn hình các điểm nằm ngoài đường tròn tâm O, bán 
kính R.
- Tìm diện tích hình chữ nhật nhỏ nhất, có các cạnh song song với hệ trục tọa độ nhỏ
nhất, chứa tất cả các điểm.*/
#include<stdio.h>
#include<math.h>
struct toa_do
{
    float x,y;
};
void in(toa_do diem[],int i)
{
	printf("(%f,%f) ",diem[i].x,diem[i].y);
}
int main()
{
    int n, dem=0;
	float max=0;
	printf("nhap n: ");
	scanf("%d",&n);
	toa_do diem[n];
	printf("nhap toa do: \n");
    for(int i=0;i<n;i++)
	{
		scanf("%f",&diem[i].x);
		scanf("%f",&diem[i].y);
    }
    printf("cac diem ma ban da nhap: ");
	for(int i=0;i<n;i++)
	{
		in(diem,i);
        if(diem[i].x<0 && diem[i].y<0) dem++;
	}
    //1,
    printf("\nco %d diem thuoc goc phan tu thu 3.\n",dem);
    //2,Nhập bán kính R, đếm và in ra màn hình các điểm nằm ngoài đường tròn tâm O, bán 
    //kính R.
	float r;
	dem=0;
	printf("nhap ban kinh r: ");
	scanf("%f",&r);
	printf("nhung diem nam ngoai duong tron la: ");
    for (int i = 0; i < n; i++)
	{
		if(sqrt(pow(diem[i].x,2)+pow(diem[i].y,2))>r)
		{
			in(diem,i);
			dem++;
		}
	}
	printf("\nco tong cong %d diem nam ngoai duong tron.\n",dem);
	/*Tìm diện tích hình chữ nhật nhỏ nhất, có các cạnh song song với hệ trục tọa độ nhỏ
nhất, chứa tất cả các điểm*/
	float x_min=diem[0].x,x_max=diem[0].x,y_min=diem[0].y,y_max=diem[0].y;
	for (int i = 0; i < n; i++)
	{
		x_min=(x_min>diem[i].x)? diem[i].x:x_min;
		y_min=(y_min>diem[i].y)? diem[i].y:y_min;
		x_max=(x_max<diem[i].x)? diem[i].x:x_max;
		y_max=(y_max<diem[i].y)? diem[i].y:y_max;
	}
	float result=(x_max-x_min)*(y_max-y_min);
	printf("dien tich cua hinh chu nhat chua tat ca cac diem = %f",result);
    return 0;
}
