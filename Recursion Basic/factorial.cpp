#include <iostream>
using namespace std;

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: 0! and 1! are both 1
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}

int main() {
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int result = factorial(num);
        cout << "Factorial of " << num << " is " << result << endl;
    }

    return 0;
}
