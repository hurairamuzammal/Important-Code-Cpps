#include<iostream>
using namespace std;
void integerToRoman(int num)
{
// here I	1
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000
    string m[] = {"", "M", "MM", "MMM"};
    string c[] = {"", "C", "CC", "CCC", "CD", "D",
                   "DC", "DCC", "DCCC", "CM"};
    string x[] = {"", "X", "XX", "XXX", "XL", "L",
                   "LX", "LXX", "LXXX", "XC"};
    string i[] = {"", "I", "II", "III", "IV", "V",
                   "VI", "VII", "VIII", "IX"};
    string thousands = m[num / 1000];
    string hundereds = c[(num % 1000) / 100];
    string tens = x[(num % 100) / 10];
    string ones = i[num % 10];
    string ans = thousands + hundereds + tens + ones;
    cout << ans << endl;
}
int main()
{ 
    int num = 0;
    cout<<"Enter the number: \n";
    cin>>num;
    integerToRoman(num);
    return 0; 
}