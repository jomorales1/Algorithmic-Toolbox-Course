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
    vector<int> coins = {1, 3, 4};
    int amount = 0;
    cin >> amount;
    int result = dp_change(coins, amount);
    cout << result << '\n';
    return 0;
}