#include<iostream>
using namespace std;
struct book
{
    /* data members */
    int bookid;
    string title;
    float price;
};
struct library
{
    /* data members */
    int libid;
    string libname;
    //array of structure
    book b[3];
};
int main()
{
    //created a structure instance
    library l1;
    l1.libid=1;
    l1.libname="Central Library";
 //use loop to enter data in array of structure
    for(int i=0;i<3;i++)
    {
        cout<<"Enter Book ID: ";
        cin>>l1.b[i].bookid;
        cout<<"Enter Book Title: ";
        cin>>l1.b[i].title;
        cout<<"Enter Book Price: ";
        cin>>l1.b[i].price;
    }
//use loop to display data in array of structure
    for(int i=0;i<3;i++)
    {
        cout<<"Book ID: "<<l1.b[i].bookid<<endl;
        cout<<"Book Title: "<<l1.b[i].title<<endl;
        cout<<"Book Price: "<<l1.b[i].price<<endl;
    }
 return 0;
}