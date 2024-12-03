#include <bits/stdc++.h>
using namespace std;

class QLH
{
protected:
	string ma, ten, xuatxu;
	int loai;

public:
	QLH(string ma = "", string ten = "", string xuatxu = "", int loai = 0)
	{
		this->ma = ma;
		this->ten = ten;
		this->xuatxu = xuatxu;
		this->loai = loai;
	}

	friend istream &operator>>(istream &is, QLH &qlh)
	{
		getline(is, qlh.ma);
		getline(is, qlh.ten);
		getline(is, qlh.xuatxu);
		cin >> qlh.loai;
		return is;
	}
	friend ostream &operator<<(ostream &os, QLH qlh)
	{
		os << setw(20) << qlh.ma
		   << setw(20) << qlh.ten
		   << setw(20) << qlh.xuatxu
		   << setw(20) << qlh.loai;
		return os;
	}

	int getLoai()
	{
		return loai;
	}
};

class DIENTU : public QLH
{
private:
	int tgbh;

public:
	DIENTU (string ma = "", string ten = "", string xuatxu = "", int loai = 0) {
		this->ma = ma;
		this->ten = ten;
		this->xuatxu = xuatxu;
		this->loai = loai;
		tgbh = 0;
	}
	friend istream &operator>>(istream &is, DIENTU &dt)
	{
		is >> static_cast<QLH &>(dt) >> dt.tgbh;
		is.ignore();

		return is;
	}
	friend ostream &operator<<(ostream &os, DIENTU dt)
	{
		os << (QLH)dt << setw(20) << dt.tgbh << endl;
		return os;
	}

	int gettgbh()
	{
		return tgbh;
	}
	DIENTU operator=(DIENTU a){
		this->ma = a.ma;
		this->ten = a.ten;
		this->loai = a.loai;
		this->xuatxu = a.xuatxu;
		this->tgbh = a.tgbh;

		return *this;
	}
};

signed main()
{
	cout << "nhap n: ";
	int n;
	cin >> n;
	cin.ignore();
	DIENTU dt[n];
	cout << "nhap hang: ";
	for (int i = 0; i < n; i++)
	{
		cin >> dt[i];
	}

	vector<DIENTU> a[3];
	for (DIENTU x : dt)
	{
		a[x.getLoai() - 1].push_back(x);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "loai hang " << i + 1 << "la:\n";
		for (DIENTU x : a[i])
		{
			cout << x;
		}
		cout << endl;
	}

	cout << "hang loai 1 co thoi gian bao hanh lau nhat:\n";
	DIENTU maxx;
	for (int i = 0; i < n; i++)
	{
		if (maxx.gettgbh() < dt[i].gettgbh()){
			maxx = dt[i];
		}
	}
	cout << maxx;

	return 0;
}