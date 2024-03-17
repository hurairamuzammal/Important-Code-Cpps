#include <iostream>
using namespace std;
//simple recursion
void toh(int n, char from, char to, char aux) {
  if (n == 1) {
    cout << "MOVE DISK FROM TOWER " << from << " TO TOWER " << to << endl;
    return;
  }

  toh(n - 1, from, aux, to);
  cout << "MOVE DISK FROM TOWER " << from << " TO TOWER " << to << endl;
  toh(n - 1, aux, to, from);
}
int main() {
  int n;
  cin >> n;

  char from, to, aux;
  cout << "From: ";
  cin >> from;
  cout << "To: ";
  cin >> to;
  cout << "Aux: ";
  
  cin >> aux;


  while (n > 0) {
    toh(n, from, to, aux);
    n--;
  }

  return 0;
}