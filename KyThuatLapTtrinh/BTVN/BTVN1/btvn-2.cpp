#include<stdio.h>
#include<string.h>

#define sc scanf
#define pr printf
#define endl printf("\n")

void Out(int arr)
{
    pr("%d ",arr);
}

//1, tong
int Sum(int arr[], int n)
{
    if(n == 0) return arr[0];
    return arr[n]+Sum(arr, n-1);
}

//2, lon hon x
bool Higher(int arr[], int n, int x)
{
    pr("nhung phan tu co gia tri lon hon x: ");
    int check = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            Out(arr[i]);
            check = false;
        }
    }
    return check;
}

//3, tim max
int Max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = (max<arr[i])? arr[i]:max;
    }
    return max;
}

//4, kiem tra day tang dam
bool Rise(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if(arr[i] <= arr[i-1]) return false;
    }
    return true;
}

int main()
{
    //nhap n
    int n;
    back: pr("nhap so phan tu co trong day: ");
    sc("%d",&n);
    if (n<1)
    {
        pr("vui long nhap lai.\n");
        goto back;
    }
    

    //nhap mang
    int arr[n];
    pr("nhap gia tri cho cac phan t trong day: ");
    for (int i = 0; i < n; i++)
    {
        sc("%d", &arr[i]);
    }
    
    //in mang
    for (int i = 0; i < n; i++)
    {
        Out(arr[i]);
    }
    endl; endl;
    
    //1, tong day so
    pr("tong cac phan tu trong day = %d\n\n", Sum(arr, n-1));


    //2,
    int x;
    pr("nhap x: ");
    sc("%d", &x);
    if(Higher(arr, n , x)) pr("khong co gia tri nao lon hon x");
    endl;
    endl;


    //3,tim max
    pr("gia tri lon nhat trong day: %d\n\n", Max(arr, n));

    //4,kiem tra day tang dan
    if(Rise(arr, n)) pr("day la day tang dan");
    else pr("day ko phai day tang dan");
    return 0;
}
