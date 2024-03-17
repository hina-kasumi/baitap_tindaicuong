#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Input(float *arr){

    //khai báo n để đếm xem mảng có kích cỡ là bao nhiêu
    int n = 0;

    //vòng lặp để nhập
    while (true){
        scanf("%f", arr + n);
        n++;

        //tận dụng một lỗi '/n' ở trong stdin để dừng vòng lặp
        char stop;
        scanf("%c", &stop);
        if (stop == '\n') break;
    }

    //trả về kích cơ của mảng
    return n;
}

//hàm in ra giá trị của một biến số thực
void Output (float x){
    printf("%.2f ", x);
}

//hàm in ra các phần tử trong mảng
void OutArray(float *arr, int n){
    printf("%.2f", *(arr));
    for (int i = 1; i < n; i++)
    {
        printf(" + %.2fx^%d", *(arr + i), i);
    }
}

float Tong(float *arr, int n){
    for (int i = 0; i < n; i++)
    {
        
    }
    
}

int main()
{
    printf("nhap he so cho Q(x):");
    float *Px = (float*) malloc(100 * sizeof(float));
    int n = Input(Px);
    printf("da thuc P(x): ");
    OutArray(Px, n);

    printf("\nnhap he so cho Q(x):");
    float *Qx = (float*) malloc(100 * sizeof(float));
    int m = Input(Qx);
    printf("da thuc Q(x): ");
    OutArray(Qx, n);

    int x;
    printf("\nnhap x:");
    scanf("%d", &x);


    return 0;
}
