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

int fibonacci_sum_fast(long long n) {
    if (n <= 0)
        return 0;
    if (n <= 1)
        return n;
    return (get_fibonacci_huge_fast(n + 2, 10) - 1 + 10) % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    return (fibonacci_sum_fast(to) - fibonacci_sum_fast(from - 1) + 10) % 10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    return 0;
}
