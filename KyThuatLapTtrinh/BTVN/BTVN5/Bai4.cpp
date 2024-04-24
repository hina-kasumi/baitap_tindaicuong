/*xây dựng cấu trúc Điểm gồm:
hoành độ và tung độ, viết hàm và xây dựng chương trình thực hiện các yêu cầu sau
1, điếm số thuộc đường phan giác góc phần tư thứ 3
2, tìm diện tích hình trong tâm O nhỏ nhát chứa tất cả các diểm
3, tính độ dài đường gấp khúc đi qua tất cả các điểm
4, nhập và bán kính RỒI, đếm và in ra màn hình các điểm nằm ngoài đường tròn tâm O bán kính R
5, tìm một điểm thuộc góc phần tư thứ 2 gần gốc tọa độ nhất
6, đếm số đoạn thẳng cất trục hoành
7, đếm số đoạn thẳng thuộc góc phần tư thứ 2.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#define endl printf("\n")
#define endll printf("\n\n")
const float PI = 3.14;

struct Point
{
    float x, y;
};

void Input(int *x){
    scanf("%d", x);
}
void Input(float *x){
    scanf("%f", x);
}
void Input (Point *point){
    Input (&point->x);
    Input (&point->y);
}

void Input(Point **points, int n){
    *points = (Point*) malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++)
        Input(*points + i);
}

void Output (Point point){
    printf("(%.2f, %.2f) ", point.x, point.y);
}

void Output(Point *points, int n){
    for (int i = 0; i < n; i++){
        Output(*(points + i));
    }
}

//1, điếm số thuộc đường phan giác góc phần tư thứ 3
int CountThirdQuadrant(Point *points, int n){
    int res = 0;
    for (int i = 0; i < n; i++){
        if ((points + i)->x < 0 && (points + i)->y < 0 )
            res++;
    }
    return res;
}
//2, tìm diện tích hình trong tâm O nhỏ nhát chứa tất cả các diểm
float FindMax (Point *points, int n){
    float max = 0;
    for (int i = 0; i < n; i++){
        float distance = (points + i)->x * (points + i)->x + (points + i)->y * (points + i)->y;
        distance = sqrt(distance);
        
        max = (max < distance)? distance:max;
    }
    return max * max * PI;
}
//3, tính độ dài đường gấp khúc đi qua tất cả các điểm
float *DistainPerPoint(Point *points, int n){
    float *distain = (float*) malloc(n * sizeof(float));
    for (int i = 0; i < n - 1; i++){
        *(distain + i) = sqrt(pow((points + i)->x - (points + i + 1)->x, 2) + pow((points + i)->y - (points + i + 1)->y, 2));
    }
    return distain;
}

//4, nhập và bán kính R, đếm và in ra màn hình các điểm nằm ngoài đường tròn tâm O bán kính R
Point *CountOutSizeCircle(Point *points, int n, float x, int *count){
    Point *list = (Point*) malloc (n * sizeof(Point));
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < (points + i)->x * (points + i)->x + (points + i)->y * (points + i)->y)
        {
            *(list + *count) = *(points + i);
            (*count) ++;
        }
    }
    return list;
}

//5, tìm một điểm thuộc góc phần tư thứ 2 gần gốc tọa độ nhất
int IndexMinSecondQuadrant(Point *points, int n){
    int indexMin = -1;
    float min = __FLT_MAX__;
    for (int i = 0; i < n; i++)
    {
        float x = (points + i)->x * (points + i)->x + (points + i)->y * (points + i)->y;
        if ((points + i)->x < 0 && (points + i)->y > 0 && min > x)
        {
            min = x;
            indexMin = i;
        }
    }
    return indexMin;
}

//6, đếm số đoạn thẳng cất trục hoành
int CountLineCrossX(Point *points, int n){
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((points + i)->y * (points + j)->y < 0)
            {
                count ++;
            }
        }
    }
    return count;
}

//7, đếm số đoạn thẳng thuộc góc phần tư thứ 2.
int CountLineInSecondQuadrant(Point *points, int n){
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((points + i)->y > 0 && (points + j)->y > 0 && (points + i)->x < 0 && (points + j)->x < 0)
            {
                count ++;
            }
        }
    }
    return count;
}




int main()
{
    int n;
    printf("Enter how many point on graph: ");
    Input(&n);

    Point *points;
    printf("Enter location of points:\n");
    Input(&points, n);

    printf("All point you enter are: ");
    Output(points, n);
    endll;

    //1, điếm số thuộc đường phan giác góc phần tư thứ 3
    int countThirdQuadrant = CountThirdQuadrant(points, n);
    if (countThirdQuadrant)
        printf("Have %d point in Third Quadrant.\n\n", countThirdQuadrant);
    else 
        printf("Have no point in Third Quadrant.\n\n");

    //2, tìm diện tích hình trong tâm O nhỏ nhát chứa tất cả các diểm
    printf("the smallest circle area contain all points : %f\n\n", FindMax(points, n));

    //3, tính độ dài đường gấp khúc đi qua tất cả các điểm
    float *distain = DistainPerPoint(points, n);
    for (int i = 0; i < n -1; i++){
        printf("line %d: %f\n",i + 1, distain[i]);
    }
    endl;

    //4, nhập và bán kính RỒI, đếm và in ra màn hình các điểm nằm ngoài đường tròn tâm O bán kính R
    float r;
    printf("Enter radius: ");
    Input(&r);
    int count;
    Point *listOutSizeCircle = CountOutSizeCircle(points, n , r, &count);
    if (count){
        printf("list points out size the circle:\n");
        Output(listOutSizeCircle, count);
        endl;
    }
    else
        printf("do not have any point out side the circle.\n\n");

    //5, tìm một điểm thuộc góc phần tư thứ 2 gần gốc tọa độ nhất
    int indexMinSecondQuadrant = IndexMinSecondQuadrant(points, n);
    if (indexMinSecondQuadrant == -1)
        printf("don't have any point in second quadrant.\n\n");
    else{
        printf("Point closest O and in second quadrant: ");
        Output(*(points + indexMinSecondQuadrant));
        endll;
    }

    count = CountLineCrossX(points, n);
    if (count)
        printf("%d line cross X.\n\n", count);
    else
        printf("all point y > 0 or y < .\n\n");

    //7, đếm số đoạn thẳng thuộc góc phần tư thứ 2.
    count = CountLineInSecondQuadrant(points, n);
    if (count)
        printf("%d line in second quadrant.\n\n", count);
    else
        printf("don't have any line in second quadrant.\n\n");


    //giải phóng bộ nhớ
    free(points);
    free(distain);
    free(listOutSizeCircle);
    
    return 0;
}
