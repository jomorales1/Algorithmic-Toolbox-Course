#include <bits/stdc++.h>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int n = stops.size();
    int num_refills = 0;
    int current_refill = 0;
    while (current_refill < n) {
        int last_refill = current_refill;
        while (current_refill < n && stops[current_refill + 1] - stops[last_refill] <= tank) {
            current_refill++;
        }
        if (current_refill == last_refill) {
            return -1;
        }
        if (dist - stops[current_refill] > 0) {
            num_refills++;
        }
    }
    return num_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
