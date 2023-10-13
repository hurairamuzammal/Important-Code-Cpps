#include<iostream>
using namespace std;
class CreateAndDestroy {
public:
	CreateAndDestroy(int);//Constructor
	~CreateAndDestroy();//Destructor
	
private:
	int data;
};

CreateAndDestroy::CreateAndDestroy(int value)
{
	data = value;
	cout << "Object " << data << " constructor";
}

CreateAndDestroy::~CreateAndDestroy()
{
	cout << "Object " << data << " destructor " << endl;
}
	void create(void);// prototype
	CreateAndDestroy first(1);// global object

int main()
{
	cout << "   (global created before main)" << endl;
	CreateAndDestroy second(2);        // local object
	cout << "   (local automatic in main)" << endl;

	static CreateAndDestroy third(3);  // local object
	cout << "   (local static in main)" << endl;

	create();  // call function to create objects

	CreateAndDestroy fourth(4);        // local object
	cout << "   (local automatic in main)" << endl;

	return 0;

}//Function to create object
void create(void)
{
	CreateAndDestroy fifth(5);
	cout << "  (local automatic in create)"
		<< endl;

	static CreateAndDestroy sixth(6);
	cout << "   (local static in create)"
		<< endl;

	CreateAndDestroy seventh(7);
	cout << "   (local automatic in create)"
		<< endl;
}


