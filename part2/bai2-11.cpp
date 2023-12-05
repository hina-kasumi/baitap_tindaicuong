/*11. Nhập ngày và tháng năm 2014 tìm ngày tiếp theo ngay sau, Ví dụ ngày 2/9 thì tiếp theo là 3/9 còn 
28/2 thì tiếp theo là 1/3; ngày 31/12 thì tiếp theo là 1/1. Biết rằng năm 2014 tháng 1,3,5,7,8,10,12 có 31 
ngày tháng 2 có 28 ngày, các tháng còn lại có 30 ngày*/
#include <stdio.h>
void ngay(int d,int m, int y)
{
	int nd,nm,ny,begin;
	nd=d+1;
	nm=m+1;
	ny=y+1;
	begin=1;
	if (d==31){
		if(m==1||m==3||m==5||m==7||m==8||m==10)printf("%d/%d/%d",begin,nm,y);
		if (m==12)printf("%d/%d/%d",begin,begin,ny);}
	if (d==30){
		if(m==4||m==6||m==9||m==11)printf("%d/%d/%d",begin,nm,y);}
	if (d>0&&d<30){
		if(m==4||m==6||m==9||m==11)printf("%d/%d/%d",nd,m,y);}
	if (d>0&&d<31){
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)printf("%d/%d/%d",nd,m,y);}
}
main()
{
	int d,m,y,nd,nm,ny,begin;
	//day month year  nextday nextmonth next year
	scanf("%d/%d/%d",&d,&m,&y);
	nd=d+1;
	nm=m+1;
	ny=y+1;
	begin=1;
	if (y%4!=0){
		if (d==28&&m==2)printf("%d/%d/%d",begin,nm,y);
		if(m==2){
			if(d>0&&d<28)printf("%d/%d/%d",nd,m,y);}
			ngay(d,m,y);
		}
			
	if (y%4==0){
	 	if (m==2){
	 		if (d==29)printf("%d/%d/%d",begin,nm,y);
			if (d>0&&d<29)printf("%d/%d/%d",nd,m,y);}
		ngay(d,m,y);}
			
}