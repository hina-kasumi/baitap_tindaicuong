#include<stdio.h>
#include<math.h>
void nhap(int *n)
{
    printf("nhap n: ");
    scanf("%d",n);
}
void xuat(int arr[],int i)
{
    printf("%d ",arr[i]);
}
main()
{
    int n;
    nhap(&n);
    printf("nhap day nguyen duong co %d phan tu: ",n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("day ban vua vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        xuat(arr,i);
    }
    //1,
    int x;
    printf("\nnhap gia tri ban muon kiem tra co trong trong day hay ko: ");
    scanf("%d",&x);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==x) {
            printf("co\n");
            goto skip;}
    }
    printf("khong\n");
    //2,
    skip: int gioi_han=3;
    int max1=arr[0],min=arr[0],max[gioi_han];
    for (int i = 0; i < n; i++)
    {
        max1=(max1<arr[i])? arr[i]:max1;
        min=(min>arr[i])? arr[i]:min;
    }
    for (int i = 1; i < gioi_han; i++)
    {
        max[i]=min;
    }
    max[0]=max1;
    printf("gia tri lon thu 1 la: %d\n",max1);
    for (int i = 1; i < gioi_han; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max[i]<arr[j])max[i]=arr[j];
            if(max[i]>=max[i-1]) max[i]=min;
        }
        printf("gia tri lon thu %d la: %d\n",i+1,max[i]);
    }
    
}
