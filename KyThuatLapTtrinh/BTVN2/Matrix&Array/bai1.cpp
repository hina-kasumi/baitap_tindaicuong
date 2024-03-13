/*Nhập vào một ma trận vuông kiểu nguyên cấp nxn
-	In ra màn hình dưới dạng bảng
-	Tìm min của ma trận
-	Tìm min các phần tử âm của ma trận
-	Tính tổng từng cột, cho biết các cột có tổng lớn nhất
-	Tìm max từng hàng
-	Đếm các phần tử dương lớn hơn 10 có trong ma trận
-	Kiểm tra xem ma trận có phải ma trận tam giác dưới hay không. Tính tích các phần tử âm thuộc đường chéo phụ
-	Tính trung bình cộng các phần tử lớn hơn 10 có trong ma trận
-	Đếm xem trong ma trận có bao nhiêu phần tử nằm trong đoạn [5, 30]
-	Tính tổng từng hàng, cho biết các hàng có tổng lớn nhất
-	Tính trung bình cộng các phần tử dương thuộc cột lẻ trong dãy
-	Nhập số hàng và cột bằng nhau, kiểm tra ma trận có phải tam giác trên hay không
-	Tính trung bình cộng các phần tử trên đường chéo phụ.
-	Kiểm tra xem ma trận có phải ma trận đối xứng hay không.
-	Tìm max các phần tử nằm phía dưới đường chéo chính
-	Kiểm tra xem ma trận có các tổng hàng nào có giá trị bằng nhau hay không
-	Tìm max của từng cột.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

//nhap mot phan tu
void Input(int *x){
    scanf("%d", x);
}

//nhap mot ma tran
void In_Matrix(int n, int matrix[][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",matrix[i][j]);
        }
        
    }
    
}

//in ra mot so nguyen
void Output(int *matrix);

int main()
{
    int n;
    Input(&n);
    int maxtrix[n][n];
    In_Matrix(n, maxtrix);
    return 0;
}
