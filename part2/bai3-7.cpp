/*7. Cần có tổng số 200000đ từ 3 loại giấy bạc 1000đ, 2000đ và 5000đ. Lập chương trình để tìm tất cả các 
phương án có thể.*/
#include<stdio.h>

int main()
{
    short money=200;
    short dem1=-1,dem2=-2,dem5=money/5+1;
    while(dem1<money)
    {
		
        if(dem5>0)
        {
            dem5--;
            dem1++;
            dem2+=2;
        }
        else
        {
            if (dem2>0)
            {
                dem2--;
                dem1+=2;
            }
        }
        printf("%hd to 5k, %hd to 2k, %hd to 1k\n",dem5,dem2,dem1);
    }
    
    return 0;
}
