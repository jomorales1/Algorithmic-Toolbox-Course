#include <bits/stdc++.h>

using namespace std;

vector<int> change(vector<int> &denominations, int amount) {
    sort(denominations.rbegin(), denominations.rend());
    int n = denominations.size();
    vector<int> result;
    int index = 0;
    for (int i = 0; i < n; i++) {
        while(amount >= denominations[i]) {
            result.push_back(denominations[i]);
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
    vector<int> result = change(denominations, amount);
    for (const auto &coin : result) {
        cout << coin << " ";
    }
    cout << '\n';
    return 0;
}