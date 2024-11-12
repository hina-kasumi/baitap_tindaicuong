#include <bits/stdc++.h>
using namespace std;

class mon_hoc {
    string maMon, tenMon;
    int soTin;
public:
    mon_hoc (){
        maMon = "";
        tenMon = "";
        soTin = 0;
    }

    friend istream &operator >> (istream &is, mon_hoc &a){
        cout << "Nhap ma mon: ";
        is >> a.maMon;
        cout << "Nhap ten mon: ";
        is >> a.tenMon;
        cout << "Nhap so tin chi: ";
        is >> a.soTin;
        return is;
    }

    friend ostream &operator << (ostream &os, mon_hoc &a){
        os << setw(20) << a.maMon << setw(20) << a.tenMon << setw(20) << a.soTin << endl;
        return os;
    }
    void setMaMon(string maMon){
        this->maMon = maMon;
    }
    bool operator == (mon_hoc &a){
        return maMon == a.maMon;
    }
    string getMaMon(){
        return maMon;
    }
};


class DKHP {
    string maSV, tenSV;
    int soMon;
    mon_hoc *mon;

public:
    DKHP(){
        maSV = "";
        tenSV = "";
        soMon = 0;
        mon = nullptr;
    }

    friend istream &operator >> (istream &is, DKHP &a){
        cout << "Nhap ma sinh vien: ";
        is >> a.maSV;
        cout << "Nhap ten sinh vien: ";
        is >> a.tenSV;
        cout << "nhap so mon hoc: ";
        is >> a.soMon;
        is.ignore();
        a.mon = new mon_hoc[a.soMon];
        for (int i = 0; i < a.soMon; i++){
            cout << "Nhap mon hoc thu " << i + 1 << ": " << endl;
            string maMon;
            is >> maMon;
            a.mon[i].setMaMon(maMon);

        }
        return is;
    }

    friend ostream &operator << (ostream &os, DKHP &a){
        os << setw(20) << a.maSV << setw(20) << a.tenSV << endl;
        for (int i = 0; i < a.soMon; i++){
            os << a.mon[i] << endl;
        }
        return os;
    }
    string getMaMon(){
        return mon->getMaMon();
    }
};

signed main()
{
    int m;
    cout << "nhap so mon hoc: ";
    cin >> m;
    mon_hoc *a = new mon_hoc[m];
    for (int i = 0; i < m; i++){
        cout << "Nhap mon hoc thu " << i + 1 << ": " << endl;
        cin >> a[i];
    }
    int n;
    cout << "nhap so sinh vien: ";
    cin >> n;
    DKHP *b = new DKHP[n];
    for (int i = 0; i < n; i++){
        cout << "Nhap sinh vien thu " << i + 1 << ": " << endl;
        cin >> b[i];
    }

    return 0;
}