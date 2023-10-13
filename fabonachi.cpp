#include <iostream>
using namespace std;

void fibonacci(int n, int a = 0, int b = 1) {
    if (n == 0) {
        return;
    }
    cout << a << " ";
    fibonacci(n-1, b, a+b);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci series: ";
    fibonacci(n);
    return 0;
}