/*Câu 5. Xây dựng cấu trúc Diem (Điểm), trong đó có các thuộc tính gồm hoành độ và tung độ; 
Viết hàm main() để:
	Nhập tọa độ n điểm trên mặt phẳng.
	Sắp xếp dãy điểm xa dần gốc tọa độ.
	Tính tổng khoảng cách từ tất cả các điểm trên đến gốc tọa độ.
	Tìm một điểm ở gần gốc tọa độ nhất.
	Tìm diện tích hình tròn tâm O nhỏ nhất chưa tất cả các điểm.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n")
const float PI = 3.14;

struct Location
{
	float x, y;
};

//nhạp một biến có kiểu dữ liệu là số nguyên
void Input(int *x){
	scanf("%d", x);
}

//nhập một biến có kiểu dữ liệu số thực
void Input(float *x){
	scanf("%f", x);
}

//nhập giá trị cho các tọa độ đó
void Input(Location *Point, int n){
	for (int i = 0; i < n; i++)
	{
		Input(&((Point + i)->x));
		Input(&((Point + i)->y));
	}
}

//in ra một điểm
void Output(float x, float y){
	printf("(%.2f, %.2f) ", x, y);
}

//in ra các điểm 
void Output(Location *Point, int n){
	for (int i = 0; i < n; i++)
	{
		Output((Point + i)->x, (Point + i)->y);
		endl;
	}
	endl;
}

//tạo một hàm trả về một mảng chứa dộ dài của các điểm
float *KhoangCach(Location *point, int n){
	//tạo một mảng
	float *khoangCach = (float*) malloc(n * sizeof(float));

	for (int i = 0; i < n; i++)
	{
		*(khoangCach + i) = sqrt((point + i)->x*(point + i)->x + (point + i)->y*(point + i)->y);
	}
	return khoangCach;
}

void Swap(float *x, float *y){
	float tmp = *x;
	*x = *y;
	*y = tmp;
}

//hàm xắp xếp từ bé đến lớn
void Sort(float *khoangCach, int n, Location *point){
	for (int i = 0; i < n -1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(khoangCach + i) > *(khoangCach + j))
			{
				Swap((khoangCach + i), (khoangCach + j));
				Swap (&((point + i)->x),&((point + j)->x));
				Swap (&((point + i)->y),&((point + j)->y));
			}
		}
	}
}

// hàm tính tổng
float Sum(float *khoangCach, int n){
	float sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += *(khoangCach + i);
	}
	return sum;
}

int main()
{
	//nhập n
	int n;
	back: printf("nhap so diem co tren truc toa do: ");
	Input(&n);
	if (n < 1)
	{
		printf("vui long nhap lai.\n");
		goto back;
	}
	
	//khai báo mảng đồ thị
	Location *Point = (Location*) malloc (n * sizeof(Location));
	printf("nhap toa do cho %d diem:\n", n);
	Input(Point, n);
	
	//in ra các điểm các điểm đã nhập
	printf("cac diem ma ban da nhap:\n");
	Output(Point, n);

	//Sắp xếp dãy điểm xa dần gốc tọa độ.
	//tạo một mảng chứa khoảng cách của điểm
	float *khoangCach = KhoangCach(Point, n);
	Sort(khoangCach, n, Point);
	printf("do thi sau khi xap xep xa danh goc toa do:\n");
	Output(Point, n);

	

	//Tính tổng khoảng cách từ tất cả các điểm trên đến gốc tọa độ.
	printf("tong khoang cach tu tat ca diem tren den goc toa do = %f\n\n", Sum(khoangCach, n));
	

	//Tìm một điểm ở gần gốc tọa độ nhất.
	printf("diem gan goc toa do nhat: (%.2f, %.2f)\n\n", Point->x, Point->y);

	//Tìm diện tích hình tròn tâm O nhỏ nhất chưa tất cả các điểm.
	printf("dien tich chon be nhat chua tat cac diem vua nha la: %f", *(khoangCach + n -1) * *(khoangCach + n -1) * PI);

	//giải phóng bộ nhớ
	free(Point);
	free(khoangCach);
	return 0;
}
