/*Nhập vào một ma trận vuông kiểu nguyên cấp nxn
-	In ra màn hình dưới dạng bảng
-	Tìm min của ma trận
-	Tìm min các phần tử âm của ma trận
-	Tính tổng từng cột, cho biết các cột có tổng lớn nhất
-	Tìm max từng hàng
-	Đếm các phần tử dương lớn hơn 10 có trong ma trận
-	Kiểm tra xem ma trận có phải ma trận tam giác dưới hay không. Tính tích các phần tử âm thuộc đường chéo phụ
-	Tính trung bình cộng các phần tử lớn hơn 10 có trong ma trận
-	Đếm xem trong ma trận có bao nhiêu phần tử nằm trong đoạn [5, 30]
-	Tính tổng từng hàng, cho biết các hàng có tổng lớn nhất
-	Tính trung bình cộng các phần tử dương thuộc cột lẻ trong dãy
-	Nhập số hàng và cột bằng nhau, kiểm tra ma trận có phải tam giác trên hay không
-	Tính trung bình cộng các phần tử trên đường chéo phụ.
-	Kiểm tra xem ma trận có phải ma trận đối xứng hay không.
-	Tìm max các phần tử nằm phía dưới đường chéo chính
-	Kiểm tra xem ma trận có các tổng hàng nào có giá trị bằng nhau hay không
-	Tìm max của từng cột.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define endl printf("\n")
#define endll printf("\n\n")

//nhap mot phan tu
void Input(int *x){
    scanf("%d", x);
}

//hàm nhập cho một mảng 1 chiều
void Input(int *hang, int n){
    for (int i = 0; i < n; i++)
    {
        Input(hang + i);
    }
}

//hàm nhập vào giá trị của một ma trận
void Input(int **matrix, int n){
    for (int i = 0; i < n; i++)
    {
        Input(*(matrix + i), n);
    }
}


//hàm in ra màn hình một số nguyên
void Output(int x){
    printf("%d ", x);
}

//hàm in ra một dãy số nguyên
void Output(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        Output(*(arr + i));
    }
    endl;
}

//hàm in ra một ma trận 
void Output(int **matrix, int n){
    for (int i = 0; i < n; i++)
    {
        Output(*(matrix + i), n);
    }
    endl;
}



//tìm min trong một mảng
int Min(int *arr, int n){
    int min = *arr;
    for (int i = 0; i < n; i++)
    {
        min = (min > *(arr + i))? *(arr + i):min;
    }
    return min;
}

//tìm giá trị nhỏ nhất tỏng ma trận
int Min(int **matrix, int n){
    int min = **matrix;
    for (int i = 0; i < n; i++)
    {
        int tmp = Min(*(matrix + i), n);
        min = (min > tmp)? tmp:min;
    }
    return min;
}

//tìm cột có tổng giá tri lớn nhất
//tìm giá trị lớn nhất của một mảng
int Max(int *arr, int n){
    int max = *arr;
    for (int i = 0; i < n; i++)
    {
        max = (max < *(arr + i))? *(arr + i):max;
    }
    return max;
}

//hàm tính tổng các phần tử trong một mảng
int Tong(int *arr, int n){
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += *(arr + i);
    }
    return tong;
}

//tính tổng các phần tử và tìm giá trị lớn nhất
int TongMax(int **matrix, int n){
    // khai báo một mảng để chứa các tổng của các cột
    int *tong = (int*) malloc (n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        *(tong + i) = 0;
        for (int j = 0; j < n; j++)
        {
            *(tong + i) += *(*(matrix + j) + i);
        }
    }

    //tìm tổng lớn nhất
    int max = Max(tong, n);
    return max;
}

//tìm các phần tử lớn hơn x
int *Find(int **matrix, int n, int x, int *count){
    int *list = (int*) malloc(n * sizeof(int));
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(*(matrix + i) + j) > x)
            {
                *(list + *count) = *(*(matrix + i) + j);
                (*count)++;
            }
        }
    }
    return list;
}

//kiểm tra ma trận có phải là tam giác dưới hay không
bool TamGiacDuoi(int **matrix, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (*(*(matrix + i) + j) != 0){
                return false;
            }
        }
    }
    return true;
}


//Tính tích các phần tử âm thuộc đường chéo phụ
int TichAm(int **matrix, int n, int *check){
    *check = 0;

    //tạo biến chứa kết quả tính được
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        if (*(*(matrix + i) + ((n - 1) - i)) < 0)
        {
            result *= *(*(matrix + i) + ((n - 1) - i));
            *check = 1;
        }
    }
    return result;
}


//hàm tính trung bình công của một mảng
float TBC (int *arr, int n){
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += (float) (*(arr + i));
    }
    return result/n;
}

//Đếm xem trong ma trận có bao nhiêu phần tử nằm trong đoạn [x, y]
int CountXY(int **matrix, int n, int x, int y){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(*(matrix + i) + j) >= x && *(*(matrix + i) + j) <= y)
            {
                count++;
            }
        }
    }
    return count;
}


//tính trung bình cộng các giá trị dương của cột lẻ
float *TBCDuongLe(int **matrix, int n, int *check){
    *check = false;

    float *tbc = (float*) malloc(n * sizeof(float));

    for (int cot = 0; cot < n; cot+=2)
    {
        int count  = 0;
        *(tbc + cot) = 0;
        for (int hang = 0; hang < n; hang++)
        {
            if(*(*(matrix + hang) + cot) > 0)
            {
                *(tbc + cot) += (float) *(*(matrix + hang) + cot);
                count ++;
                *check = true;
            }
        }
        *(tbc + cot) /= count;
    }
    return tbc;
}

//kiểm tra ma trận có phải là tam giác trên hay không
bool TamGiacTren(int **matrix, int n){
    for (int i = 1; i < n ; i++){
        for (int j = 0; j < i; j++){
            if (*(*(matrix + i) + j) != 0){
                return false;
            }
        }
    }
    return true;
}

//Tính tbc các phần tử thuộc đường chéo phụ
float TbcCheoPhu(int **matrix, int n){

    //tạo biến chứa kết quả tính được
    float result = 0;

    for (int i = 0; i < n; i++)
    {
        result += (float) *(*(matrix + i) + ((n - 1) - i));
    }
    return result/n;
}

//kiểm tra ma trận có đối xứng không
bool DoiXung(int **matrix, int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (*(*(matrix + i) + j) != *(*(matrix + j) + i))
            {
                return false;
            }
        }
    }
    return true;
}

//Tìm max các phần tử nằm phía dưới đường chéo chính
int MaxCheoChinh(int **matrix, int n){
    int max = *(*matrix);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            max = (max < *(*(matrix + i) + j))? *(*(matrix + i) + j):max;
        }
    }
    return max;
}

int main()
{
    //nhập kích cỡ ma trận
    int n;
    printf("nhap kich co cua ma tran vuong: ");
    Input(&n);


    //khai báo cấp phát động mảng 2 chiều
    int **matrix;
    matrix = (int**) malloc(n * sizeof(int*));

    //khai báo cho các phẩn tử mảng
    for (int i = 0; i < n; i++)
    {
        *(matrix + i) = (int*) malloc(n * sizeof(int));
    }
    
    //nhập cho các phần tử của mảng
    Input(matrix, n);
    endl;

    //in ra các ma trận vừa nhập
    printf("ma tran ban vua nhap la:\n");
    Output(matrix, n);

    //cách hoạt động đơn giản của hàm in
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        endl;
    }
    */

    //Tìm min của ma trận
    int min = Min(matrix, n);
    printf("gia tri nho nhat trong ma tran la: %d\n\n", min);


    //Tìm min các phần tử âm của ma trận
    if (min < 0)
        printf("gia tri min am trong ma tran la: %d\n\n", min);
    else
        printf("khong co gia tri min trong ma tran.\n\n");
    

    //Tính tổng từng cột, cho biết các cột có tổng lớn nhất
    printf("cot co tong lon nhat = %d\n\n", TongMax(matrix, n));



    //Tìm max từng hàng
    for (int i = 0; i < n; i++)
    {
        int max = Max(*(matrix + i), n);
        printf("max hang %d = %d\n", i + 1, max);
    }
    endl;



    //Đếm các phần tử dương lớn hơn 10 có trong ma trận
    int count;
    int *list = Find(matrix, n, 10, &count);
    if(count){
        printf("nhung so lon hon 10: ");
        Output(list, count);
        endl;
    } else {
        printf("khong co so nao lon hon 10.\n\n");
    }


    //Kiểm tra xem ma trận có phải ma trận tam giác dưới hay không.
    if(TamGiacDuoi(matrix, n))
        printf("day la ma tran tam giac duoi.\n\n");
    else
        printf("khong phai la ma tran tam giac duoi.\n\n");


    //Tính tích các phần tử âm thuộc đường chéo phụ
    int check;
    int tichAm = TichAm(matrix, n, &check);
    if (check)
    {
        printf("tich cac gia tri am tren duong cheo phu = %d\n\n", tichAm);
    }
    else
        printf("tren duong cheo phu khong co so am.\n\n");
    

    //Tính trung bình cộng các phần tử lớn hơn 10 có trong ma trận
    if(count){
        printf("trung binh cong cua cac phan tu lon hon 10 = %.2f\n\n", TBC(list, count));
    } else {
        printf("khong co so nao lon hon 10.\n\n");
    }
    
    

    //Đếm xem trong ma trận có bao nhiêu phần tử nằm trong đoạn [5, 30]
    printf("co %d phan tu thuoc [5, 30]\n\n", CountXY(matrix, n, 5, 30));


    //Tính tổng từng hàng, cho biết các hàng có tổng lớn nhất
    for (int i = 0; i < n; i++)
    {
        *(list + i) = Tong(*(matrix + i), n);
        printf("hang %d co tong = %d\n", i + 1, *(list + i));
    }
    
    //tìm hàng có tổng lớn nhất
    printf("hang co tong lon nhat = %d\n\n", Max(list, n));



    //Tính trung bình cộng các phần tử dương thuộc cột lẻ trong dãy
    float *Cot = TBCDuongLe(matrix, n, &count);

    if (count)
    {
        for (int i = 0; i < n; i+=2)
        {
            printf("cot %d co tbc cac gia tri duong le = %f\n", i + 1, *(Cot + i));
        }
    }
    else
        printf("ma tran khong co gia tri duong le o cac cot le.\n");
    endl;

    //giải phóng bộ nhớ
    free(Cot);


    // kiểm tra ma trận có phải tam giác trên hay không
    if(TamGiacTren(matrix, n))
        printf("day la ma tran tam giac tren.\n\n");
    else
        printf("khong phai la ma tran tam giac tren.\n\n");



    //Tính trung bình cộng các phần tử trên đường chéo phụ.
    printf("tbc tren duong cheo phu = %f\n\n",TbcCheoPhu(matrix, n));

    //Kiểm tra xem ma trận có phải ma trận đối xứng hay không.
    if(DoiXung(matrix, n))
        printf("ma tran la ma tran doi xung.\n\n");
    else
        printf("ma tran nay khong doi xung.\n\n");

    //Tìm max các phần tử nằm phía dưới đường chéo chính
    printf("gia tri lon nhaat o phia duoi duong cheo chinh = %d\n", MaxCheoChinh(matrix ,n));


    //Kiểm tra xem ma trận có các tổng hàng nào có giá trị bằng nhau hay không
        //gán biến test  = đúng để xét sẽ loại dần phần tử dã xét r
        bool *test = (bool*) malloc(n * sizeof(bool));
        for (int i = 0; i < n; i++)
        {
            *(test + i) = true;
        }

        //biến này để kiểm tra xem có hàng nào bằng nhau không nếu không có thì in thông báo không có
        check = 1;
        for (int i = 0; i < n - 1; i++)
        {
            //biến này dùng để giới hàn hàm in thông điệp một lần
            count = 1;

            //nếu như mà số này xét rồi thì skip chưa thì sẽ kiểm tra
            if (*(test + i))
            {
                //tìm xem có tồng hàng nào = nhau không
                for (int j = i + 1; j < n; j++)
                {
                    //nếu có thì thực hiện lệnh
                    if (*(list + i) == *(list + j))
                    {
                        //hàm count mới đầu là 0 nên sẽ chạy thông điệp này và sau khi chạy xong sẽ tắt thông điệp chạy
                        if(count)
                            printf("\ncac hang co tong = nhau la: %d ", i + 1);
                        count = 0;

                        //đánh dấu là số thứ gì này đã kiểm tra rồi không cần kiểm tra lần sau nữa
                        *(test + j) = false;
                        
                        // in ra những tổng hàng bằng nhau
                        Output(j + 1);

                        //do đã tìm thấy tổng hàng bằng nhau thì đánh dấu là có tồn tại tổng hàng bằng nhau
                        check = 0;
                    }
                }
            }
        }
        //nếu không tìm thấy thì sẽ chạy hàm này
        if(check)
            printf("\nkhong co tong hang nao bang nhau.");
    


    //giải phóng bộ nhớ list và test
    free(list);
    free(test);
    
    //giải phóng bộ nhớ của các con trỏ phần tử
    for (int i = 0; i < n; i++)
    {
        free(*(matrix + i));
    }
    
    //giả phóng bộ nhớ của con trỏ 2 sao
    free(matrix);
    return 0;
}