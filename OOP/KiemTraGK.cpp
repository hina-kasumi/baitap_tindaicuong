#include <bits/stdc++.h>
using namespace std;

class SP {
private:
    float phanThuc, phanAo;
public:
    SP (float phanThuc = 0, float phanAo = 0) {
        this->phanThuc = phanThuc;
        this->phanAo = phanAo;
    }
    friend istream &operator>> (istream &is, SP &sp){
        is >> sp.phanThuc >> sp.phanAo;
        return is;
    }

    friend ostream &operator<<(ostream &os, SP sp){
        os << sp.phanThuc << " + " << sp.phanAo << "i\n";
        return os;
    }
    SP operator=(const SP sp){
        this->phanThuc = sp.phanThuc;
        this->phanAo = sp.phanAo;
        return *this;
    }
    SP operator+(SP sp){
        return SP (phanThuc + sp.phanThuc, phanAo + sp.phanAo);
    }
};


signed main()
{
    SP s1, s2, s3;
    cout << "nhap vao 3 so phuc:\n";
    cin >> s1 >> s2 >> s3;

    SP s = s1 + s2 + s3;
    cout << "s1: " << s1
        << "s2: " << s2
        << "s3: " << s3
        << "s: " << s;

    return 0;
}