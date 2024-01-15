#include <iostream>
using namespace std;

class Engine
{
public:
    Engine(int power) : power(power) {
        
    }
    void start() { cout << "Engine with power " << power << " started" << endl; }

private:
    int power;
};

class Car
{
public:
    Car(string name, int enginePower) : name(name), engine(enginePower) {}
    void start()
    {
        cout << name << " starting" << endl;
        engine.start();
    }

private:
    string name;
    Engine engine;
};

int main()
{
    Car car("Ferrari", 600);
    car.start();
    return 0;
}