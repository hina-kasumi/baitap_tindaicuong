#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
private:
    int tuSo, mauSo;

public:
    PhanSo(int tuSo = 0, int mauSo = 1)
    {
        if (mauSo == 0)
            throw runtime_error("mau so bang 0");
        int temp = __gcd(mauSo, tuSo);
        this->tuSo = tuSo / temp;
        this->mauSo = mauSo / temp;
    }

    PhanSo operator*(PhanSo x)
    {
        return PhanSo(
            this->tuSo * x.tuSo,
            this->mauSo * x.mauSo);
    }

    //nhập 
    friend istream &operator>>(istream &is, PhanSo &x)
    {
        char c;
        is >> x.tuSo >> c >> x.mauSo;
        if (x.mauSo == 0)
            throw runtime_error("mau so bang 0");
        return is;
    }

    //xuất
    friend ostream &operator<<(ostream &os, PhanSo x)
    {
        if (x.mauSo == 1)
            os << x.tuSo;
        else
            os << x.tuSo << '/' << x.mauSo;
        return os;
    }
};

signed main()
{
    PhanSo a(4, 6), b;
    cin >> b;

    cout << "a * b = " << a * b << endl;
    cout << a << ' ' << b << endl;

    return 0;
}