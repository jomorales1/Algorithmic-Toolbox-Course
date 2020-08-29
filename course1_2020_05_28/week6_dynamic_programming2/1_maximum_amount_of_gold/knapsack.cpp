#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
    //write your code here
    int current_weight = 0;
    for (int i = 0; i < w.size(); ++i) {
        if (current_weight + w[i] <= W) {
        current_weight += w[i];
        }
    }
    return current_weight;
}

int knapsack(vector<int> &weights, vector<int> &prizes, int W) {
    int n = weights.size();
    vector<vector<int>> value(W + 1, vector<int> (n + 1));
    for (int i = 0; i < n + 1; i++) {
        value[0][i] = 0;
    }
    for (int i = 0; i < W + 1; i++) {
        value[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            value[w][i] = value[w][i - 1];
            if (weights[i - 1] <= w) {
                int val = value[w - weights[i - 1]][i - 1] + prizes[i - 1];
                if (value[w][i] < val) {
                    value[w][i] = val;
                }
            }
        }
    }
    return value[W][n];
}

int main() {
    int n, W;
    cin >> W >> n;
    vector<int> weights(n);
    vector<int> prizes(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        prizes[i] = weights[i];
    }
    sort(weights.begin(), weights.end());
    sort(prizes.begin(), prizes.end());
    int result = knapsack(weights, prizes, W);
    cout << result << '\n';
    return 0;
}
