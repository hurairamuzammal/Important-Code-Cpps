#include<iostream>
using namespace std;
class Student {
protected:
	int age;
public:
Student(int a)
{
    age=a;
}
Student()
{
	
}
	int getAge() 
    {
		return age;
	}
};

class MSStudent: public  virtual Student{
};

class PhDStudent: public virtual  Student {
};   
class MSPhDStudent:public MSStudent,public PhDStudent {
public:
	MSPhDStudent(int a,int b) 
    {
		MSStudent::age = b;
		PhDStudent::age = a;
	}
};
int main() {
	MSPhDStudent obj1(13,13);
	cout << obj1.MSStudent::getAge();
	cout << obj1.PhDStudent::getAge();
    return 0;
}
// There are multiple copies of data member age



