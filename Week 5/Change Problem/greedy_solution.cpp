#include <bits/stdc++.h>

using namespace std;

int change(vector<int> &denominations, int amount) {
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
    int n = 0;
    cin >> n;
    vector<int> denominations(n);
    for (int i = 0; i < n; i++) {
        cin >> denominations[i];
    }
    int amount = 0;
    cin >> amount;
    int result = change(denominations, amount);
    cout << result << '\n';
    return 0;
}