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
    int clone[gioi_han];
    for (int i = 0; i < n; i++)
    {
        clone[i]=arr[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (clone[i]<clone[j])
            {
                int tmp = clone[i];
                clone[i] = clone[j];
                clone[j] = tmp;
            }
        }
    }
    int max[gioi_han]= {clone[0]};
    printf("gia tri lon nhat thu 1 la %d\n",max[0]);
    for (int i = 1; i < gioi_han; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (clone[j]<max[i-1])
            {
                max[i]=clone[j];
                break;
            }
        }
        printf("gia tri lon nhat thu %d la %d\n", i+1,max[i]);
    }
    
    
}
