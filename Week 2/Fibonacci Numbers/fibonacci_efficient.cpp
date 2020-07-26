#include <bits/stdc++.h>

using namespace std;

int lines_executed(int n) {
    return 2 * n + 2;
}

long long fibonacci(int n) {
    vector<long long> f(n + 1);
    f[0] = 0LL;
    f[1] = 1LL;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    cout << "Result: " << fibonacci(n) << "\n";
    cout << "Lines executed: " << lines_executed(n) << "\n";
    return 0;
}