#include<iostream>
#include<vector>
using namespace std;

int max_sum_subarray(int arr[], int n, int& start, int& end)
{
    int ans = arr[0], sum = arr[0];
    start = 0;
    end = 0;
    int tempStart = 0;

    for(int i = 1; i < n; i++)
    {
        if(sum + arr[i] > arr[i])
        {
            sum += arr[i];
        }
        else
        {
            sum = arr[i];
            tempStart = i;
        }

        if(sum > ans)
        {
            ans = sum;
            start = tempStart;
            end = i;
        }
    }

    return ans;
}

int main()
{ 
    int n = 8;
    int *arr = new int[n];
    arr[0] = 7;
    arr[1] = -2;
    arr[2] = 14;
    arr[3] = -7;
    arr[4] = 4;
    arr[5] = -3;
    arr[6] = 5;
    arr[7] = 0;

    int start, end;
    int maxSum = max_sum_subarray(arr, n, start, end);

    cout << "The maximum sum of subarray is: " << maxSum << endl;
    cout << "The subarray starts at index " << start << " and ends at index " << end << endl;

    delete[] arr;
    return 0; 
}