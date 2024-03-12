#include<iostream>
using namespace std;

int max_sum_subarray(int arr[], int n, int& start, int& end)
{
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum > maxSum)
            {
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }

    return maxSum;
}

int main()
{
    int n = 16;
    int arr[] = {7, -2, 14, -7, -1, -5, 4, -3, -1, -3, 4, 2, 3, 5, 14, 6};

    int start, end;
    int maxSum = max_sum_subarray(arr, n, start, end);

    cout << "The maximum sum of subarray is: " << maxSum << endl;
    cout << "The subarray starts at index " << start << " and ends at index " << end << endl;

    return 0; 
}