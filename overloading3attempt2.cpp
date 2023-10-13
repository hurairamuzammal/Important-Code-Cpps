#include <iostream>
using namespace std;
class Test
{
private:
    int x, y;

public:
    Test() {}
    Test(int j, int k) : x(2), y(3)
    {
        x = j;
        y = k;
    }
    Test operator+(Test &t2)
    {
        return Test(x + t2.x, y + t2.y);
    }
    Test operator-(Test &t2)
    {
        return Test(x - t2.x, y - t2.y);
    }
    Test operator*(Test &t2)
    {
        return Test(x * t2.x, y * t2.y);
    }
    Test operator/(Test &t2)
    {
        return Test(x / t2.x, y / t2.y);
    }
    void getResult(Test t2)
    {
        cout << "Values of T1 x and y are " << x << " " << y << endl;
        cout << "Values of T2 x and y are " << t2.x << " " << t2.y << endl;
    }
    void answer()
    {
     cout <<endl<< "Values of T3 x and y are " << this->x << " " << this->y << endl;
    
    }
    ~Test() {}
};

int main()
{
    Test t1(10,12), t2(5,6),t3;
    t1.getResult(t2);
    t3 = t1 + t2;
    cout<<"T3=T1+t2";
    t3.answer();

    t3 = t1 - t2;
    cout<<endl<<"T3=T1-t2";
    t3.answer();

    t3 = t1 * t2;
    cout<<endl<<"T3=T1*t2";
    t3.answer();

    t3 = t1 / t2;
    cout<<endl<<"T3=T1/t2";
    t3.answer();

    return 0;
}