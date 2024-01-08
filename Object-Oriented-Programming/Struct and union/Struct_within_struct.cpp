#include<iostream>
using namespace std;
struct engine
{
    /* data members */
    int power;
    float mileage;
};
struct tyre
{
    /* data members */
    int radius;
    int width;
};
struct car
{
    /* data members */
    int price;
    string name;
    //structure within structure
    engine e;
    tyre t;
};

int main()
{
    //created a structure instance
    car c1;
    c1.price=1000000;
    c1.name="Audi";
    c1.e.power=1000;
    c1.e.mileage=20.5;
    c1.t.radius=20;
    c1.t.width=10;
    cout<<"Price: "<<c1.price<<endl;
    cout<<"Name: "<<c1.name<<endl;
    cout<<"Engine Power: "<<c1.e.power<<endl;
    cout<<"Engine Mileage: "<<c1.e.mileage<<endl;
    cout<<"Tyre Radius: "<<c1.t.radius<<endl;
    cout<<"Tyre Width: "<<c1.t.width<<endl;
 return 0;
}