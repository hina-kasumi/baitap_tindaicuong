#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    float thuc, ao;
public:
    Complex(float thuc, float ao = 0){
        this->thuc = thuc;
        this->ao = ao;
    }

    friend ostream &operator<<(ostream &os, Complex cp){
        if(!cp.ao)
            cout << cp.thuc;
        else
            cout << cp.thuc << " + " << cp.ao << "i";
        return os;
    }

    Complex operator+(Complex a){
        return Complex(this->thuc + a.thuc,
            this->ao + a.ao
        );
    }
};


signed main()
{
    Complex a(10, 8), b(8);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a + b: " << a + b << endl;

    return 0;
}