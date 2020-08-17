#include <bits/stdc++.h>

using namespace std;

vector<int> count_sort(const vector<int> &numbers, int m) {
    int n = numbers.size();
    vector<int> count(m + 1);
    for (int i = 0; i < n; i++) {
        count[numbers[i]]++;
    }
    vector<int> res;
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= count[i]; j++) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    int n = 0;
    cin >> n;
    int m = 0;
    cin >> m;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    vector<int> res = count_sort(numbers, m);
    for (auto &number : res) {
        cout << number << " ";
    }
    cout << '\n';
    return 0;
}