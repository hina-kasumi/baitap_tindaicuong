/*40, Nhập một dãy số thực a1, a2 ... an.
Nhập chỉ số k sao cho 1 ≤ k ≤ n. Tính giá trị trung bình của dãy rồi so sánh giá trị vừa tính 
được với phần tử thứ k.*/
#include<stdio.h>
int main()
{
    int n,i,k;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    float arr[n],average;
    printf("nhap gia tri day n: ");
    for (i = 0; i < n; i++) scanf("%f",&arr[i]);
    re: printf("nhap gia tri k: ");
    scanf("%d",&k);
    if(1>k || k>n) goto re;
    for ( i = 0; i < n; i++)
    {
        average+=arr[i]/n;
    }
    if (average==arr[k-1]) printf("gia tri trung binh cua day %f = phan tu thu k %f",average,arr[k-1]);
    else if(average<arr[k-1]) printf("gia tri trung binh cua day %f < phan tu thu k %f",average,arr[k-1]);
    else printf("gia tri trung binh cua day %f > phan tu thu k %f",average,arr[k-1]);
    return 0;
}
