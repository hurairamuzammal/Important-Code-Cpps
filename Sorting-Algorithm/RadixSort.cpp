// radix sort raw
#include <iostream>
#include <queue>
using namespace std;
int maximuim(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void radixSort(int arr[], int max,int size)
{
    queue<int> q1[10];
    int newArr[10];
    int digit = 0;
    int value = 10;
    int numberofDigits = 0;
    while (max > 0)
    {
        numberofDigits++;
        max /= 10;
    }

    for (int k = 0; k < numberofDigits; k++)
    {
        for (int i = 0; i < size; i++)
        {
            digit = arr[i] % value;
            if (k == 0)
            {
                digit = digit / 1;
            }
            else if (k == 1)
            {
                digit = digit / 10;
            }
            else if (k == 2)
            {
                digit = digit / 100;
            }
            q1[digit].push(arr[i]);
        }
        // return queue back to array

        int j = 0;
        for (int i = 0; i < size; i++)
        {
            while (!(q1[i].empty()))
            {
                newArr[j] = q1[i].front();
                q1[i].pop();
                j++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            arr[i] = newArr[i];
        }
        value *= 10;
    }

    cout << "Array After sorting is: ";
    for (int i = 0; i < size; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size=10;
    int *array;
    array = new int[size];
    array[0] = 5;
    array[1] = 3;
    array[2] = 27;
    array[3] = 804;
    array[4] = 704;
    array[5] = 42;
    array[6] = 38;
    array[7] = 600;
    array[8] = 580;
    array[9] = 9;
    
    // int arr[] = {5, 3, 27, 804, 704, 42, 38, 600, 580, 9};
    int max = maximuim(array);

    radixSort(array, max,size);

    system("pause");
}