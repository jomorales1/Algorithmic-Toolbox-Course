#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> factors(int n) {
  vector<pair<int, int>> f;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0){
      pair<int, int> factor;
      factor.first = i;
      factor.second = 1;
      n /= i;
      while (n % i == 0) {
        factor.second++;
        n /= i;
      }
      f.push_back(factor);
    }
  }
  if (n > 1) {
    f.push_back(make_pair(n, 1));
  }
  return f;
}

int gcd_fast(int a, int b) {
  if (b > a)
    swap(a, b);
  if (b == 0)
    return a;
  return gcd_fast(b, a % b);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
  return (long long) a * b / gcd_fast(a, b);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << "\n";
  /*int n;
  cin >> n;
  vector<pair<int, int>> fac = factors(n);
  for (auto x: fac) {
    cout << x.first << "^" << x.second << "\n";
  }*/
  return 0;
}
