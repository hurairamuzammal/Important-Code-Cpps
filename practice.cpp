#include<iostream>
using namespace std;
class Test
{
private:
    int x,y,z;
   void  sumofnumbers()
    {
        z=x+y;
       
    }
public:
    // Test(){};
    Test(int j,int k):z(0)
    {
        x=j;
        y=k;
  
    cout<<x<<" "<<y<<" "<<z<<endl;
    }
  void  indirectSum()
    { 
    sumofnumbers();
        cout<<"The sum of two numbers is "<<z;
    }
    ~Test(){};
};


int main()
{ 
    Test t1(2,3);
    t1.indirectSum();
    t1.indirectSum();
    return 0; 
}