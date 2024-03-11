/*Bài 2. Nhập vào đa thức P(x) bậc n, tính S = 2020 + P(x) – P’(x) với x là số thực nhập từ bàn phím
Nhập đa thức Q(x), in ra màn hình hệ số của đa thức tổng trong trường hợp cùng bậc và khác bậc.*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")
int const LIMIT = 100;

//hàm nhận đặc biệt có thể nhập cả biến và mảng (mảng không cần khai báo trước kích cỡ)
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

//tính S = 2020 + P(x) – P’(x)
float S (float *arr, int n, float x)
{
    //khai báo và tính sẵn 2020 + hệ số tự do của P(x)
    float result = 2020 + *(arr);

    //quá trình tính
    for (int i = 1; i < n; i++)
    {
        //P(x)
        result += (*(arr + i)) * pow(x, i);

        //P'(x)
        result += i*(*(arr + i)) * pow(x, i - 1);
    }

    //trả về giá trị cần tính
    return result;
}

//tính tổng Q(x) và P(x)
float *Plus (float *P, float *Q, int n, int m){
    //tìm số lớn hơn để làm giói hạn để tính
    int higher = (n > m)? n:m;
    int lower = (n < m)? n:m;

    //khai báo result là mảng động
    float *result;
    result = (float*) malloc(LIMIT * sizeof(float));

    //quá trình cộng P(x) và Q(x)
    for (int i = 0; i < lower; i++)
    {
        *(result + i) = *(P + i) + *(Q + i);
    }

    for (int i = lower; i < higher; i++)
    {
        if(n > m) *(result + i) = *(P + i);
        else if (n < m) *(result + i) = *(Q + i);
    }
    
    free(result);
    return result;
}

int main()
{
    //khai báo cấp phát động cho mảng hệ số
    float *heso;
    heso = (float*) malloc(LIMIT * sizeof(float));


    //Hàm Input là hàm nhập đặc biết có thể nhập cho biến và mảng (không cần khai báo kích cỡ trước)
    //sau khi nhập xong hàm sẽ trả về kích cỡ của mảng
    printf("nhap he so cho phuong trinh P(x) tu x^0:\n");
    int n = Input(heso);

    //in ra ra các hệ số vừa nhập
    printf("phuong trinh ban vua nhap la: ");
    OutArray(heso, n);
    endll;


    //tính kết quả S = 2020 + P(x) – P’(x) với x là số thực nhập từ bàn phím
    //nhập gia trị cho x
    float x;
    printf("nhap x: ");
    Input(&x);

    //tính giá trị của S bằng Hàm tính
    float result = S(heso, n, x);
    printf("S = 2020 + P(x) - P'(x) = ");
    Output(result);
    endll;

    //Nhập đa thức Q(x), in ra màn hình hệ số của đa thức tổng trong trường hợp cùng bậc và khác bậc.

    //nhập hệ số cho phương trình Q(x)
    printf("nhap he so cho phuong trinh Q(x):\n");
    float *heso_Q;
    heso_Q = (float*) malloc(LIMIT * sizeof(float));
    int m = Input(heso_Q);

    //in ra phươ trình Q(x)
    printf("phuong trinh Q(x) ban vua nhap la: ");
    OutArray(heso_Q, m);
    endll;

    //int ra phuong trinh tong
    printf("phuong trinh tong cua Q(x) va P(x) la: ");
    float *a = Plus(heso, heso_Q , n, m);
    int higher = (n > m)? n:m;
    OutArray(a, higher);
    
    
    //giải phóng bộ nhớ mảng heso mà mình đã xin
    free(heso);
    free(heso_Q);
    return 0;
}
