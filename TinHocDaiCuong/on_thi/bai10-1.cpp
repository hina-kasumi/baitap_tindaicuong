/*Câu 1: Nhập, xuất vào một dãy số nguyên có n phần tử, thực hiện các yêu cầu sau:
- Tìm giá trị chẵn lớn nhất
- Đếm và in ra màn hình các cặp số liên tiếp mà tích chia tổng dư 3.
- Nhập vào 1 số x, tính tổng các số có giá trị lớn hơn x*/
#include<stdio.h>
#define nn printf("\n")

int tim_max_chan(int arr[],int n, int chan_max)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2==0)
        {
            chan_max=(chan_max<arr[i])? arr[i]:chan_max;
        }
    }
    return chan_max;
}

void in(int arr[],int i)
{
    printf("%d ",arr[i]);
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if (n<1) goto back;
    int arr[n],chan_max;
    printf("nhap gia tri nguyen cho cac phan tu trong day: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%2==0) chan_max=arr[i];
    }
    printf("day ban vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        in(arr,i);
    }
    nn;
    //1,
    printf("ngia tri chan lon nhat la: %d\n",tim_max_chan(arr,n,chan_max));
    //2,
    int dem=0;
    for (int i = 0; i < n-1; i++)
    {
        if((arr[i]*arr[i+1])%(arr[i]+arr[i+1])==3)
        {
            dem++;
        }
    }
    if (dem>0)
    {
        printf("co %d cap co tich chia tong du 3.\ndo la cap: ",dem);
        for (int i = 0; i < n-1; i++)
        {
            if((arr[i]*arr[i+1])%(arr[i]+arr[i+1])==3)
            {
                in(arr,i);in(arr,i+1);
                printf("|");
            }
        }
    }
    else printf("khong co cap nao thoa man de bai.\n");
    nn;
    //3,
    int x,tong=0;
    printf("nhap x: ");
    scanf("%d",&x);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>x)
        {
            tong+=arr[i];
        }
    }
    if(tong) printf("tong cac so co gia tri lon hon x = %d.",tong);
    else printf("khong co phan tu nao lon hon x nen tong = 0.");
    return 0;
}
