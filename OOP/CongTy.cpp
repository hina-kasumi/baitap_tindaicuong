#include <bits/stdc++.h>
using namespace std;

class CTY {
private:
    string ten;
    int ntl;
public:
    friend istream& operator>>(istream& is, CTY& cty) {
        is.ignore();
        cout << "Nhap ten cong ty: ";
        is >> cty.ten;
        cout << "Nhap nam thanh lap: ";
        is >> cty.ntl;
        return is;
    }

    friend ostream& operator<<(ostream& os, CTY& cty) {
        os << setw(10) << cty.ten;
        os << setw(10) << cty.ntl;
        return os;
    }
};

class CTYPM:public CTY {
private:
    int soLaptrinhVien;
public:
    static void title(){
        cout << setw(10) << "Ten CTY";
        cout << setw(10) << "Nam TL";
        cout << setw(10) << "So lap trinh vien" << endl;
    }
    friend istream& operator>>(istream& is, CTYPM& cty) {
        is>> static_cast<CTY&>(cty);
        cout << "Nhap so lap trinh vien: ";
        is >> cty.soLaptrinhVien;
        return is;
    }

    friend ostream& operator<<(ostream& os, CTYPM& cty) {
        os << static_cast<CTY&>(cty);
        os << setw(10) << cty.soLaptrinhVien << endl;
        return os;
    }
};

class CTYVT:public CTY {
private:
    int so_oto;
public:
    static void title(){
        cout << setw(10) << "Ten CTY";
        cout << setw(10) << "Nam TL";
        cout << setw(10) << "So oto" << endl;
    }
    friend istream& operator>>(istream& is, CTYVT& cty) {
        is >> static_cast<CTY&>(cty);
        cout << "Nhap so oto: ";
        is >> cty.so_oto;
        return is;
    }

    friend ostream& operator<<(ostream& os, CTYVT& cty) {
        os << static_cast<CTY&>(cty);
        os << setw(10) << cty.so_oto << endl;
        return os;
    }
};


int main() {
    // freopen("input.INP", "r", stdin);
    int n, m;
    cout << "Nhap so cong ty phan mem: ";
    cin >> n;
    cout << "Nhap so cong ty van tai: ";
    cin >> m;

    vector<CTYPM> cty_pm(n);
    vector<CTYVT> cty_vt(m);

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cong ty phan mem thu " << i + 1 << endl;
        cin >> cty_pm[i];
    }

    for (int i = 0; i < m; i++) {
        cout << "Nhap thong tin cong ty van tai thu " << i + 1 << endl;
        cin >> cty_vt[i];
    }

    cout << "Danh sach cong ty phan mem:\n";
    CTYPM::title();
    for (int i = 0; i < n; i++)
    {
        cout << cty_pm[i];
    }

    cout << "Danh sach cong ty van tai:\n";
    CTYVT::title();
    for (int i = 0; i < m; i++)
    {
        cout << cty_vt[i];
    }
    


    return 0;
}