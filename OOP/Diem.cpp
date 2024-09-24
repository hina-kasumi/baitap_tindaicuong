#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    float x, y;
public:
    Point(float x = 0, float y = 0){
        this->x = x;
        this->y = y;
    }

    float khoangCach(Point a){
        return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
    }

    bool operator==(Point a){
        return x == a.x && y == a.y;
    }

    Point operator*(Point a){
        return Point(x * a.x, y * a.y);
    }

    friend istream &operator>>(istream& is, Point &a){
        is >> a.x >> a.y;
        return is;
    }

    friend ostream &operator<<(ostream& os, Point a){
        os << "(" << a.x << ", " << a.y << ")";
        return os;
    }
};



signed main()
{
    Point a, b(0, 0), c(10, 99);

    cout << a << b << c << endl;

    cout << c.khoangCach(a);
    

    return 0;
}