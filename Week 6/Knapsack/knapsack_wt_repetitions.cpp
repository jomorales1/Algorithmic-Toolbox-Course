#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int knapsack(vector<int> &weights, vector<int> &prizes, int W) {
    int n = weights.size();
    int value[W + 1][n + 1];
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
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= n; j++) {
            cout << value[i][j] << '\t';
        }
        cout << '\n';
    }
    return value[W][n];
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<pair<int, int>> objects(n);
    for (int i = 0; i < n; i++) {
        cin >> objects[i].first;
        cin >> objects[i].second;
    }
    sort(objects.begin(), objects.end(), compare);
    vector<int> weights(n);
    vector<int> prizes(n);
    for (int i = 0; i < n; i++) {
        weights[i] = objects[i].first;
        prizes[i] = objects[i].second;
    }
    int result = knapsack(weights, prizes, W);
    cout << result << '\n';
    return 0;
}