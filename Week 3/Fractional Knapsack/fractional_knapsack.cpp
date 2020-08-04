#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double, double> a, pair<double, double> b) {
    double uc_a = a.first / a.second;
    double uc_b = b.first / b.second;
    return uc_a - uc_b > 0.0 ? true : false;
}

void knapsack(vector<pair<double, double>>& items, double W) {
    double V = 0.0;
    vector<int> A(items.size());
    for (int i = 0; i < items.size(); i++) {
        if (W == 0.0) {
            break;
        }
        double a = min(items[i].second, W);
        V += a * items[i].first / items[i].second;
        items[i].second -= a;
        A[i] += a;
        W -= a;
    }
    cout << "Total value: " << V << "\n";
    for (auto el: A) {
        cout << el << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    double v, w, W;
    cin >> n >> W;
    vector<pair<double, double>> items;
    for (int i = 0; i < n; i++) {
        cin >> v >> w;
        items.push_back(make_pair(v, w));
    }
    sort(items.begin(), items.end(), comp);
    knapsack(items, W);
    return 0;
}