/*Câu 1: Nhập, xuất một đa thức P(x) bậc n, thực hiện các yêu cầu sau:
- Nhập vào số thực x, tính S = √2021 + 𝑃(𝑥) + 𝑃′(𝑥)
- Nhập vào đa thức Q(x) bậc n, in ra màn hình hệ số của đa thức hiệu trong trường 
hợp khác bậc.*/
#include<stdio.h>
#include<math.h>
#define nn printf("\n")

void cau2 (int P[],int Q[], int n,int nq)
{
    printf("da thuc hieu: ");
    for (int i = n; i > nq; i--)
    {
        printf("%dx^%d + ",P[i],i);
    }
    for (int i = nq; i > 0; i--)
    {
        printf("%dx^%d + ",P[i]-Q[i],i);
    }
    printf("%d",P[0]-Q[0]);
}

int main()
{
    int n;
    back: printf("nhap n: ");
    scanf("%d",&n);
    if(n<1) goto back;
    int P[n+1];
    printf("nhap he so cho\n");
    for (int i = n; i > 0; i--)
    {
        printf("x^%d ",i);
        scanf("%d",&P[i]);
    }
    scanf("%d",&P[0]);
    printf("phuong trinh Px ban vua nhap: ");
    for (int i = n; i > 0; i--)
    {
        printf("%dx^%d + ",P[i],i);
    }
    printf("%d\n",P[0]);
    //1,
    float x,S=2021;
    printf("nhap so thuc x: ");
    scanf("%f",&x);
    //P(x)
    for (int i = n; i > 0; i--)
    {
        S+=(P[i]*pow(x,i)+P[i]*i*pow(x,i-1));
    }
    S+=P[0];
    printf("gia tri cua S = %f\n",sqrt(S));
    //2,
    int nq;
    back2: printf("nhap bac cua Qx: ");
    scanf("%d",&nq);
    if(nq<1)goto back2;
    int Q[n+1];
    printf("nhap he so cho\n");
    for (int i = nq; i > 0; i--)
    {
        printf("x^%d ",i);
        scanf("%d",&Q[i]);
    }
    scanf("%d",&Q[0]);
    if(n==nq) printf("bac 2 phuong trinh bang nhau nen khong co da thuc hieu.");
    else if(n>nq) cau2(P,Q,n,nq);
    else if(nq>n) cau2(Q,P,nq,n);
    return 0;
}
