#include <iostream>
using namespace std;
class operation
{
private:
    int x;

public:
    operation() { x = 1; };
    void operator++() // pre increment
    {
        ++x;
    }
    void operator ++(int) // post increment
    {
        x++;
    }

    void operator --() // pre decrement
    {
        --x;
    }
    void operator--(int) // post decrement
    {
        x--;
    }
    void operator!() // uniary operator called
    {
        !x;
    }
    void getResult()
    {
        cout << "Value of x is " << x << endl;
    }
};

int main()
{
    operation op1;
    op1.getResult();
    ++op1;
    op1.getResult();
    op1++;
    op1.getResult();
    op1--;
    op1.getResult();
    --op1;
    op1.getResult();
    !op1;
    op1.getResult();

    return 0;
}