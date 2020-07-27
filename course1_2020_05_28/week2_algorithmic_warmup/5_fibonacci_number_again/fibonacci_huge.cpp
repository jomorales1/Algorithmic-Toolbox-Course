#include <bits/stdc++.h>

using namespace std;

int fibonacci(long long n, long long m) {
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % m;
    }
    return f[n];
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    /*long long f[n + 1];
    f[0] = 0;
    f[1] = 1;
    cout << f[0] << " " << f[1] << " ";
    for (int i = 2; i <= n; i++){
        f[i] = (f[i - 1] + f[i - 2]) % m;
        cout << f[i] << " ";
    }*/
    if (n <= 1)
        return n;

    int p = 0;
    vector<int> period;
    period.push_back(0);
    period.push_back(1);
    for (int i = 2; i < m * m; i++) {
        if (fibonacci(i, m) == 0 && fibonacci(i + 1, m) == 1){
            p = i;
            break;
        }
        period.push_back(fibonacci(i, m));
    }
    long long pos = n % p;
    return period[pos];
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_fast(n, m) << '\n';
    /*for (int i = 1; i < 4; i++) {
        get_fibonacci_huge_fast(50, i + 1);
    }*/
    return 0;
}
