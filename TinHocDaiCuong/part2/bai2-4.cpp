//Cho ba số a, b, c đọc vào từ bàn phím. Hãy in ra màn hình theo thứ tự tăng dần các số.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a[3];
    for (int i = 0; i < 3; i++) scanf("%f",&a[i]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            if (a[i]>a[j])
            {
                int step=a[i];
                a[i]=a[j];
                a[j]=step;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%f ",a[i]);
    }
    return 0;
}
