 /*Viết chương trình nhập vào một chuỗi ký tự s. Thực hiện các yêu cầu sau: 
- Xuất các từ phân biệt ra màn hình. 
- Tìm từ có độ dài lớn nhất. 
- Đảo ngược các từ và lưu vào chuỗi s1. 
- Thay thế những từ có ký tự đầu là ‘t’ trong chuỗi s1 thành từ “NewWord” 
- Thống kê tần suất xuất hiện của các ký tự trong chuỗi s. 
- Sắp xếp các từ trong s theo thứ tự từ điển tăng dần. 
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")

struct String
{
    char *s;
};


String *toArray(char *str, int *soTu){
    //lấy độ dài của chuỗi
    int len = strlen(str);

    //cấp phát động
    String *arr = (String*) malloc(len * sizeof(String));
    for (int i = 0; i < len; i++){
        arr[i].s = (char*) malloc(len * sizeof(char));
        memset(arr[i].s, 0 , len);
	}

    //tách các từ thành string vào mảng string
    *soTu = 0;
    for (int i = 0; i < len; i++){
        //khi nào chạy qua dấu cách hoặc lúc bắt đầu thì thực hiện
        if (!i || str[i - 1] == ' '){
            //truyền từng ký tự vào string mới cho đến khi gặp dấu cách thì truyền sang mảng mới
            for (int j = i; j < len; j++){
                if (str[j] == ' ')
                    break;
                arr[*soTu].s[j - i] = str[j];
            }
            (*soTu)++;
        }
    }
    (*soTu)++;
    return arr;
}

String LongestWord(String *str, int soTu){
    int max = strlen(str[0].s);
    int location = 0;
    for (int i = 1; i < soTu; i++){
        if (max < strlen(str[i].s)){
            max = strlen(str[i].s);
            location = i;
        }
    }
    return str[location];
}

void replace(String *str, int soTu, char startWith, char *to){
    for (int i = 0; i < soTu; i++){
        if (str[i].s[0] == startWith){
            str[i].s = to;
        }
    }
}

void Output(String *str, int soTu, char folow){
    for (int i = 0; i < soTu; i++)
        printf("%s%c", str[i], folow);
}

int *ThongKe(char *str){
    int *tanXuat = (int*)malloc(200 * sizeof(int));
    memset(tanXuat, 0, 200);
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z')
            tanXuat[str[i]]++;
    }
    return tanXuat;
}

void swap(String *a, String *b){
    String x = *a;
    *a = *b;
    *b = x;
}

int partition(String *str, int low, int high){
    String pivot = str[high];
    int i = low - 1;
    for (int j = low; j <= high; j++){
        if (strcmp(str[j].s, pivot.s) == -1){
            i++;
            swap(str + i, str + j);
        }
    }
    swap(str + i + 1, str + high);
    return i + 1;
}

void QuickSort(String *str, int low, int high){
    if (low < high){
        int pi = partition(str, low, high);

        QuickSort(str, low, pi - 1);
        QuickSort(str, pi + 1, high);
    }
}

int main()
{
    char str[100];
    printf("nhap mot xau: ");
    gets(str);

    //1, Xuất các từ phân biệt ra màn hình. 
    int soTu;
    String *arr = toArray(str, &soTu);
    printf("in cac tu tren mot dong:\n");
    Output(arr, soTu, '\n');
    
    //2, Tìm từ có độ dài lớn nhất.
    printf("tu co do dai lon nhat la: %s\n\n", LongestWord(arr, soTu));

    //3 Đảo ngược các từ và lưu vào chuỗi s1.
    char *s1 = str;
    printf("chuoi sau khi dao: %s\n\n", strrev(s1));

    //4, Thay thế những từ có ký tự đầu là ‘t’ trong chuỗi s1 thành từ “NewWord” 
    replace(arr, soTu, 't', "NewWord");
    printf("chuoi sau khi duoc doi: ");
    Output(arr, soTu, ' ');
    

    //5, Thống kê tần suất xuất hiện của các ký tự trong chuỗi s.
    printf("\n\nthong ke so luong ky tu trong string: ");
    int *tanXuat = (int*) malloc(200 * sizeof(int));
    tanXuat = ThongKe(str);
    for (int i = 'A'; i <= 'z'; i++){
        if(*(tanXuat + i))
            printf("%c: %d\n", i, tanXuat[i]);
    }
    
    QuickSort(arr, 0, soTu);
    printf("chuoi sau khi duoc xep lai la: "); Output(arr, soTu, ' ');

    free(arr);
    return 0;
}
