#include<iostream>
using namespace std;
class Test
{
private:
   int x,y;
public:
    Test(){x=5;y=10;};
    Test(int j,int k)
    {
        x=j;
        y=k;
    }
    ~Test(){};
   void operator+(Test t2)
    {  // Test t3;
    
        x+=t2.x;
        y+=t2.y;
        // x=t2.x+t1.x,y=t2.y+t1.y
       
    }   
    void operator*(Test t2)
    {
         x*=t2.x;
        y*=t2.y;
    }
    void operator/(Test t2)
    {
         x/=t2.x;
        y/=t2.y;
    }
    void operator-(Test t2)
    {
         x-=t2.x;
        y-=t2.y;
    }
    void getResult(Test t2)
    {   
        cout<<"Values of T1 x and y are "<<x<<" "<<y<<endl;
        cout<<"Values of T2 x and y are "<<t2.x<<" "<<t2.y<<endl;
    }
};


int main()
{   Test t1(2,3),t2(2,5);
    t1.getResult(t2);
    t1+t2;
   cout<<endl<<"T1=T1+T2"<<endl;
    t1.getResult(t2);
    t1*t2;
   cout<<endl<<"T1=T1*T2"<<endl;
    t1.getResult(t2);

    t1/t2;
   cout<<endl<<"T1=T1/T2"<<endl;
    t1.getResult(t2);

   
    t1-t2;
   cout<<endl<<"T1=T1-T2"<<endl;
    t1.getResult(t2);


    return 0; 
}