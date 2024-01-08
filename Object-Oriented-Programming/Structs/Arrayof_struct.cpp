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
    l1.b[0].bookid=101;
    l1.b[0].title="C++";
    l1.b[0].price=500;
    l1.b[1].bookid=102;
    l1.b[1].title="Java";
    l1.b[1].price=600;
    l1.b[2].bookid=103;
    l1.b[2].title="Python";
    l1.b[2].price=700;
    cout<<"Library ID: "<<l1.libid<<endl;
    cout<<"Library Name: "<<l1.libname<<endl;
    cout<<"Book ID: "<<l1.b[0].bookid<<endl;
    cout<<"Book Title: "<<l1.b[0].title<<endl;
    cout<<"Book Price: "<<l1.b[0].price<<endl;
    cout<<"Book ID: "<<l1.b[1].bookid<<endl;
    cout<<"Book Title: "<<l1.b[1].title<<endl;
    cout<<"Book Price: "<<l1.b[1].price<<endl;
    cout<<"Book ID: "<<l1.b[2].bookid<<endl;
    cout<<"Book Title: "<<l1.b[2].title<<endl;
    cout<<"Book Price: "<<l1.b[2].price<<endl;
 return 0;
}