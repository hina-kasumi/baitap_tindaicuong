#include <bits/stdc++.h>
using namespace std;

class Dummy{
public:
    static int n;
    Dummy(){n++;};
    ~Dummy(){n--;};
    static void print(){cout << "cout  = " << n << endl;}
};
int Dummy::n = 0;

signed main()
{
    Dummy::print();
    Dummy a;
    a.print();
    Dummy::print();
    Dummy b = a;
    Dummy::print();

    
    return 0;
}