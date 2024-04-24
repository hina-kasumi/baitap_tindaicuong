/*Bài 3: Xây dựng cấu trúc Điểm (Point), với các thành phần là hoành độ x và tung độ y 
Xây dựng cấu trúc Đoạn thẳng (Line) gồm các thành phần 
 Điểm bắt đầu (start point) của đoạn thẳng (là một Point). 
 Điểm kết thúc (end point) của đoạn thẳng (là một Point). 
Và các hàm:  - 
Hàm tạo một đoạn thẳng bằng cách chỉ định điểm bắt đầu và điểm kết thúc. 
 Hàm tính độ dài của đoạn thẳng. 
 Hàm kiểm tra xem một điểm có thuộc đoạn thẳng hay không. 
 Hàm hiển thị thông tin về đoạn thẳng, bao gồm điểm bắt đầu và điểm kết thúc. 
Viết hàm main() nhập vào danh sách điểm và đoạn thằng, tính tổng độ dài của các đoạn thẳng, 
đếm số điểm thuộc từng đoạn thẳng. */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")
struct Point
{
    float x,y;
    void toString(){
        printf("(%.2f, %.2f) ", x, y);
    }
};

struct Line
{
    Point startPoint;
    Point endPoint;

    float DoDai(){
        return sqrt(pow(endPoint.x - startPoint.x, 2) + pow(endPoint.y - startPoint.y, 2));
    }
    void ThongTinLine(){
        printf("start: "); startPoint.toString();
        printf("end: "); endPoint.toString();
        endl;
    }
};

void Input (Point *point){
    scanf("%f%f", &point->x, &point->y);
}
void Input(Line *line){
    printf("start point: ");
    Input(&line->startPoint);

    printf("end point: ");
    Input(&line->endPoint);

    endl;
}

void Input(Line *line, int n){
    for (int i = 0; i < n; i++)
    {
        printf("doan thang thu %d:\n", i + 1);
        Input(line + i);
    }
}

void Output(Line *line, int n){
    for (int i = 0; i < n; i++)
    {
        printf("doan thang thu %d:\n", i + 1);
        (line + i)->ThongTinLine();
        endl;
    }
    
}

bool KiemTraThuocDuongThang(Line line, Point tmp){
    float a = line.startPoint.y - line.endPoint.y;
    float b = line.endPoint.x - line.startPoint.x;
    Line tmp1 = {line.startPoint, tmp};
    Line tmp2 = {line.endPoint, tmp};
    return a * (tmp.x - line.startPoint.x) + b * (tmp.y - line.startPoint.y) == 0 
    && tmp1.DoDai() + tmp2.DoDai() == line.DoDai();
}

float TongDoDai(Line *line, int n){
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += line[i].DoDai();
    }
    return sum;
}

int *SoDiemThuocDgThang(Line *line, int n){
    int *count = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        count[i] = -2;
        for (int j = 0; j < n; j++)
        {
            if (KiemTraThuocDuongThang(line[i], line[j].startPoint))
                count[i] ++;
            
            if (KiemTraThuocDuongThang(line[i], line[j].endPoint))
                count[i] ++;
        }
    }
    return count;
}


int main()
{
    int n;
    printf("nhap so duong thang trong danh sach: ");
    scanf("%d", &n);

    Line *line = (Line*) malloc(n * sizeof(Line));
    printf("nhap so lieu cho cho cac doan thang:\n");
    Input(line, n);

    printf("cac doan thang ma ban da nhap la:\n");
    Output(line, n);
    endl;

    printf("tong do dai cua cac duong thang la: %f\n\n", TongDoDai(line, n));

    int *count = SoDiemThuocDgThang(line, n);
    printf("so diem thuoc tung duong thang:\n");
    for (int i = 0; i < n; i++)
    {
        printf("doan thang thu %d: %d\n", i + 1, *(count + i));
    }
    

    free(count);
    free(line);
    return 0;
}
