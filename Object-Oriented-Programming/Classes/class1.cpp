#include <iostream>
#include <string>
using namespace std;

class CreateAndDestroy
{
public:
    CreateAndDestroy(int);
    ~CreateAndDestroy();

private:
    int objectID;
    string message;
};

void create(void)
{
    CreateAndDestroy fifth(5);
    cout << " (local automatic in create)" << endl;

    static CreateAndDestroy sixth(6);
    cout << " (local static in create)" << endl;

    CreateAndDestroy seventh(7);
    cout << " (local automatic in create)" << endl;
}

CreateAndDestroy::CreateAndDestroy(int value)
{
    objectID = value;
    cout << "Object " << objectID << " constructor" << endl;
}

CreateAndDestroy::~CreateAndDestroy()
{
    cout << "Object " << objectID << " destructor" << endl;
}

int main()
{
    cout << " (global created before main)" << endl;

    CreateAndDestroy second(2); // local object
    cout << " (local automatic in main)" << endl;

    static CreateAndDestroy third(3); // local object
    cout << " (local static in main)" << endl;

    create(); // call function to create objects

    CreateAndDestroy fourth(4); // local object
    cout << " (local automatic in main)" << endl;

    return 0;
}
