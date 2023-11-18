#include<stdio.h>
#include<math.h>
int main()
{
    int hang,x=0,y=1;
    back: printf("nhap so toa do muon tao: ");
    scanf("%d",&hang);
    if (hang<1) goto back;
    float toado[hang][2];
    printf("nhap toa do: ");
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%f",&toado[i][j]);
        }
    }
    for (int i = 0; i < hang; i++)
    {
            printf("toa do thu %d la (%f,%f)\n",i+1,toado[i][x],toado[i][y]);
    }
    //b,Đếm số điểm nằm trong góc phần tư thứ 2, và in các điểm đó ra màn hình.
    int dem=0;
    for (int i = 0; i < hang; i++)
    {
        if (toado[i][x]<0 && toado[i][y]>0)
        {
            printf("toa do trong goc phan tu thu 2 la: (%f,%f)\n",toado[i][x],toado[i][y]);
            dem++;
        }
    }
    if (dem==0) printf("b,khong co diem nao thoa man\n");
    //c. Đếm số điểm nằm phía trên đường phân giác của góc phần tư thứ nhất và in kết quả ra 
//màn hình.
    dem=0;
    for (int i = 0; i < hang; i++)
    {
        if (toado[i][x]>0 && toado[i][y]>0 && toado[i][x]<toado[i][y])
        {
            printf("toa do tren duong phan giac goc phan tu thu 1 la: (%f,%f)\n",toado[i][x],toado[i][y]);
            dem++;
        }
    }
    if (dem==0) printf("c,khong co diem nao thoa man\n");
    /*d. Nhập 2 số thực a và b. Đếm rồi in ra màn hình số điểm nằm phía trên đường thẳng y = 
ax + b*/
    float a,b;
    printf("nhap a va b: ");
    scanf("%f%f",&a,&b);
    dem=0;
    for (int i = 0; i < hang; i++)
    {
        if (toado[i][y]-a*toado[i][x]-b > 0)
        {
            dem++;
        }
    }
    if (dem==0) printf("d,khong co diem nao thoa man\n");
    else printf("so diem nam phia tren duong thang la: %d\n",dem);
    /*e. Trong số các đoạn thẳng tạo bởi 2 trong số các điểm đã nhập, tính rồi in ra màn hình 
độ dài của đoạn thẳng dài nhất.*/
float max=0,khoangcach;
    for (int i = 0; i < hang-1; i++)
    {
        for (int j = i+1; j < hang; j++)
        {
            khoangcach=sqrt(pow(toado[i][x]-toado[j][x],2)+pow(toado[i][y]-toado[j][y],2));
            if (max<khoangcach)
            {
                max=khoangcach;
            }
        }
    }
    printf("do dai cua doan thang dai nhat la: %f\n",max);
    /*f. Đếm số đoạn thẳng cắt trục hoành*/
    dem=0;
    for (int i = 0; i < hang-1; i++)
    {
        for (int j = i+1; j < hang; j++)
        {
            if (toado[i][y]*toado[j][y]<=0)
            {
                dem++;
            }   
        }
    }
    printf("so doan thang cat truc hoanh la: %d\n",dem);
    /*g. Đếm số điểm nằm phía ngoài đường tròn tâm O(0,0) bán kính R (đơn vị), với R là số 
thực nhập từ bàn phím*/
    float R;
    printf("nhap ban kinh R cua duong tron tam O: ");
    scanf("%f",&R);
    dem=0;
    for (int i = 0; i < hang; i++)
    {
        if (sqrt(pow(toado[i][x],2)+pow(toado[i][y],2))>R)
        {
            dem++;
        }
    }
    printf("so diem nam ngoai duong tron tam O ban kinh R=%f la %d\n",R,dem);
    /*h. Đếm số đoạn thẳng có một đầu mút nằm trong đường tròn tâm O(0,0) bán kính r và 
một đầu mút nằm ngoài đường tròn đó, với r nhập từ bàn phím.*/
    printf("nhap ban kinh r cua duong tron tam O: ");
    scanf("%f",&R);
    dem=0;
    for (int i = 0; i < hang-1; i++)
    {
        for (int j = i+1; j < hang; j++)
        {
            if (sqrt(pow(toado[i][x],2)+pow(toado[i][y],2))>R && sqrt(pow(toado[j][x],2)+pow(toado[j][y],2))<R) dem++;
            if (sqrt(pow(toado[i][x],2)+pow(toado[i][y],2))<R && sqrt(pow(toado[j][x],2)+pow(toado[j][y],2))>R) dem++;
        }
    }
    printf("so duong cat duong tron tam O ban kinh R=%f la %d\n",R,dem);
    /*i. Nhập số thực dương L rồi đếm và in ra màn hình số các đoạn thẳng tạo bởi 2 trong số 
các điểm đã nhập mà độ dài của chúng nhỏ hơn L*/
    float L;
    nhaplai: printf("nhap do dai L: ");
    scanf("%f",&L);
    if(L<=0) goto nhaplai;
    for (int i = 0; i < hang-1; i++)
    {
        for (int j = i+1; j < hang; j++)
        {
            khoangcach=sqrt(pow(toado[i][x]-toado[j][x],2)+pow(toado[i][y]-toado[j][y],2));
            if (khoangcach<L)
            {
                printf("doan than ngan hon L la doan cua (%.2f,%.2f) va (%.2f,%.2f)",toado[i][x],toado[i][y],toado[j][x],toado[j][y]);
                printf(" voi do dai la %f\n",khoangcach);
            }
        }
    }
    /*j. Trong số các điểm đã nhập, in ra màn hình tọa độ của 1 điểm cách xa tâm O(0, 0) 
nhất.*/
    int i;
    float furthest=sqrt(pow(toado[0][x],2)+pow(toado[0][y],2));
    float toadox,toadoy;
    for (i = 0; i < hang; i++)
    {
        if (furthest<sqrt(pow(toado[i][x],2)+pow(toado[i][y],2)))
        {
            toadox=toado[i][x];
            toadoy=toado[i][y];
        }
    }
    printf("diem xa tam o nhat la: (%f,%f)",toadox,toadoy);
    return 0;
}
