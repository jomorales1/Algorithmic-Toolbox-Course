#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> grouping(const vector<double>& ages) {
    vector<pair<double, double>> segments;
    int i = 0;
    int n = ages.size();
    while (i < n) {
        pair<double, double> seg = {ages[i], ages[i] + 1.0};
        segments.push_back(seg);
        i++;
        while (i < n && ages[i] <= seg.second) {
            i++;
        }
    }
    return segments;
}

int main() {
    int n;
    cin >> n;
    vector<double> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    sort(ages.begin(), ages.end());
    vector<pair<double, double>> res = grouping(ages);
    vector<vector<double>> groups(res.size());
    int segment = 0;
    for (int i = 0; i < n; i++) {
        if (ages[i] >= res[segment].first && ages[i] <= res[segment].second) {
            groups[segment].push_back(ages[i]);
        } else {
            segment++;
            groups[segment].push_back(ages[i]);
        }
    }
    cout << "Segments\n";
    for (auto seg: res) {
        cout << "(" << seg.first << ", " << seg.second << ")\n";
    }
    cout << "Groups\n";
    for (auto gr: groups) {
        for (auto ch: gr) {
            cout << ch << " ";
        }
        cout << "\n";
    }
    return 0;
}