#include<iostream>
#include<string>
using namespace std;

union car
{
    int price;
    int cylinder;
    
    // in union you cannot store differnt data types
    // also you cannot store string in union
    // string name;
};

int main()
{
    car c1;
    c1.price = 1000000;
    c1.cylinder = 4;
    cout << "Price: " << c1.price << endl;
    cout << "Name: " << c1.cylinder << endl;
    
    return 0;
}
