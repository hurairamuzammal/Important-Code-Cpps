#include<iostream>
using namespace std;
int main()
{ 
    string n1="Exception 1 ",str2="Exception 2";
    int num=5,deno=0;
    try{
        if(deno==0)
        {
            throw str2;
        }else cout<<num/deno;
    }
    catch(string &c)
    {
        cout<<c;
    }catch(...)
    {
        cout<<"Error";
    }
    return 0; 
}