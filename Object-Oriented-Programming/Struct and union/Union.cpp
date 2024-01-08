#include<iostream>
using namespace std;
union car
{
    /* data members */
    int price;
    string name;
};
int main()
{
    car c1;
    c1.price=1000000;
    c1.name="Audi";
    cout<<"Price: "<<c1.price<<endl;
    cout<<"Name: "<<c1.name<<endl;
 return 0;
}