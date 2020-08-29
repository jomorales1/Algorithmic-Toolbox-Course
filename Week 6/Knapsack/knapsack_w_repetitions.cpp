#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &weights, vector<int> &prices, int W) {
    int n = weights.size();
    vector<int> value(W + 1);
    value[0] = 0;
    for (int w = 1; w <= W; w++) {
        value[w] = 0;
        for (int i = 0; i < n; i++) {
            if (weights[i] <= w) {
                int val = value[w - weights[i]] + prices[i];
                if (val > value[w]) {
                    value[w] = val;
                }
            }
        }
    }
    return value[W];
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        cin >> prices[i];
    }
    int result = knapsack(weights, prices, W);
    cout << result << '\n';
    return  0;
}