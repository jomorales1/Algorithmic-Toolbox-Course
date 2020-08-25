#include <bits/stdc++.h>

using namespace std;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

pair<int, int> minimum(const vector<int> &numbers) {
    int m = INT_MAX;
    int index = -1;
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        if (numbers[i] < m && numbers[i] != -1) {
            index = i; m = numbers[i];
        }
    }
    return {index, m};
}

vector<int> sequence(int n) {
    vector<int> numbers;
    vector<pair<int, int>> dp2(n + 1);
    dp2[0] = {-1, -1};
    dp2[1] = {-1, 0};
    if (n == 2) {
        dp2[2] = {1, 1};
    }
    if (n >= 3) {
        dp2[3] = {1, 1};
    }
    for (int i = 4; i <= n; i++) {
        vector<int> results = {-1, -1, -1};
        results[0] = (dp2[i - 1].second + 1);
        if (i % 2 == 0) {
            results[1] = (dp2[i / 2].second + 1);
        }
        if (i % 3 == 0) {
            results[2] = (dp2[i / 3].second + 1);
        }
        pair<int, int> m = minimum(results);
        dp2[i] = m;
    }
    int index = n;
    numbers.push_back(n);
    while(index > 1) {
        if (dp2[index].first == 0) {
            numbers.push_back(index - 1);
            index = index - 1;
        } else if (dp2[index].first == 1) {
            numbers.push_back(index / 2);
            index = index / 2;
        } else if (dp2[index].first == 2){
            numbers.push_back(index / 3);
            index = index / 3;
        } else {
            break;
        }
    }
    reverse(numbers.begin(), numbers.end());
    return numbers;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = sequence(n);
    cout << result.size() - 1 << '\n';
    for (const auto &number : result) {
        cout << number << ' ';
    }
    cout << '\n';
    return 0;
}
