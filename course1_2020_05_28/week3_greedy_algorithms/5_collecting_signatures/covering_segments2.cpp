#include <bits/stdc++.h>

using namespace std;

bool comp_segments(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool share_point(pair<int, int> a, pair<int, int> b) {
    return b.first >= a.first && b.first <= a.second;
}

bool contains(vector<int> points, int point) {
    for (auto p : points) {
        if (p == point)
            return true;
    }
    return false;
}

int contain_point(vector<pair<int, int>> &segments, vector<bool> &chosen, int point) {
    int count = 0;
    for (int i = 0; i < segments.size(); i++) {
        if (!chosen[i] && point >= segments[i].first && point <= segments[i].second)
            count++;
    }
    return count;
}

void choose(vector<pair<int, int>> &segments, vector<bool> &chosen, int point) {
    for (int i = 0; i < segments.size(); i++) {
        if (!chosen[i] && point >= segments[i].first && point <= segments[i].second) {
            chosen[i] = 1;
        }
    }
}

vector<int> optimal_points(vector<pair<int, int>> &segments) {
    vector<int> points;
    vector<bool> chosen(segments.size());
    for (int j = 0; j < segments.size(); j++) {
        if (chosen[j])
            continue;
        choose(segments, chosen, segments[j].second);
        points.push_back(segments[j].second);
    }
    return points;
}

int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    sort(segments.begin(), segments.end(), comp_segments);
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (auto point : points) {
        cout << point << " ";
    }
    cout << "\n";
    return 0;
}