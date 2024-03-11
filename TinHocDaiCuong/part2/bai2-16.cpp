/*16. Viết chương trình tính tiền cước TAXI. Biết rằng:
km đầu tiên là 13000đ
Mỗi km tiếp theo là 12000đ
Nếu lớn hơn 30km thì mỗi km thêm sẽ là 11000đ
Hãy nhập số km sau đó in ra số tiền phải trả.
*/
#include<stdio.h>
int main()
{
    int km,money=0;
    printf("nhap quang duong ban muon di km = ");
    scanf("%d",&km);
    if(km>=1) 
    {
        money=13;
    }
    if (km>1 && km<=30)
    {
        money=money+(km-1)*12;
    }
    if (km>30)
    {
        money+=29*12;
        money+=(km-30)*11;
    }
    printf("so tien phai tra sau khi di %dkm la: %d000",km,money);
    return 0;
}
