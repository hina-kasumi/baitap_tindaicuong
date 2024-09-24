#include <bits/stdc++.h>
using namespace std;

class Rect
{
private:
    float width, height;

public:
    Rect(float width = 0, float height = 0)
    {
        this->width = width;
        this->height = height;
    }

    friend istream &operator>>(istream &is, Rect &rect)
    {
        is >> rect.width >> rect.height;
        rect.width = rect.width ? rect.width : 0;
        rect.height = rect.height ? rect.height : 0;
        return is;
    }

    friend ostream &operator<<(ostream &os, Rect rect)
    {
        os << "(w: " << rect.width << ", h: " << rect.height << ")";
        return os;
    }

    float S()
    {
        return width * height;
    }
};

signed main()
{
    int n;
    cin >> n;
    Rect *rects = new Rect[n];

    for (int i = 0; i < n; i++)
    {
        cin >> rects[i];
        cout << rects[i] << endl;
    }

    float res = 0;

    for (int i = 0; i < n; i++)
    {
        res = max(res, rects[i].S());
    }

    cout << res;

    return 0;
}