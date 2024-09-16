#include <bits/stdc++.h>
using namespace std;

class MatHang
{
protected:
    int maHang;
    string tenHang, nhaSanXuat;
    int soLuong;
    float donGia;

public:
    MatHang(int maHang = 0, string tenHang = "", string nhaSanXuat = "", int soLuong = 0, float donGia = 0)
    {
        this->maHang = maHang;
        this->tenHang = tenHang;
        this->nhaSanXuat = nhaSanXuat;
        this->soLuong = soLuong;
        this->donGia = donGia;
    }

    friend istream &operator>>(istream &is, MatHang &x)
    {
        cout << "ma hang: ";
        is >> x.maHang;
        cout << "ten hang: ";
        is >> x.tenHang;
        cout << "nha san xuat: ";
        is >> x.nhaSanXuat;
        cout << "so luong: ";
        is >> x.soLuong;
        cout << "don gia: ";
        is >> x.donGia;
        return is;
    }

    friend ostream &operator<<(ostream &os, MatHang x)
    {
        os << x.maHang << '|'
            << x.tenHang << '|'
            << x.nhaSanXuat << '|'
            << x.soLuong << '|'
            << x.donGia << "|";
        return os;
    }
};

class MayTinh:public MatHang{
private:
    string loaiCPU, heDieuHanh;
    float trongLuong;
public:
    MayTinh(int maHang = 0, string tenHang = "", string nhaSanXuat = "", int soLuong = 0, float donGia = 0, string loaiCPU = "",string heDieuHanh = "window", float trongLuong = 0){
        MatHang(maHang, tenHang, nhaSanXuat, soLuong, donGia);
        this->loaiCPU = loaiCPU;
        this->heDieuHanh = heDieuHanh;
        this->trongLuong = trongLuong;
    }

    friend ostream &operator<<(ostream& os, MayTinh x){
        os << (MatHang)x << x.loaiCPU << '|' << x.heDieuHanh << '|' << x.trongLuong << '\n';
        return os;
    }
};



signed main()
{
    

    return 0;
}