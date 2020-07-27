#include <bits/stdc++.h>

using namespace std;

int gcd_fast(int a, int b) {
  if (b > a)
    swap(a, b);
  if (b == 0)
    return a;
  return gcd_fast(b, a % b);
}

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b) << "\n";
  return 0;
}
