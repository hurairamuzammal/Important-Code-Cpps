#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
     
    string st="Not enter";
    int str;
    cout<<"Enter the string =";
    try
    {
         cin>>str;
         if(cin.fail())
         {
            throw st;
         }
    }
    catch(string &s)
    {
        cout<<s;
    }

    return 0;
}
