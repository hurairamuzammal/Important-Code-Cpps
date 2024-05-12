#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        float temp = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > temp) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = temp;
    }
}

void bucketSort(float arr[], int n) {
    int numBuckets = 10;
    vector<vector<float>> buckets(numBuckets);

    for (int i = 0; i < n; i++) {
        int bi = numBuckets * arr[i];
        buckets[bi].push_back(arr[i]);
    }

    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float data[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(data) / sizeof(data[0]);
    bucketSort(data, n);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    return 0;
}
