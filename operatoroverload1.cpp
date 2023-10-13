#include <iostream>
using namespace std;
class Test
{
private:
    int x;

public:
    Test() { x = 1; };
    void operator++()  // pre increment
    {
        ++x;
    }

    void operator++(int)  // post increment
    {
        x++;
       
    }
    void getResult()
    {
        cout << "Value of x is " << x << endl;
    }
};

int main()
{
    Test t1, t2;
    t1.getResult();
    ++t1;
    t1.getResult();
    t1++;
    
    
    return 0;
}