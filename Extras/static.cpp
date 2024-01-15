#include <iostream>
using namespace std;

class MyClass {
public:
    static int x;
    static void printX() {
        cout << x <<endl;
    }
};

int MyClass::x = 1;

int main() {
  MyClass c1;
  c1.printX();
    return 0;
}