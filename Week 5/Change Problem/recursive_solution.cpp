#include <bits/stdc++.h>

using namespace std;

int recursive_change(vector<int> &coins, int amount) {
    if (amount == 0)
        return 0;
    int min_num_coins = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        if (amount >= coins[i]) {
            int num_coins = recursive_change(coins, amount - coins[i]);
            if ((num_coins + 1) < min_num_coins)
                min_num_coins = num_coins + 1;
        }
    }
    return min_num_coins;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.rbegin(), coins.rend());
    int amount = 0;
    cin >> amount;
    int result = recursive_change(coins, amount);
    cout << result << '\n';
    return 0;
}