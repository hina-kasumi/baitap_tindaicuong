#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define endl printf("\n")
#define endll printf("\n\n")
const int limit = 80;


void QuyDoiDate(tm *date){
    while (date->tm_mday > 31)
    {
        date->tm_mon++;
        date->tm_mday -= 31;
    }
    while (date->tm_mon > 12)
    {
        date->tm_year++;
        date->tm_mon -= 12;
    }
    date->tm_year -= 1900;
    date->tm_mon --;
}

void QuyDoiTime(tm *time){
    while (time->tm_sec > 59)
    {
        time->tm_min++;
        time->tm_sec -= 60;
    }
    while (time->tm_min > 59)
    {
        time->tm_hour++;
        time->tm_min -= 60;
    }
    while (time->tm_hour > 23)
        time->tm_hour -= 24;
}


void InputDate(tm *date){
    scanf("%d%d%d", &date->tm_mday, &date->tm_mon, &date->tm_year);
    // QuyDoiDate(date);
}



void InputTime(tm *time){
    scanf("%d%d%d", &time->tm_hour, &time->tm_min, &time->tm_sec);
    //QuyDoiTime(time);
}

void OutputTime(tm time){
    char *toString = (char*) malloc (limit * sizeof(char));
    strftime(toString, 80, "%X", &time);
    printf("Time: |%s|\n", toString );
}


void OutputDate(tm date){
    char *toString = (char*) malloc (limit * sizeof(char));
    date.tm_mon --;
    date.tm_year -= 1900;
    strftime(toString, 80, "%d/%m/%Y", &date);
    printf("Date: |%s|\n", toString);
}



//Hàm cập nhật thời gian bằng cách cộng thêm một số giờ, phút, và giây được cung cấp.
tm CongTime(tm time){
    tm timeThem;
    InputTime(&timeThem);

    tm res;
    res.tm_hour = time.tm_hour + timeThem.tm_hour;
    res.tm_min = time.tm_min + timeThem.tm_min;
    res.tm_sec = time.tm_sec + timeThem.tm_sec;
    QuyDoiTime(&res);
    return res;
}


//Hàm kiểm tra xem một đối tượng Thời gian có phải là thời gian hợp lệ hay không  
bool CheckTime(tm time){
    if (time.tm_hour < 0 || time.tm_hour > 23)
        return 0;
    if (time.tm_min < 0 || time.tm_min > 59)
        return 0;
    if (time.tm_sec < 0 || time.tm_sec > 59)
        return 0;
        
    return true;
}

bool CheckDate(tm date){
    if (date.tm_mday < 1 || date.tm_mday > 31)
        return 0;

    if (date.tm_mon < 0 || date.tm_mon > 11)
        return 0;

    if (date.tm_year <= -1900)
        return 0;

    return true;
}
//Hàm tính khoảng cách giữa hai đối tượng Ngày Tháng và trả về số ngày giứa 2 ngày đó. 
int khoangCach2Ngay(tm date1, tm date2){
    return (date2.tm_year - date1.tm_year)*365 + (date2.tm_mon - date1.tm_mon)*30 + (date2.tm_mday - date1.tm_mday);
}



tm CongDate(tm date, int nam, int thang, int ngay){
    tm res;
    res.tm_year = nam + date.tm_year;
    res.tm_mday = thang + date.tm_mon;
    res.tm_mday = ngay + date.tm_mday;
    
    res.tm_year += res.tm_mon/12;
    res.tm_mon %= 12;

    if (res.tm_year % 4)
    {
        res.tm_year += res.tm_mday/365;
        res.tm_mday %= 365;
    }
    else
        res.tm_year += res.tm_mday/366;
        res.tm_mday %= 366;
    
}


int main()
{
    tm time;
    printf("nhap thoi bat ky: ");
    
    InputTime(&time);
    while (!CheckTime(time)){
        printf("gio ban vua nhap khong thoa man hay nhap lai.\n");
        InputTime(&time);
        
    }
    printf("gio ban vua nhap la: ");
    OutputTime(time);
    endl;

    printf("nhap so gio, phut, giay ma ban muon cong them: ");
    OutputTime(CongTime(time));
    endl;

    printf("nhap mot ngay bat ky: ");
    tm date1;
    InputDate(&date1);

    while (!CheckDate(date1))
    {
        printf("ngay khong hop le vui long nhap lai: ");
        InputDate(&date1);
    }

    printf("ngay ban vua nhap la: ");
    OutputDate(date1);
    endl;
    
    tm date2;
    printf("nhap ngay tiep theo: ");
    InputDate(&date2);

    while (!CheckDate(date2))
    {
        printf("ngay khong hop le vui long nhap lai: ");
        InputDate(&date2);
    }

    printf("ngay "); OutputDate(date1); printf("cach ngay ");
    OutputDate(date2); printf("khoang %d ngay.", khoangCach2Ngay(date1, date2));

    return 0;
}
