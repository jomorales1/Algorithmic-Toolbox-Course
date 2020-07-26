#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    long long best = 0LL;
    for (long long d = 1; d <= a + b; d++) {
        if (a % d == 0 && b % d == 0) {
            best = d;
        }
    }
    return best;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << "GCD: " << gcd(a, b) << "\n";
    return 0;
}