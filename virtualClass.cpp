#include<iostream>
using namespace std;
class Shape
{
private:
    int x, y;
public:
    Shape() {}
    Shape(int j, int k) : x(j), y(k) {}
    virtual void draw() =0;
    virtual void check()=0;
    ~Shape() {}
};
class circle : public Shape
{
public:
    circle() {}
    circle(int j, int k) : Shape(j, k) {}
    void draw()
    {
        cout << "Draw of Circle is called " << endl;
    }
   void  check(){cout<<"This is check "<<endl;}
};

int main()
{
    //Shape c1;
    Shape *ptr;
    circle c1(2, 3);
    ptr = &c1;
    ptr->draw();
    return 0;
}