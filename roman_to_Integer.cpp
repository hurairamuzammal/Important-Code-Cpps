#include <iostream>
#include <string>
#include <cstring>
using namespace std;
enum RomanNumeral
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};
class Solution
{
public:
    int romanToInt(string s)
    {
        if (s.length() == 0)
            return 0;

        else
        {
            int sum = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'I')
                {
                    if (s[i + 1] == 'V' || s[i + 1] == 'X')
                    {
                        sum -= I;
                    }
                    else
                    {
                        sum += I;
                    }
                }
                else if (s[i] == 'V')
                {
                    sum += V;
                }
                else if (s[i] == 'X')
                {
                    if (s[i + 1] == 'L' || s[i + 1] == 'C')
                    {
                        sum -= X;
                    }
                    else
                    {
                        sum += X;
                    }
                }
                else if (s[i] == 'L')
                {
                    sum += L;
                }
                else if (s[i] == 'C')
                {
                    if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    {
                        sum -= C;
                    }
                    else
                    {
                        sum += C;
                    }
                }
                else if (s[i] == 'D')
                {
                    sum += D;
                }
                else if (s[i] == 'M')
                {
                    sum += M;
                }
            }
            return sum;
        }
    }
};
int main()
{
    string s;
    cout << "Enter the Roman numeral: ";
    cin >> s;
    Solution sol;
    // here I             1
    // V             5
    // X             10
    // L             50
    // C             100
    // D             500
    // M             1000
    cout << "The integer value of the Roman numeral " << s << " is: " << sol.romanToInt(s) << endl;
    return 0;
}