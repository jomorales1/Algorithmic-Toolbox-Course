#include <bits/stdc++.h>

using namespace std;

const int size = (int) 1e6 + 1;
int dp[size];

int dp_change(vector<int> &coins, int amount) {
    dp[0] = 0;
    for (int m = 1; m <= amount; m++) {
        dp[m] = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (m >= coins[i]) {
                int num_coins = dp[m - coins[i]] + 1;
                if (num_coins < dp[m]) {
                    dp[m] = num_coins;
                }
            }
        }
    }
    return dp[amount];
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int amount = 0;
    cin >> amount;
    int result = dp_change(coins, amount);
    cout << result << '\n';
    return 0;
}