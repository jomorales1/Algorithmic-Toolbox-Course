#include <bits/stdc++.h>

using namespace std;

const int max_size = 14 + 1;
int m[max_size][max_size];
int M[max_size][max_size];

int minimum_five (int a, int b, int c, int d, int e) {
    if (a < b && a < c && a < d && a < e) {
        return a;
    }
    if (b < a && b < c && b < d && b < e) {
        return b;
    }
    if (c < a && c < b && c < d && c < e) {
        return c;
    }
    if (d < a && d < b && d < c && d < e) {
        return d;
    }
    return e;
}

int maximum_five (int a, int b, int c, int d, int e) {
    if (a > b && a > c && a > d && a > e) {
        return a;
    }
    if (b > a && b > c && b > d && b > e) {
        return b;
    }
    if (c > a && c > b && c > d && c > e) {
        return c;
    }
    if (d > a && d > b && d > c && d > e) {
        return d;
    }
    return e;
}

pair<int, int> min_and_max(int i, int j, vector<char> &operations) {
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for (int k = i; k <= j - 1; k++) {
        int a, b, c, d;
        if (operations[k] == '+') {
            a = M[i][k] + M[k + 1][j];
            b = M[i][k] + m[k + 1][j];
            c = m[i][k] + M[k + 1][j];
            d = m[i][k] + m[k + 1][j];
        } else if (operations[k] == '-') {
            a = M[i][k] - M[k + 1][j];
            b = M[i][k] - m[k + 1][j];
            c = m[i][k] - M[k + 1][j];
            d = m[i][k] - m[k + 1][j];
        } else {
            a = M[i][k] * M[k + 1][j];
            b = M[i][k] * m[k + 1][j];
            c = m[i][k] * M[k + 1][j];
            d = m[i][k] * m[k + 1][j];
        }
        minimum = minimum_five(minimum, a, b, c, d);
        maximum = maximum_five(maximum, a, b, c, d);
    }
    return {minimum, maximum};
}

int parentheses(vector<int> &numbers, vector<char> &operations) {
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        m[i][i] = numbers[i];
        M[i][i] = numbers[i];
    }
    for (int s = 1; s <= n - 1; s++) {
        for (int i = 0; i < n - s; i++) {
            int j = i + s;
            pair<int, int> r = min_and_max(i, j, operations);
            m[i][j] = r.first;
            M[i][j] = r.second;
        }
    }
    return M[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    vector<int> numbers;
    vector<char> operations;
    int number;
    for (int i = 0; i < s.length(); i += 2) {
        number = s[i] - '0';
        numbers.push_back(number);
    }
    for (int i = 1; i < s.length() - 1; i += 2) {
        operations.push_back(s[i]);
    }
    int result = parentheses(numbers, operations);
    cout << result << '\n';
    return 0;
}