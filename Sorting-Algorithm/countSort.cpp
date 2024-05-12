#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max + 1, 0), output(arr.size());
    for (int number : arr) {
        count[number]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> data = {4, 2, 2, 8, 3, 3, 1};
    countSort(data);
    for (int num : data) {
        cout << num << " ";
    }
    return 0;
}
