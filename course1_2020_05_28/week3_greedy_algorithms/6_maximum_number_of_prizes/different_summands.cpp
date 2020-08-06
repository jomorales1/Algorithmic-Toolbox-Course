#include <bits/stdc++.h>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if (n <= 2) {
    summands.push_back(n);
    return summands;
  }
  //write your code here
  int summand = 1;
  while (n > 0) {
    summands.push_back(summand);
    n -= summand;
    summand++;
    if ((n - summand) <= summand) {
      summands.push_back(n);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (int i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
  cout << "\n";
  return 0;
}
