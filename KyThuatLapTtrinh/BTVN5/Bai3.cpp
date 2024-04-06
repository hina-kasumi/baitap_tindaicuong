/*xây dựng cấu trúc môn học gồm:
mã môn, tên môn, số tín chỉ
xây dựng cấu trúc kỳ học bao gồm:
mã ký học, số môn học và danh sách các môn học
viết chương trình nhập vào số các môn học, số ký học. tính tổng số tín chỉ của từng kỳ học
cho biết kỳ nào có nhiều tín chỉ nhất.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")

struct Subject
{
    int codeSubject;
    char nameSubject[20];
    int numberOfCredit;
};

struct Semester
{
    int codeSemster;
    int numberOfSubjects;
    Subject *subject;
};

void Input(Subject *subject){
    printf("Enter code of subject: ");
    scanf("%d", &subject->codeSubject);

    printf("Enter subject: ");
    fflush(stdin);
    gets(subject->nameSubject);

    printf("Enter number Credit of subject: ");
    scanf("%d", &subject->numberOfCredit);

    endl;
}

void Input(Semester *semester, Subject *subjects, int numberOfSubject){
    printf("Enter code of semster: ");
    scanf("%d", &semester->codeSemster);

    printf("Enter number of subjects: ");
    scanf("%d", &semester->numberOfSubjects);

    printf("Enter code of subject: ");
    semester->subject = (Subject*) malloc(semester->numberOfSubjects * sizeof(Subject));

    for (int i = 0; i < semester->numberOfSubjects; i++)
    {
        scanf("%d", &(semester->subject + i)->codeSubject);
        for (int j = 0; j < numberOfSubject; j++)
        {
            if ((semester->subject + i)->codeSubject == (subjects + j)->codeSubject)
            {
                *(semester->subject + i) = *(subjects + j);
                break;
            }
        }
    }
    endl;
}

void Output(Subject subject){
    printf("%10d|%10s|%10d\n", subject.codeSubject, subject.nameSubject, subject.numberOfCredit);
}

void Output(Semester semester){
    printf("\n%10d:\n", semester.codeSemster);
    for (int i = 0; i < semester.numberOfSubjects; i++)
    {
        Output(*(semester.subject + i));
    }
}

int MaxCredit(Semester *semester, int numberOfSemester){
    int max = 0;
    int indexOfMax = -1;
    for (int i = 0; i < numberOfSemester; i++)
    {
        int num = 0;
        for (int j = 0; j < semester->numberOfSubjects; j++)
        {
            num += ((semester + i)->subject + j)->numberOfCredit;
        }
        if (max < num){
            max = num;
            indexOfMax = i;
        }
    }
    return indexOfMax;
}


int main()
{
    //nhập số môn học
    int numberOfSubjects;
    printf("Enter how many subjects: ");
    scanf("%d", &numberOfSubjects);

    printf("Enter infomation of subjects:\n");
    Subject *subjects = (Subject*) malloc(numberOfSubjects * sizeof(Subject));
    for (int i = 0; i < numberOfSubjects; i++)
        Input(subjects + i);
    printf("list subjects:\n");
    for (int i = 0; i < numberOfSubjects; i++)
        Output(*(subjects + i));

    //nhập số kỳ học
    int numberOfSemester;
    printf("Enter how many Semester: ");
    scanf("%d", &numberOfSemester);

    Semester *semesters = (Semester*) malloc(numberOfSemester * sizeof(Semester));
    printf("Enter information about semester:\n");
    for (int i = 0; i < numberOfSemester; i++)
        Input(semesters + i, subjects, numberOfSubjects);

    printf("List semester:\n");
    for (int i = 0; i < numberOfSemester; i++)
        Output(*(semesters + i));

    printf("\nsemester get most of number credit is: %d", (semesters + MaxCredit(semesters, numberOfSemester))->codeSemster);



/*5
1
1
1
2
2
2
3
3
3
4
4
4
5
5
5
3
1
3
1 2 3
2
3
3 4 5
3
3
1 3 5*/
    
    return 0;
}
