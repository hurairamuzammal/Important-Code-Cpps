#include<iostream>
using namespace std;
void add(int&x,int&y ,int &z)
{
    z=x+y;
    x=x/2;
    y=y/2;
    x=35;
    y=35;
}

int main()
{ 
    int x=5,y=2,z=0;
    add(x,y,z);
    cout<<"Sum is "<<z<<endl;
    cout<<x<<" "<<y<<endl;
    return 0; 
}