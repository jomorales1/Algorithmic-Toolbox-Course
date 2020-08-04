#include <bits/stdc++.h>

using namespace std;

bool comp_items(pair<int, double> a, pair<int, double> b) {
  return a.second > b.second ? true : false;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<pair<int, double>> unit_cost(n);
  for (int i = 0; i < n; i++) {
    unit_cost[i] = make_pair(i, (double) values[i] / weights[i]);
  }
  sort(unit_cost.begin(), unit_cost.end(), comp_items);
  int index;
  for (int i = 0; i < n; i++) {
    index = unit_cost[i].first;
    if (capacity == 0)
      return value;
    int a = min(weights[index], capacity);
    value += (double) a * values[index] / weights[index];
    weights[index] -= a;
    capacity -= a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
