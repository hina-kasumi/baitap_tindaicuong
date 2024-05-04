/*Bài 5. Cho một tệp văn bản (tên tệp nhập từ bàn phím) chứa toạ độ của một dãy điểm trên mặt phằng, có 
dạng: dòng đầu chứa số điểm, trên mỗi dòng tiếp theo chứa hoành độ và tung độ của một điểm. Hãy viết 
hàm thực hiện các yêu cầu sau:  
1. Đọc dữ liệu của dãy điểm từ tệp trên.  
2. Xác định một điểm ở xa gốc tọa độ nhất. 
3. Nếu cứ mỗi hai điểm nối với nhau tạo thành một đoạn thẳng, xác định số đoạn thẳng tạo 
bởi tập điểm n trên và nằm bên trong góc phần tư thứ ba.  
4. Tìm đoạn thẳng dài nhất 
5. Đếm số điểm thuộc đường phân giác góc phần tư thứ nhất*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

void Input(float **x, float **y, int n, FILE *fin){
    *x = (float*) malloc(n * sizeof(float));
    *y = (float*) malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
        fscanf(fin, "%f%f", *x + i, *y + i);
}

void Output(float x, float y){
    printf("(%.2f, %.2f)\n",x , y);
}

void Output(float *x, float *y, int n){
    if(n == 0)
        return;
    Output(x, y, n - 1);
    Output(x[n - 1], y[n - 1]);
}

float Max(float *x, float *y, int n){
    float max = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        float tmp = (x[i] * x[i]) + (y[i] * y[i]);
        if(max < tmp){
            max = tmp;
            res = i;
        }
    }
    return res;
}

int main()
{
    FILE *fin;
    do
    {
        char fileName[20] = "input.txt";
        fin = fopen(fileName, "r");
    } while (fin == NULL);
    
    int n;
    fscanf(fin, "%d", &n);
    float *x, *y;
    Input(&x, &y, n, fin);
    printf("cac diem:\n");
    Output(x, y, n);
    fclose(fin);

    printf("\ndiem nam xa tam nhat la: ");
    int lo = Max(x, y, n);
    Output(x[lo], y[lo]);


    free(x);
    free(y);
    return 0;
}
