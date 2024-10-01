#include<bits/stdc++.h>
using namespace std;

class Nguoi {
protected:
    string hoTen;
    string maSo;
    float chieuCao;
    float canNang;
    int namSinh;
    string gioiTinh;

public:
    // Constructor
    Nguoi(string ht, string ms, float cc, float cn, int ns, string gt)
        : hoTen(ht), maSo(ms), chieuCao(cc), canNang(cn), namSinh(ns), gioiTinh(gt) {}

    // Default Constructor
    Nguoi() : hoTen(""), maSo(""), chieuCao(0), canNang(0), namSinh(0), gioiTinh("") {}

    // Friend functions for input and output
    friend istream& operator>>(istream& is, Nguoi& nguoi);
    friend ostream& operator<<(ostream& os, const Nguoi& nguoi);
};

istream& operator>>(istream& is, Nguoi& nguoi) {
    cout << "Nhap ho ten: ";
    getline(is, nguoi.hoTen);
    cout << "Nhap ma so: ";
    getline(is, nguoi.maSo);
    cout << "Nhap chieu cao: ";
    is >> nguoi.chieuCao;
    cout << "Nhap can nang: ";
    is >> nguoi.canNang;
    cout << "Nhap nam sinh: ";
    is >> nguoi.namSinh;
    is.ignore(); // Ignore the newline character left in the buffer
    cout << "Nhap gioi tinh: ";
    getline(is, nguoi.gioiTinh);
    return is;
}

ostream& operator<<(ostream& os, const Nguoi& nguoi) {
    os << "Ho ten: " << nguoi.hoTen << endl;
    os << "Ma so: " << nguoi.maSo << endl;
    os << "Chieu cao: " << nguoi.chieuCao << endl;
    os << "Can nang: " << nguoi.canNang << endl;
    os << "Nam sinh: " << nguoi.namSinh << endl;
    os << "Gioi tinh: " << nguoi.gioiTinh << endl;
    return os;
}

class SinhVien : public Nguoi {
private:
    int soGioHoc;
    int soLanDatDiemA;

public:
    // Constructor
    SinhVien(string ht, string ms, float cc, float cn, int ns, string gt, int sgh, int slda)
        : Nguoi(ht, ms, cc, cn, ns, gt), soGioHoc(sgh), soLanDatDiemA(slda) {}

    // Default Constructor
    SinhVien() : Nguoi(), soGioHoc(0), soLanDatDiemA(0) {}

    // Friend functions for input and output
    friend istream& operator>>(istream& is, SinhVien& sv);
    friend ostream& operator<<(ostream& os, const SinhVien& sv);
    int getSoGioHoc() {
        return soGioHoc;
    }

    float getChieuCao(){
        return chieuCao;
    }

    int getTuoi(){
        return 2024 - namSinh;
    }
};

istream& operator>>(istream& is, SinhVien& sv) {
    is >> static_cast<Nguoi&>(sv); // Input base class part
    cout << "Nhap so gio hoc: ";
    is >> sv.soGioHoc;
    cout << "Nhap so lan dat diem A: ";
    is >> sv.soLanDatDiemA;
    return is;
}

ostream& operator<<(ostream& os, const SinhVien& sv) {
    os << static_cast<const Nguoi&>(sv); // Output base class part
    os << "So gio hoc: " << sv.soGioHoc << endl;
    os << "So lan dat diem A: " << sv.soLanDatDiemA << endl;
    return os;
}

int cmp(SinhVien s1, SinhVien s2){
    return s1.getSoGioHoc() > s2.getSoGioHoc();
}

vector<SinhVien> sinhVienCao150(vector<SinhVien> sv){
    vector<SinhVien> res;
    float nhotuoi = INT_MAX;
    for (int i = 0; i < sv.size(); i++)
    {
        if(sv[i].getChieuCao() > 150){
            res.push_back(sv[i]);
            nhotuoi = min(nhotuoi, sv[i].getChieuCao());
        }
    }
    
    vector<SinhVien> index;
    for(SinhVien s : res){
        if(s.getChieuCao() == nhotuoi){
            index.push_back(s);
        }
    }

    return index;
}

int main() {
    SinhVien sv;
    cin >> sv;
    cout << "\nThong tin sinh vien:\n";
    cout << sv;
    

    return 0;
}