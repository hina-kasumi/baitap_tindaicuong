// Nhập dãy n số nguyên từ bàn phím. In các số dương lẻ trên một dòng. Liệt kê các bộ 3 số
//liên tiếp tạo thành cấp số cộng trong dãy số đó (in ra màn hình theo dạng bộ ba (a1, a2, a3))
#include<stdio.h>
int main()
{
    int phantu;
    printf("nhap so phan tu cua day: ");
    scanf("%d",&phantu);
    int day[phantu];
    for (int dem1 = 0; dem1 < phantu; dem1++)
    {
        scanf("%d",&day[dem1]);
    }
    //in cac so duong le 
    printf("cac so le duong trong day la: \n");
    for (int dem1 = 0; dem1 < phantu; dem1++)
    {
        if (day[dem1]>0 && day[dem1]%2!=0)
        {
            printf("%d ",day[dem1]);
        }
    }
    printf("\n");
    //in 3 so lien tiep tao thanh cap so cong
    float trungbinh;
    int check=0;
    for (int dem1 = 0; dem1 < phantu; dem1++)
    {
        for (int dem2 = dem1+1; dem2 < phantu; dem2++)
        {
            trungbinh=1.0*(day[dem1]+day[dem2])/2;
            for (int dem3 = 0; dem3 < phantu; dem3++)
            {
                if (dem1!=dem2 && dem1!=dem3 && dem3!=dem2)
                {
                    if (trungbinh==day[dem3])
                    {
                        if (day[dem1]<day[dem2])
                        {
                            printf("(%d,%d,%d)\n",day[dem1],day[dem3],day[dem2]);
                        }
                        if (day[dem1]>day[dem2])
                        {
                            printf("(%d,%d,%d)\n",day[dem2],day[dem3],day[dem1]);
                        }
                        if (day[dem1]==day[dem2] && check==0)
                        {
                            printf("(%d,%d,%d)\n",day[dem1],day[dem3],day[dem2]);
                            check++;
                        }
                        
                    }   
                }   
            }    
        }
    }
    return 0;
}