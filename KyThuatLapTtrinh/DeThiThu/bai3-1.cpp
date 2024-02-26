/*Câu 1: Nhập, xuất vào một dãy số nguyên dương có n phần tử, thực hiện các yêu 
cầu sau:
- Đếm số phần tử chẵn có trong dãy số.
- Nhập vào số nguyên x, tính trung bình cộng các số có giá trị tuyệt đối lớn 
hơn x.
- Kiểm tra xem dãy có phải là dãy tăng dần hay không*/
#include <stdio.h>
#include <math.h>
#define pr printf
#define endl printf("\n")

bool Kiemtra(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main() {
    int n;
    back: pr("nhap so phan tu co trong day: ");
    scanf("%d", &n);
    if(n < 1)
    {
        pr("vui long nhap lai.\n");
        goto back;
    }
    int arr[n];
    pr("nhap gia tri cho cac phan tu torng day: ");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    pr("day ban vua nhap la: ");
    for(int i = 0; i < n; i++) pr("%d ", arr[i]);
    endl;
    //1,
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0) count++;
    }
    if(count>0) pr("day co %d so chan\n\n", count);
    else pr("khong co phan tu chan torng day so.\n\n");
    
    //2,
    int x;
    count = 0;
    int result = 0;
    pr("nhap x: ");
    scanf("%d", &x);
    for(int i =0;i<n;i++)
    {
        if(abs(arr[i]) > x)
        {
            count++;
            result+=arr[i];
        }
    }
    if(count > 0) pr("trung binh cong cac so co gia tri tuyet doi lon hon %d la: %f\n\n", x, 1.0*result/count);
    else pr("ko co so nao co gia tri truyet doi lon hon x.\n\n");
    //3,
    if(Kiemtra(arr, n)) pr("day la day so tang");
    else pr("day khong phai la day so tang");
    return 0;
}