/*Câu 2: Xây dựng một cấu trúc ứng với phiếu điểm của thí sinh thi học sinh giỏi gồm các 
thành phần:Họ tên,Quê quán,Trường(giả sử có 3 trường dự thi là , , C), Số báo danh,Điểm 
thi. Nhập, xuất n thí sinh. Viết chương trình thực hiện:
- Tìm kiếm và in ra các thí sinh có điểm thi >= 15
- Sắp xếp lại các phần tử của mảng cấu trúc theo thứ tự giảm dần của điểm, sau đó in 
danh sách thí sinh.
- Thống kê số sinh viên dự thi của 3 trường.*/
#include<stdio.h>
#include<string.h>
#define nn printf("\n")
struct hsg
{
    char name[20],que[20],school[20];
    int sbd;
    float diem;
};

void in(hsg hs[],int i)
{
    printf("%10s%10s%10s%13d%10.2f\n",hs[i].name,hs[i].que,hs[i].school,hs[i].sbd,hs[i].diem);
}

void bang()
{
    printf("\tho ten\t que\ttruong\t\tsbd\tdiem\n");
}

void cau_b(hsg hs[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (hs[i].diem<hs[j].diem)
            {
                hsg tmp = hs[i];
                hs[i] = hs[j];
                hs[j] = tmp;
            }
        }
    }
}

bool check(hsg hs[],int n)
{
    for (int i = 0; i < n; i++)
    {
        if(hs[i].diem>=15) return 1;
    }
    return 0;
}

int main()
{
    int n;
    do
    {
        printf("so phieu diem cua cac hsg: ");
        scanf("%d",&n);
    } while (n<1);
    hsg hs[n];
    printf("nhap thong tin cho cac ho sinh do:\n");
    for (int i = 0; i < n; i++)
    {
        printf("hoc sinh thu %d\n",i+1);
        printf("ten: ");
        fflush(stdin);
        gets(hs[i].name);
        printf("que: ");
        fflush(stdin);
        gets(hs[i].que);
        printf("truong: ");
        fflush(stdin);
        gets(hs[i].school);
        printf("sbd: ");
        scanf("%d",&hs[i].sbd);
        printf("diem thi: ");
        scanf("%f",&hs[i].diem);
    }
    //0,
    nn;
    printf("\nthong tin hoc sinh ban vua nhap:\n");
    bang();
    for (int i = 0; i < n; i++)
    {
        in(hs,i);
    }
    //1,
    nn;
    if (check(hs,n))
    {
        printf("\nnhung thi simh co diem thi >=15\n");
        bang();
        for (int i = 0; i < n; i++)
        {
            if (hs[i].diem>=15) in(hs,i);
        }
    }
    else printf("khong co hoc sinh nao diem >=15.");
    nn;
    //2,
    
    printf("\ndanh sach thi sinh sau khi xap xep theo diem giam dan\n");
    bang();
    cau_b(hs,n);
    for (int i = 0; i < n; i++)
    {
        in(hs,i);
    }
    nn;
    //3,
    int check[n]={0};
    for (int i = 0; i < n; i++)
    {
        int dem=1;
        if (!check[i])
        {
            for (int j = i+1; j < n; j++)
            {
                if(!stricmp(hs[i].school,hs[j].school))
                {
                    dem++;
                    check[j]=1;
                }
            }
        }
        if(!check[i]) printf("\ntruong %s co %d hoc sinh.",hs[i].school,dem);
    }
    return 0;
}
