#include <iostream>
using namespace std;
class Matrix
{
private:
  int rows, coloums, **arr;

public:
  Matrix()
  {

    rows = coloums = 3;
    arr = new int *[rows];
    for (int i = 0; i < 3; i++)
    {
      arr[i] = new int[coloums];
    }
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        arr[i][j] = 0;
      }
    }
    cout << "I am Default Constructor " << endl;
  }
  Matrix(int r,int c)
  {
    rows=r;coloums=c;  

  
   arr = new int *[rows];
    for (int i = 0; i < 3; i++)
    {
      arr[i] = new int[coloums];
    }
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < coloums; j++)
      {
        arr[i][j] = 0;
      }
    }
    cout<<"I am overloaded constructor with Rows:"<<rows<<" and Coloums:"<<coloums<<endl;
  }
  friend ostream& operator<<(ostream& out,Matrix &m)
  {
    for (int i = 0; i < m.rows; i++)
    {
      for (int j = 0; j < m.coloums; j++)
      {
       out<<m.arr[i][j];
      }
    }
  }
  friend istream& operator>>(ifstream& in,Matrix m);

  ~Matrix(){cout<<"Default Destructor "<<endl;}
};

istream& operator>>(ifstream& in,Matrix m)
{
  for(int i;i<m.rows;i++)
  {
    for(int j;j<m.coloums;j++ )
    {
      cin>>m.arr[i][j];
    }
  }
}
int main()
{
  return 0;
}