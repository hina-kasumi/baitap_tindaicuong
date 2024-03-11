/*Câu 1: Nhập, xuất vào một dãy số nguyên dương có n phần tử, thực hiện các yêu cầu sau:
- Đếm số phần tử chẵn có trong dãy số.
- Nhập vào số nguyên x, tính trung bình cộng các số có giá trị tuyệt đối lớn hơn x.
- Kiểm tra xem dãy có phải là dãy tăng dần hay không.*/
#include<stdio.h>
#include<math.h>
#define nn printf("\n");

void in(int arr[],int i)
{
    printf("%d ",arr[i]);
}

bool  tang_dan(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
         if(arr[i]>=arr[i+1]) return 0;
    }
    return 1;
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if (n<1) goto back;
    int arr[n],chan=0;
    back1: printf("nhap gia tri nguyen duong cho cac phan tu trong day: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        if (arr[i]<=0)
        {
            chan=0;
            goto back1;
        }
        
        if(arr[i]%2==0) chan++;
    }
    printf("day ban vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        in(arr,i);
    }
    nn;
    //1,
    printf("co %d gia tri la phan tu chan.\n",chan);
    nn;
    //2,
    int x;
    printf("nhap x: ");
    scanf("%d",&x);
    int dem=0,average=0;
    for (int i = 0; i < n; i++)
    {
        if(abs(arr[i])>x)
        {
            dem++;
            average+=arr[i];
        }
    }
    printf("trung binh cong cac gia tri tuyet doi lon hon x: %.0f\n\n",1.0*average/dem);
    //3,
    if (tang_dan(arr,n)) printf("day la day tang dan.");
    else printf("day khong phai day tang dan.");
    return 0;
}
