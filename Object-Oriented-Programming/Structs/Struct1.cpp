#include<iostream>
using namespace std;
//created a basic structure
struct Student
{
    //data members
 int roll;
 string name;
 float marks;
};
int main()
{
    //created a structure instance
    Student s1;
    s1.roll=1;
    s1.name="Rahul";
    s1.marks=99.9;
    cout<<"Roll: "<<s1.roll<<endl;
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Marks: "<<s1.marks<<endl;
 return 0;
}