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

int greedy_change(vector<int> &denominations, int amount) {
    sort(denominations.rbegin(), denominations.rend());
    int n = denominations.size();
    int result = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        while(amount >= denominations[i]) {
            result++;
            amount -= denominations[i];
        }
        if (amount == 0)
            break;
    }
    return result;
}

int main() {
    vector<int> coins = {1, 8, 20};
    for (int i = 0; i < 1000; i++) {
        int res1 = greedy_change(coins, i);
        int res2 = dp_change(coins, i);
        if (res1 != res2) {
            cout << "Wrong answer\n";
            cout << "Money: " << i << '\n';
            cout << "Greedy: " << res1 << '\n';
            cout << "Correct answer: " << res2 << '\n';
            break;
        } else {
            cout << "OK\n";
        }
    }
    return 0;
}