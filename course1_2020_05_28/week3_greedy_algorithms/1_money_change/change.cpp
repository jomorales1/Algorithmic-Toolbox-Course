#include <bits/stdc++.h>

using namespace std;

int get_change(int m) {
  //write your code here
  int n = 0;
  while (m > 0) {
    while (m >= 10) {
      m -= 10;
      n++;
      // cout << 10 << " ";
    }
    while (m >= 5) {
      m -= 5;
      n++;
      // cout << 5 << " ";
    }
    while (m >= 1) {
      m -= 1;
      n++;
      // cout << 1 << " ";
    }
  }
  // cout << "\n";
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
  return 0;
}
