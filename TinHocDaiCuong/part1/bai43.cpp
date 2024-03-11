/*43, Nhập một dãy số thực a1, a2 ... an và in dãy số ra màn hình trên một dòng.
Gọi Max là giá trị lớn nhất của dãy số, Min là giá trị nhỏ nhất của dãy số. Đếm xem trong dãy 
có bao nhiêu phần tử thỏa mãn điều kiện X - Min > Max – X với X là giá trị của mỗi phần tử
trong dãy*/
#include<stdio.h>
int main()
{
    int n,i;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float arr[n];
    printf("nhap gia tri day n: ");
    for (i = 0; i < n; i++) scanf("%f",&arr[i]);
    float max=arr[0],min=arr[0];
    //tim gia tri lon nhat va gia tri nho nhat
    for ( i = 0; i < n; i++)
    {
        if (max<arr[i]) max=arr[i];
        if (min>arr[i]) min=arr[i];
    }
    //timf thoa man dk
    int check=0;
    for ( i = 0; i < n; i++) if(arr[i]-min>max-arr[i]) check++;
    //in gia tri thoa man va so gia tri thoa man
    if (check==0) printf("khong co phan tu nao thoa man dieu kien.");
    else
    {
        printf("nhung gia tri thoa man la: \n");
        for ( i = 0; i < n; i++)
        {
            if(arr[i]-min>max-arr[i]) printf("%f ",arr[i]);
        }
        printf("\nco %d gia tri thoa man.",check);
    }
}