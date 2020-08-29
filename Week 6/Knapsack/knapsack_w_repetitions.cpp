#include <bits/stdc++.h>

using namespace std;

const int s = (int) 1e3;
int dp[s + 1];

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

int recursive_knapsack(vector<int> &weights, vector<int> &prizes, int w) {
    if (dp[w] != -1)
        return dp[w];
    dp[w] = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] <= w) {
            int val = recursive_knapsack(weights, prizes, w - weights[i]) + prizes[i];
            if (val > dp[w]) {
                dp[w] = val;
            }
        }
    }
    return dp[w];
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);
    vector<int> prizes(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        cin >> prizes[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= W; i++) {
        dp[i] = -1;
    }
    int result = knapsack(weights, prizes, W);
    int result2 = recursive_knapsack(weights, prizes, W);
    cout << result << '\n';
    cout << result2 << '\n';
    return  0;
}