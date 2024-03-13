/*Câu 1. Xây dựng một cấu trúc ThiSinh (Thí sinh ), 
trong đó có các thuộc tính mã sinh viên, tên sinh viên, điểm trung bình, trường (Giả sử chỉ có 3 trường A, B, C). 
Viết hàm main() để:
o	Nhập, xuất n thí sinh
o	Tìm kiếm tất cả các thí sinh có điểm cao nhất
o	Sắp xếp thí sinh theo điểm tăng dần
o	Tìm kiếm và in ra màn hình các thí sinh có 
điểm trung bình lớn hơn 5 điểm của trường B.
o	Nhập vào một tên thí sinh, in ra thông tin của sinh viên đó
o	Thống kê số thí sinh của mỗi trường (đếm).
o	Trường nào có nhiều thí sinh nhất
o	Tìm sinh viên có điểm cao nhất của trường B.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

//xây dựng cấu trúc thí sinh
struct ThiSinh
{
    int MSV;
    char name[20];
    float mark;
    char school[20];
};


//hàm nhập cho một biến
void Input(int *x){
    scanf("%d",x);
}

//hàm nhập của một biến có kiểu dữ liệu struct
void Input(ThiSinh *students){

    //nhập mã sinh viên
    printf("Ma Sinh Vien: ");
    Input(&students->MSV);

    //nhập tên của sinh viên
    printf("Ten: ");
    fflush(stdin);
    gets(students->name);

    //nhập điểm trung bình của sinh viên
    printf("Diem Trung Binh: ");
    scanf("%f", &students->mark);

    //nhập trường của sinh viên
    printf("Truong: ");
    fflush(stdin);
    gets(students->school);

    endl;
}

//hàm nhập cho một mảng cấu trúc
void Input(ThiSinh **students, int n){

    //khai khai báo mảng động
    *students = (ThiSinh*) malloc(100 * sizeof(ThiSinh));

    printf("nhap thong tinh cho cac thi sinh:\n");
    for (int i = 0; i < n; i++)
    {
        Input(*students + i);
    }
}

//hàm xuất một biến có kiểu dữ liệu struct
void Output(ThiSinh *student){
    printf("%10d%10s%10.2f%10s\n", student->MSV, student->name, student->mark, student->school);
}

//hàm in ra danh sách thí sinh
void Output(ThiSinh *students, int n){
    printf("danh sach thi sinh ban vua nhap:\n");
    for (int i = 0; i < n; i++)
    {
        Output(students + i);
    }
}

//hàm in ra kết của của một số yêu cầu đề bài
void Out(ThiSinh *students, int n, int *dir){
    for (int i = 0; i < n && *(dir + i) >= 0 && *(dir + i) < n; i++)
    {
        Output(students + *(dir + i));
    }
}

//tìm kiếm điểm cao nhất
float HighestMark (ThiSinh *students, int n){
    //giả sử điểm của học sinh đầu tiên là điểm cao nhất
    float max = students->mark;
    //tìm điểm cao nhất
    for (int i = 0; i < n; i++)
    {
        if (max < (students + i)->mark)
        {
            max = (students + i)->mark;
        }
    }
    return max;
}
//Tìm kiếm tất cả các thí sinh có điểm cao nhất
int *HighestMarkStudent(ThiSinh *students, int n){

    //lấy điểm số cao nhất đã tìm được
    float max = HighestMark(students, n);
    
    //tạo một mảng chứa chỉ số index của những thí sinh có điểm cao nhất
    int *dir;
    dir = (int*) malloc(n * sizeof(int));

    //tạo một biến ảo để truyền index
    int tmp = 0;

    //tìm những thí sinh có điểm cao nhất
    for (int i = 0; i < n; i++)
    {
        if (max == (students + i)->mark)
        {
            *(dir + tmp) = i;
            tmp++;
        }
    }
    return dir;

}

//Sắp xếp thí sinh theo điểm tăng dần
void Sort(ThiSinh *students, int n){
    for (int i = 0; i < n -1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((students + i)->mark > (students + j)->mark)
            {
                ThiSinh tmp = *(students + i);
                *(students + i) = *(students + j);
                *(students + j) = tmp;
            }
        }
    }
}

//Tìm kiếm và in ra màn hình các thí sinh có điểm trung bình lớn hơn x điểm của 1 trường .
int *Find(ThiSinh *students, int n, float point, char truong[], int  *check){
    //tạo mảng 2 có để chứa những index của những thí sinh thỏa mãn
    int *dir;
    dir = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (!strcmpi((students + i)->school, truong) && (students + i)->mark > point)
        {
            *(dir + *check) = i;
            (*check)++;
        }
    }

    return dir;
}

//hàm tìm người sau khi nhập tên
int *Search(ThiSinh *students, int n, char *search,int *check){
    int *dir;
    dir = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if(!strcmpi((students + i)->name, search)){
            *(dir + *check) = i;
            (*check)++;
        }
    }
    return dir;
}

//thống kê số thí sinh của mỗi trường
void Statistics(ThiSinh *students, int n, int *studentsOfSchools){
    bool check[n];

    for (int i = 0; i < n; i++)
    {
        *(studentsOfSchools + i) = 0;
        if(!check[i])
        {
            *(studentsOfSchools + i) = 1;
            for (int j = i + 1; j < n; j++)
            {
                if(!strcmpi((students + i)->school, (students + j)->school))
                {
                    (*(studentsOfSchools + i)) ++;
                    *(check + j) = true;
                }
            }
        }
    }
}

//tìm thí sinh điểm cao nhất của 1 trường.
int DiemCaoNhat(ThiSinh *students, int n, int *check, char truong[]){
    *check = false;
    float max = 0;
    int dir = -1;
    for (int i = 0; i < n; i++)
    {
        if(!strcmpi((students + i)->school, truong)){
            *check = true;
            if (max < (students + i)->mark)
            {
                max = (students + i)->mark;
                dir = i;
            }
        }
    }
    
    return dir;
}

//tìm giá trị lớn nhất
int Max(int *arr, int n){
    //giả sử giá trị lớn nhất là phần từ đầu tiên trong dãy
    int max = *arr;
    int dir = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
            dir = i;
        }
    }
    
    return dir;
}

int main()
{
    //nhập và khai báo n
    int n;
    printf("nhap so thi sinh can quan ly: ");
    Input(&n);

    //khai báo con trỏ có kiểu dữ liệu struct
    ThiSinh *students;

    //nhập dữ liệu cho struct
    Input(&students, n);

    //xuất ra dữ liệu bạn vừa nhập
    Output(students, n);

    endl;

    //1,Tìm kiếm tất cả các thí sinh có điểm cao nhất
    int *dir = HighestMarkStudent(students, n);

    //in ra những thí sinh điểm cao nhất
    printf("danh sach thi sinh co diem cao nhat:\n");
    Out(students, n, dir);

    //giải phóng bộ nhớ
    free(dir);
    endl;

    //2, Sắp xếp thí sinh theo điểm tăng dần
    Sort(students, n);
    printf("danh sach thi sinh sau khi dc xap xep tang dan:\n");
    Output(students, n);
    endl;
    
    //Tìm kiếm và in ra màn hình các thí sinh có điểm trung bình lớn hơn 5 điểm của trường B.
    int check = 0;
    dir = Find(students, n, 5, "B", &check);

    //kiểm tra bắt lỗi
    if (check > 0)
    {
        printf("danh sach thi sinh truong B co diem lon hon 5:\n");
        Out(students, n, dir);
    } else {
        printf("khong co thi sinh truong B nao diem lon hon 5.\n");
    }

    //giải phóng bộ nhớ
    free(dir);
    endl;

    //3,Nhập vào một tên thí sinh, in ra thông tin của sinh viên đó
    //khai báo và nhập tên cần tìm
    char search[20];
    fflush(stdin);
    gets(search);

    //tận dụng lại biến check đã khai báo ở câu trên
    check = 0;

    
    dir = Search(students, n, search, &check);
    if(check){
        printf("day la danh sach sinh vien co ten %s\n", search);
        Out(students, n, dir);
    }
    else 
        printf("khong tim thay sonh vien can tim");
    

    //giải phóng bộ nhớ
    free(dir);
    endl;

    //4,Thống kê số thí sinh của mỗi trường (đếm).

    //khai báo mảng đểm đếm xem mỗi trường có bao nhiêu thí sinh
    int *studentsOfSchool = (int*) malloc(n * sizeof(int));

    //đếm
    Statistics(students, n, studentsOfSchool);
    printf("thong ke thi sinh du thi cua tung truong:\n");
    for (int i = 0; i < n; i++)
    {
        if(*(studentsOfSchool + i))
        {
            printf("%s: %d thi sinh\n",(students + i)->school, *(studentsOfSchool + i));
        }
    }
    endl;
    
    //Trường nào có nhiều thí sinh nhất
    int dirMax = Max(studentsOfSchool, n);
    printf("truong %s co nhieu thi sinh nhat.\n\n", (students + dirMax)->school);

    //tìm sinh viên có điểm cao nhất trường B
    int dirB = DiemCaoNhat(students, n , &check, "B");
    if (check)
    {
        printf("sinh vien co diem cao nhat truong B:\n");
        Output(students + dirB);
    }
    else
        printf("khong co sinh vien truong B");
   

    //giải phóng bộ nhớ
    free(studentsOfSchool);
    free (students);
    return 0;
}