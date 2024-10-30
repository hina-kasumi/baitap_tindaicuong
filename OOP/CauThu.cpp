#include <bits/stdc++.h>

using namespace std;

class Nguoi {
private:
    string hoTen;
    int tuoi;

public:
    friend istream& operator>>(istream& is, Nguoi& nguoi) {
        cout << "Nhap ho ten: ";
        getline(is, nguoi.hoTen);
        cout << "Nhap tuoi: ";
        is >> nguoi.tuoi;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const Nguoi& nguoi) {
        os << "Ho ten: " << nguoi.hoTen << endl;
        os << "Tuoi: " << nguoi.tuoi << endl;
        return os;
    }
};

class CauThu : public Nguoi {
private:
    int sbt;
    int sptd;

public:
    friend istream& operator>>(istream& is, CauThu& cauThu) {
        is >> static_cast<Nguoi&>(cauThu);
        cout << "Nhap so ban thang: ";
        is >> cauThu.sbt;
        cout << "Nhap so phut thi dau: ";
        is >> cauThu.sptd;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const CauThu& cauThu) {
        os << static_cast<const Nguoi&>(cauThu);
        os << "So ban thang: " << cauThu.sbt << endl;
        os << "So phut thi dau: " << cauThu.sptd << endl;
        return os;
    }
};

int main() {
    
    return 0;
}