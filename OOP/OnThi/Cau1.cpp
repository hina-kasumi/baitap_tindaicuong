#include <bits/stdc++.h>
using namespace std;

class PS {
private:
    int tu, mau;
public:
	PS (int tu = 0, int mau = 1) {
		if(mau == 0){
			cout << "mau khong the bang 0";
			return;
		}
		int gcd = __gcd(abs(tu), abs(mau));
		tu /= gcd;
		mau /= gcd;
		if (mau < 0){
			mau *= -1;
			tu *= -1;
		}
		this->tu = tu;
		this->mau = mau;
	}
	
	friend istream &operator>>(istream &is, PS &ps){
		is >> ps.tu >> ps.mau;
		if(ps.mau == 0){
			cout << "mau khong the bang 0\n";
			return is;
		}
		int gcd = __gcd(abs(ps.tu), abs(ps.mau));
		ps.tu /= gcd;
		ps.mau /= gcd;
		if (ps.mau < 0){
			ps.mau *= -1;
			ps.tu *= -1;
		}
		return is;
	}
	friend ostream &operator<<(ostream &os, PS ps){
		if(ps.mau == 1)
			os << ps.tu;
		else
			os << ps.tu << "/" << ps.mau;
		return os;
	}
	PS operator+(PS p2){
		return PS(tu * p2.mau + p2.tu * mau, mau * p2.mau);
	}
};

signed main()
{
    PS a, b;
	cin >> a >> b;
	PS c = a + b;
	cout << a << " " << b << endl << a + b;

    return 0;
}