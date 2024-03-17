/*một mã sách , tên sách, tác giả, giá tiền
nhập n sách, tìm sách của ông x
tìm các sách đắt nhất*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

struct Book
{
    int code;
    char name[20];
    char author[20];
    int price;
};

//nhập một biến có kiểu số nguyên
void Input(int *n){
    scanf("%d",n);
}

//hàm nhập một struct
void Input(Book *book){

    printf("ma sach: ");
    scanf("%d", &book->code);

    printf("ten sach: ");
    fflush(stdin);
    gets(book->name);

    printf("tac gia: ");
    fflush(stdin);
    gets(book->author);

    printf("gia: ");
    scanf("%d", &book->price);
}

//nhap mot danh sach sach
void Input(Book *books, int n){
    for (int i = 0; i < n; i++)
    {
        //Input(books + i);
        printf("ma sach: ");
        scanf("%d", &(books + i)->code);

        printf("ten sach: ");
        fflush(stdin);
        gets((books + i)->name);

        printf("tac gia: ");
        fflush(stdin);
        gets((books + i)->author);

        printf("gia: ");
        scanf("%d", &(books + i)->price);
        endl;
    }
}

//in mot struct
void Output(Book book){
    printf("%10d|%10s|%10s|%10d\n", book.code, book.name, book.author, book.price);
}


//in ra mot danh sach
void Output(Book *books, int n){

    for (int i = 0; i < n; i++)
    {
        Output(*(books + i));
    }
    endl;
}


//tin ra gia sach sau giam gia
void Discount (Book *books, int n){
    for (int i = 0; i < n; i++)
    {
        (books + i)->price *= 0.2;
    }
    //return books;
}


int main()
{
    //nhập sô sách
    int n;
    printf("nhap so sach can quan ly: ");
    Input(&n);
    
    //khai báo một mảng động có kiểu dữ liệu Book
    Book *books = (Book*) malloc(n * sizeof(Book));

    //input
    Input(books, n);

    //output
    Output(books, n);

    printf("gia cua cac cuon sach sau giam gia la:\n");
    Discount(books, n);
    Output(books, n);


    //giải phóng bộ nhớ
    free(books);
    return 0;
}
