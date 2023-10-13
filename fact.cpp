#include<iostream>
using namespace std;
// long fact (long num )
// {
// if (num==0)
// return 1;
// else return num * fact(num-1);
// }
int sort(int arr[],int lower,int higher)
{	int max;
	if(lower==higher)
	{
	return arr[lower];
	}
	else 
	{
		max= sort(arr,lower+1,higher);
	if (arr[lower]>=max)
	{
		return arr[lower];

	}
	else 
		return max;
	}
}
int main()
{
	long x;
	int arr[5]={1,7,9,3,2};
	// cout<<"Enter the Number ";
	// cin>>x;
	// cout<<"Factorial of "<<x<<" is: "<<fact(x)<<endl;
	cout<<"Largest elemnt of array is "<<sort(arr,0,5);
	
	return 0;
}

