#include <bits/stdc++.h>

using namespace std;

int min_refills(const vector<int>& x, int n, int L) {
    int num_refills = 0;
    int current_refill = 0;
    while (current_refill <= n) {
        int last_refill = current_refill;
        while (current_refill <= n && (x[current_refill + 1] - x[last_refill] <= L)) {
            current_refill++;
        }
        if (current_refill == last_refill)
            return -1;
        if (current_refill <= n)
            num_refills++;
    }
    return num_refills;
}

int main() {
    int n, L;
    cin >> n >> L;
    vector<int> stations(n);
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }
    int res = min_refills(stations, n - 1, L);
    cout << (res == -1 ? "IMPOSSIBLE" : to_string(res)) << "\n";
    return 0;
}