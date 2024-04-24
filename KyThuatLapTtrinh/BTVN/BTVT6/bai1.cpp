/*Bài 1: Xây dựng hàm và thực hiện các công việc sau:  
1, Nhập vào một chuỗi ký tự s, xuất các từ phân biệt ra màn hình. 
2, Tìm từ có độ dài lớn nhất. 
3, Đảo ngược các từ và lưu vào chuỗi s1. 
4, Thay thế những từ có ký tự đầu là ‘t’ trong chuỗi s1 thành từ “NewWord” 
5, Thống kê tần suất xuất hiện của các ký tự trong chuỗi s. 
6, sắp xếp các từ trong s theo thứ tự từ điển tăng dần. */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")


void OutputTheoTu(char *str){
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            endl;
        else 
            printf("%c", str[i]);
    }
    
}

//2, Tìm từ có độ dài lớn nhất.  
int TimTuDaiNhat(char *str, int *start){
    int len = strlen(str);
    int max = 0;

    int tmp = 0;
    *start = 0;
    int end = len - 1;
    for (int i = 0; i < len; i++)
    {
        if (str[i + 1] == ' ' || i == len - 1){
            int soKyTu = i - tmp + 1;
            if (max < soKyTu)
            {
                max = soKyTu;
                *start = tmp;
                end = i;
            }
            tmp = i + 2;
        }
    }
    return max;
}

//5, Thống kê tần suất xuất hiện của các ký tự trong chuỗi s.
void *ThongKeSokyTu(char *str){
    int len = strlen(str);
    bool isChecked[len] = {false};
    for (int i = 0; i < len; i++)
    {
        if (!isChecked[i])
        {
            int count = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (str[i] == str[j])
                {
                    count++;
                    isChecked[j] = true;
                }
            }
            printf("%c: %d\n", str[i], count);
        }
    }
}

//6, sắp xếp các từ trong s theo thứ tự từ điển tăng dần.
void Sort(char *str){
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}


int main()
{
    char str[100];
    printf("nhap xau: ");
    gets(str);

    int len = strlen(str);
    printf("xau vua nhap la:\n");
    OutputTheoTu(str);
    endll;

    //2, Tìm từ có độ dài lớn nhất.
    printf("tu dai nhat trong chuoi la : ");
    int start;
    int max = TimTuDaiNhat(str, &start);
    for (int i = start; i <= start + max; i++)
    {
        printf("%c", str[i]);
    }
    endll;
    
    //3, Đảo ngược các từ và lưu vào chuỗi s1. 

    char *s1 =  strrev(str);
    printf("chuoi sau khi dao: %s\n\n", s1);

	//5, Thống kê tần suất xuất hiện của các ký tự trong chuỗi s. 
    ThongKeSokyTu(str);
    endl;

    //6, sắp xếp các từ trong s theo thứ tự từ điển tăng dần.
    Sort(str);
    printf("chuoi sau khi sap xep theo ma ascii: %s", str);


    free(s1);

    return 0;
}
