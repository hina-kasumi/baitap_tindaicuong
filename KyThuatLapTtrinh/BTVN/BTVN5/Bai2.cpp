/*hãy xây dựng cấu trúc Thisinh gồm:
hoten, diem, truong với giả thiết chỉ có 3 trường đại học;
các hàm nhập xuất và các hàm cần thiết,
viết hàm main() để:
1, nhập thông tin cho n thí sinh
2, tính tổng số điểm của mỗi trường và xác định trường có tổng điểm cao nhất.
3, thống kê số lượng sinh viên tham dự của mỗi trường
4, tìm thí sinh có điểm của trường A.
5, nhập vào tên trường, in ra các thí sinh thuộc trường đó
6, Nhập và tên 1 thí sinh, in ra thông tin thí sinh đó
7, kiểm tra xem toàn bộ xem toàn bộ thí sinh của trường B có điểm đều lớn hơn x hay không, x nhập từ bàn phím
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")

//Attributes
int n;

//có thể làm được với bất kì tên trường nào
struct Thisinh
{
    char nameThiSinh[20];
    float scores;
    char schoolName[20];
};

void Input(int *x){
    scanf("%d", x);
}

void Input(float *x){
    scanf("%f", x);
}

void Input(char *str){
    fflush(stdin);
    gets(str);
}

void Input(Thisinh **students){
    *students = (Thisinh*) malloc(n * sizeof(Thisinh));
    for (int i = 0; i < n; i++){
        printf("Enter name of student: ");
        fflush(stdin);
        gets((*students + i)->nameThiSinh);

        printf("Enter student scores: ");
        Input(&(*students + i)->scores);

        printf("Enter school name: ");
        fflush(stdin);
        gets((*students + i)->schoolName);

        endl;
    }
}

void Output(Thisinh student){
    printf("%10s|%10.2f|%10s\n", student.nameThiSinh, student.scores, student.schoolName);
}

void Output(Thisinh *students, int n){
    for (int i = 0; i < n; i++){
        Output(*(students + i));
    }
}

//2, tính tổng số điểm của mỗi trường và xác định trường có tổng điểm cao nhất.
int FindIndexMax(int *arr, int n){
    int max = *arr;
    int indexMax = 0;
    for (int i = 0; i < n; i++){
        if (max < *(arr + i)){
            max = *(arr + i);
            indexMax = i;
        }
    }
    return indexMax;
}

char *MaxSchools(Thisinh *students){
    int numberOfSchools = 0;
    int  *sumOfSchool = (int*) malloc(n * sizeof(int));

    bool isTested[n] = {false};
    for (int i = 0; i < n; i++){
        if (!isTested[i]) {
            *(sumOfSchool + numberOfSchools) = (students + i)->scores;
            for (int j = i + 1; j < n; j++){
                if (!strcmp((students + i)->schoolName, (students + j)->schoolName)){
                    *(sumOfSchool + numberOfSchools) += (students + j)->scores;
                    
                    isTested[j] = true;
                }
            }            
            numberOfSchools++;
        }
    }
    return (students + FindIndexMax(sumOfSchool, numberOfSchools))->schoolName;
}

//3, thống kê số lượng sinh viên tham dự của mỗi trường
void ListNumberStudentsOfSchools (Thisinh *students){
    //int *list = (int*) malloc(n * sizeof(int));
    //memset(list, 1, n);
    bool isChecked[n];
    int numberOfSchools = 0;
    for (int i = 0; i < n; i++){
        if (!isChecked[i]){
            int count = 1;
            for (int j = i + 1; j < n; j++){
                if (!strcmp((students + i)->schoolName, (students + j)->schoolName)){
                    count++;
                    isChecked[j] = true;
                }
            }
            printf("School %s : %d\n", (students + i), count);
        }
    }
}

//4, tìm thí sinh có điểm của trường A.
Thisinh *ListStudentsOfSchools(Thisinh *students, char school[], int *numberOfSthudents){
    Thisinh *listStudents = (Thisinh*) malloc(n * sizeof(Thisinh));
    *numberOfSthudents = 0;
    for (int i = 0; i < n; i++){
        if (!strcmp((students + i)->schoolName, school)){
            *(listStudents + *numberOfSthudents) = *(students + i);
            (*numberOfSthudents)++;
        }
    }
    return listStudents;
}

//6, Nhập và tên 1 thí sinh, in ra thông tin thí sinh đó
Thisinh *FindedStudents (Thisinh *students, char *nameFind, int *count){
    Thisinh *listStudents = (Thisinh*) malloc(n * sizeof(Thisinh));
    *count = 0;
    for (int i = 0; i < n; i++){
        if (!strcmp((students + i)->nameThiSinh, nameFind)){
            *(listStudents + *count) = *(students + i);
            (*count) ++;
        }
    }
    return listStudents;
}

//7, kiểm tra xem toàn bộ xem toàn bộ thí sinh của trường B có điểm đều lớn hơn x hay không, x nhập từ bàn phím
bool AllStudentLonHonX(Thisinh *studetns, char *school, int x){
    bool check = 0;
    for (int i = 0; i < n; i++){
        if (!strcmp((studetns + i)->schoolName, school)){
            if ((studetns + i)->scores <= x)
                return 0;
            check = true;
        }
    }
    return check;
}


int main()
{
    //1, nhập thông tin cho n thí sinh
    printf("Enter n: ");
    Input(&n);

    printf("Enter information for students:\n");
    Thisinh *students;
    Input(&students);

    printf("List of students:\n");
    Output(students, n);
    endl;

    //2, tính tổng số điểm của mỗi trường và xác định trường có tổng điểm cao nhất.
    printf("the school get the highest scores: %s\n\n", MaxSchools(students));

    //3, thống kê số lượng sinh viên tham dự của mỗi trường
    ListNumberStudentsOfSchools(students);
    endl;

    //4, tìm thí sinh có điểm của trường A.
    int countStudentsOfA;
    Thisinh *studentsOfA = (Thisinh*) malloc(n * sizeof(Thisinh));
    studentsOfA = ListStudentsOfSchools(students, "A", &countStudentsOfA);
    if (countStudentsOfA){
        printf("list students from school A:\n");
        Output(studentsOfA ,countStudentsOfA);  
        endl;  
    }
    else 
        printf("SChools A have no student.\n\n");

    //5, nhập vào tên trường, in ra các thí sinh thuộc trường đó
    char searchSchool[20];
    
    printf("Enter school name: ");
    Input(searchSchool);
    int countStudentsFinded;
    Thisinh *listStudentFinded = (Thisinh*) malloc(n * sizeof(Thisinh));
    listStudentFinded = ListStudentsOfSchools(students, searchSchool, &countStudentsFinded);
    if (countStudentsFinded){
        printf("list students from %s:\n", searchSchool);
        Output(listStudentFinded ,countStudentsFinded);  
        endl;  
    }
    else 
        printf("SChools %s have no student.\n\n", searchSchool);

    //6, Nhập và tên 1 thí sinh, in ra thông tin thí sinh đó
    char searchStudents[20];
    printf("Enter student name: ");
    Input(searchStudents);
    listStudentFinded = FindedStudents(students, searchStudents, &countStudentsFinded);
    if (countStudentsFinded){
        printf("list students finded:\n");
        Output(listStudentFinded, countStudentsFinded);
        endl;  
    }
    else 
        printf("can't find this student.\n\n");
    

    //7, kiểm tra xem toàn bộ xem toàn bộ thí sinh của trường B có điểm đều lớn hơn x hay không, x nhập từ bàn phím
    float x;
    printf("Enter value for x: ");
    Input(&x);
    if (AllStudentLonHonX(students, "B", x))
        printf("All students score from B > %.2f", x);
    else
        printf("Not All students score from B > %.2f", x);



    //giải phóng bộ nhớ
    free(studentsOfA);
    free(listStudentFinded);
    free(students);
    return 0;
}
