#include <iostream>
#include <climits>
using namespace std;

int Max_Subarray_Sum(int arr[], int n)
{
    if(n == 1)
        return arr[0];

    int m = n/2;
    int left_MSS = Max_Subarray_Sum(arr,m);
    int right_MSS = Max_Subarray_Sum(arr+m,n-m);
    int leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
    for(int i=m;i < n; i++)
    {
        sum += arr[i];
        rightsum = max(rightsum,sum);
    }

    sum = 0;
    for(int i= (m-1);i >= 0; i--)
    {
        sum += arr[i];
        leftsum = max(leftsum,sum);
    }

    int ans = max(left_MSS,right_MSS);
    return max(ans,leftsum+rightsum);
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = Max_Subarray_Sum(arr, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}