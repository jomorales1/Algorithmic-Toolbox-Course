#include <bits/stdc++.h>

using namespace std;

vector<int> mult_poly(vector<int> &a, vector<int> &b, int n) {
    int pair[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair[i][j] = a[i] * b[j];
        }
    }
    vector<int> product(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        product[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            product[i + j] += pair[i][j];
        }
    }
    return product;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> product = mult_poly(a, b, n);
    for (auto coefficient : product) {
        cout << coefficient << " ";
    }
    cout << '\n';
    return 0;
}