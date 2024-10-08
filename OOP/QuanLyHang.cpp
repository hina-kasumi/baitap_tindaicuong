#include <bits/stdc++.h>
using namespace std;

class QLH
{
protected:
    string maHang;
    string tenHang;
    string xuatXu;
    int loaiHang;
    int soLuong;

public:
    QLH(string maHang, string tenHang, string xuatXu, int loaiHang, int soLuong)
        : maHang(maHang), tenHang(tenHang), xuatXu(xuatXu), loaiHang(loaiHang), soLuong(soLuong) {}

    QLH() : maHang(""), tenHang(""), xuatXu(""), loaiHang(0), soLuong(0) {}
    int getLoaiHang()
    {
        return loaiHang;
    }

    friend istream &operator>>(istream &is, QLH &qlh)
    {
        is >> qlh.maHang;
        is >> qlh.tenHang;
        is >> qlh.xuatXu;
        is >> qlh.loaiHang;
        is >> qlh.soLuong;
        is.ignore();
        return is;
    }

    friend ostream &operator<<(ostream &os, const QLH qlh)
    {
        os << setw(10) << qlh.maHang << '|'
           << setw(20) << qlh.tenHang << '|'
           << setw(20) << qlh.xuatXu << '|'
           << setw(10) << qlh.loaiHang << '|'
           << setw(10) << qlh.soLuong << '|';
        return os;
    }
};

class DienTu : public QLH
{
private:
    int thoiGianBaoHanh;

public:
    DienTu(string maHang, string tenHang, string xuatXu, int loaiHang, int soLuong, int thoiGianBaoHanh)
        : QLH(maHang, tenHang, xuatXu, loaiHang, soLuong), thoiGianBaoHanh(thoiGianBaoHanh) {}

    DienTu() : QLH(), thoiGianBaoHanh(0) {}
    friend istream &operator>>(istream &is, DienTu &dt)
    {
        is >> static_cast<QLH &>(dt);
        is >> dt.thoiGianBaoHanh;
        return is;
    }

    friend ostream &operator<<(ostream &os, const DienTu dt)
    {
        os << static_cast<const QLH &>(dt);
        os << dt.thoiGianBaoHanh << endl;
        return os;
    }

    int getThoiGianBaoHanh()
    {
        return thoiGianBaoHanh;
    }
};

void thongke(vector<DienTu> dt)
{
    map<int, int> res;
    for (int i = 0; i < dt.size(); i++)
    {
        res[dt[i].getLoaiHang()]++;
    }
    for (pair<int, int> p : res)
    {
        cout << p.first << " gom " << p.second << " loai hang.\n";
    }
}

void dtloai1(vector<DienTu> dt){
    int pos = -1;
    for (int i = 0; i < dt.size(); i++)
    {
        if(dt[i].getLoaiHang() == 1 && pos == -1)
            pos = i;
        if(dt[i].getLoaiHang() == 1 && dt[i].getThoiGianBaoHanh() > dt[pos].getThoiGianBaoHanh()){
            pos = i;
        }
    }
    cout << dt[pos];
}

signed main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<DienTu> dt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << dt[i];
    }

    cout << endl;
    thongke(dt);
    cout << endl;

    dtloai1(dt);


    return 0;
}