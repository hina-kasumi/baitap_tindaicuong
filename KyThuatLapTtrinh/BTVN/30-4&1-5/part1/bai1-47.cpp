/*Viết chương trình phát sinh ngẫu nhiên mảng một chiều số nguyên a gồm 
30.000 phần tử có giá trị từ 0 đến 20.000.
Hãy thống kê tần suất xuất hiện của các phần tử trong a. */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
const int n = 3e4;
const int limit = 2e4;

int GetRandom(int min, int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int *SoLan(){
    int *LanXuatHien = (int*)malloc((limit + 1) * sizeof(int));
    for (int i = 0; i <= limit; i++)
        LanXuatHien[i] = 0;

    for (int i = 0; i < n; i++)
        LanXuatHien[GetRandom(0, limit)]++;
    return LanXuatHien;
}
int main()
{
    int *lanXuatHien = SoLan();
    for (int i = 0; i <= limit; i++)
        if(lanXuatHien[i]>0)
            printf("%d: %d\n", i, lanXuatHien[i]);
    
    
    return 0;
}
