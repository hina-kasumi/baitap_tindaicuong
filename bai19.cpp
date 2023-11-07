#include<stdio.h>
int main()
{
    int n,dirmax, dirmin;
    printf("nhap so n: ");
    scanf("%d",&n);
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&arr[i]);
    }
    float max=arr[0], min=arr[0];
    for (int i = 0; i < n; i++)
    {
        
        if(arr[i]<=min) 
        {
            min=arr[i];
            //dirmin=i+1;
        }
        if(arr[i]>=max)
        {
            max=arr[i]; 
            //dirmax=i+1;
        }
    }
    //hien thi so lon nhat va be nhat cua day
    printf("so lon nhat trong day la: %.3f\n",max);
    printf("so nho nhat trong day la: %.3f\n",min);
    //hien thi vi tri cua so lon nhat va be nhat trong day
    for (int i=0;i<n;i++)
    {
        if (min==arr[i])
        {
            dirmin=i+1;
            printf("vi tri so nho nhat trong day la: %d\n",dirmin);
        } 
    }
    for (int i=0;i<n;i++)
    {
        if(max==arr[i])
        {
            dirmax=i+1;
            printf("vi tri so lon nhat trong day la: %d\n",dirmax);
        }
    }
    
    return 0;
}
