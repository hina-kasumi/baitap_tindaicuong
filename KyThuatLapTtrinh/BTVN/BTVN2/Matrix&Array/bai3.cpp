/*Bài 3. Nhập vào một dãy số nguyên có n phần tử, 
kiểm tra xem dãy có đang tăng dần hay ko.
Tìm giá trị chẵn lớn nhất của dãy số
Tìm giá trị nhỏ nhất của |a1|, |a2|,…, |an|
Tìm max của a[1], a[2]/2, a[3]/3, …, a[n]/n
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")
const int LIMIT = 100;

// hàm nhận đặc biệt có thể nhập cả biến và mảng (mảng không cần khai báo trước kích cỡ)
int Input(int *arr)
{

    // khai báo n để đếm xem mảng có kích cỡ là bao nhiêu
    int n = 0;

    // vòng lặp để nhập
    while (true)
    {
        scanf("%d", arr + n);
        n++;

        // tận dụng một lỗi '/n' ở trong stdin để dừng vòng lặp
        char stop;
        scanf("%c", &stop);
        if (stop == '\n')
            break;
    }

    // trả về kích cơ của mảng
    return n;
}

// hàm in ra giá trị của một biến số thực
void Output(int x)
{
    printf("%d ", x);
}

// hàm in ra các phần tử trong mảng
void OutArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        Output(*(arr + i));
    }
}

// hàm dùng để tìm giá trị chẵn trong dãy
int FindChan(int *arr, int n)
{
    // nếu tìm thấy thì trả về vị trí của số chắn đó nếu không thấy trả về -1
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) % 2 == 0)
            return i;
    }
    return -1;
}

// tìm số chẵn lớn nhất
int MaxChan(int *arr, int n)
{
    int max;
    int dir_max = FindChan(arr, n);

    // nếu không tìm thấy trả về số lẻ -1 để thể hiện là không có số chẵn trong dãy
    if (dir_max == -1)
        return -1;

    // tìm số chẵn lớn nhất
    for (int i = dir_max; i < n; i++)
    {
        if (*(arr + i) % 2 == 0 && *(arr + i) > max)
        {
            max = *(arr + i);
        }
    }

    // trả về giá trị max
    return max;
}

//tìm giá trị tuyệt đối bé nhất
int AbsMin(int *arr, int n){
    int min = abs(*(arr));
    for (int i = 0; i < n; i++){
        int tmp = abs(*(arr + i));
        min = (min > tmp)? tmp:min;
    }
    return min;
}

//Tìm max của a[1], a[2]/2, a[3]/3, …, a[n]/n
float Max (int *arr, int n){
    float max = (float)*arr;
    for (int i = 1; i < n; i++)
    {
        float tmp = 1.0*(*(arr + i))/(i + 1);
        max = (max < tmp)? tmp:max;
    }
    return max;
}

int main()
{
    // khai báo mảng động
    int *arr;
    arr = (int *)malloc(LIMIT * sizeof(int));

    // nhập mảng dùng hàm đặc biệt có thể nhận biến và mảng (không cần khai báo kích cỡ)
    // giá trị trả về của hàm là kích cỡ của mảng
    printf("nhap gia tri cho cac phan tu co trong mang:\n");
    int n = Input(arr);

    // in ra mang vua nhap
    printf("mang ban vua nhap la: ");
    OutArray(arr, n);
    endll;

    // tìm giá trị chẵn lớn nhất trong dãy số
    int max = MaxChan(arr, n);
    if (max == -1)
        printf("khong co gia tri chan trong day.\n\n");
    else
        printf("gia tri chan lon nhat trong day = %d\n\n", max);

    //Tìm giá trị nhỏ nhất của |a1|, |a2|,…, |an|
    printf("gia tri tuyet doi be nhat trong day la: %d\n\n", AbsMin(arr, n));

    //Tìm max của a[1], a[2]/2, a[3]/3, …, a[n]/n
    printf("gia tri lon nhat theo a[n]/n = %.2f", Max(arr, n));
    
    //giải phóng bộ nhớ
    free(arr);
    return 0;
}
