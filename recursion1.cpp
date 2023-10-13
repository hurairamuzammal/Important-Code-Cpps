#include <iostream>

using namespace std;

void sort(int array[], int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot = array[end];
  int i = start - 1;

  for (int j = start; j < end; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[end]);

  sort(array, start, i);
  sort(array, i + 2, end);
}

int main() {
  int array[] = {10, 8, 2, 7, 1, 9, 6, 5, 4, 3};
  int size = sizeof(array) / sizeof(array[0]);

  sort(array, 0, size - 1);

  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  return 0;
}
