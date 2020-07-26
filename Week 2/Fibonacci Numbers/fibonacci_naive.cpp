#include <bits/stdc++.h>

using namespace std;

int lines_executed(int n) {
    if (n <= 1)
        return 2;
    return 3 + lines_executed(n - 1) + lines_executed(n - 2);
}

int fibo_recurs(int n) {
    if (n <= 1)
        return n;
    return fibo_recurs(n - 1) + fibo_recurs(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << "Result: " << fibo_recurs(n) << "\n";
    cout << "Lines executed: " << lines_executed(n) << "\n";
    return 0;
}