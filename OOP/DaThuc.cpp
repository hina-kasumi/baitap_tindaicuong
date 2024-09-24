#include <bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    int n;
    float *arr;
public:
    DaThuc(int n = 0){
        this->n = n;
        arr = new float[n + 1];
    }


    friend istream &operator>>(istream& is, DaThuc &a){
        is >> a.n;
        a.arr = new float[a.n + 1];
        for (int i = 0; i <= a.n; i++)
            is >> a.arr[i];
        
        return is;
    }

    friend ostream &operator<<(ostream& os,const DaThuc a){
        os << a.arr[0];
        for (int i = 1; i <= a.n; i++)
            os << " + " << a.arr[i] << "x^" << i;

        return os;
    }

    DaThuc operator+(DaThuc a){
        int tmp = max(n, a.n);
        DaThuc res = (tmp);
        for (int i = 0; i <= tmp; i++)
        {
            if(i <= a.n && i <= this->n)
                res.arr[i] = this->arr[i] + a.arr[i];
            else if(i <= a.n)
                res.arr[i] = a.arr[i];
            else if(i <= this->n)
                res.arr[i] = this->arr[i];
        }
        return res;
    }

    DaThuc operator=(DaThuc a){
        this->n = a.n;
        this->arr = a.arr;
        return *this;
    }
};

signed main()
{
    DaThuc a, b;
    cin >> a >> b;
    cout << a << endl << b << endl;
    a = b;
    cout << a << endl << b << endl;
    cout << a + b;
    return 0;
}