#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

bool compare_segments1(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

bool compare_segments2(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

bool compare_segments3(pair<int, int> &a, pair<int, int> &b) {
    int l1 = abs(a.first - a.second);
    int l2 = abs(b.first - b.second);
    return l1 <= l2;
}

bool contains_point(pair<int, int> &segment, int point) {
    return point >= segment.first && point <= segment.second;
}

vector<int> fast_count_points(vector<pair<int, int>> &segments, vector<int> &points, int max) {
    int n = points.size();
    vector<int> cnt(n);
    sort(segments.begin(), segments.end());
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = segments.size() - 1;
        int mid = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (contains_point(segments[mid], points[i]))
                break;
            if (points[i] > segments[mid].second)
                left = mid + 1;
            if (points[i] < segments[mid].first)
                right = mid - 1;
        }
        int index_left = mid;
        while (index_left >= 0) {
            if (contains_point(segments[index_left], points[i])) {
                cnt[i]++;
            } else {
                /*if (segments[index_left].first != segments[index_left].second &&
                    abs(segments[index_left].first - segments[index_left].second) > 2)
                    break;*/
            }
            index_left--;
            if (segments[index_left].first < points[i] && segments[index_left].second < points[i] && points[i] < max / 2)
                break;
        }
        int index_right = mid + 1;
        while (index_right < segments.size()) {
            if (contains_point(segments[index_right], points[i])) {
                cnt[i]++;
            } else {
                /*if (segments[index_right].first != segments[index_right].second &&
                    abs(segments[index_right].first - segments[index_right].second) > 2)
                    break;*/
            }
            index_right++;
            if (segments[index_right].first > points[i] && segments[index_right].second > points[i] && points[i] < max / 2)
                break;
        }
    }
    return cnt;
}

vector<int> count_points(vector<pair<int, int>> &segments, vector<int> &points) {
    unordered_map<int, int> frequencies;
    for (const auto &segment : segments) {
        for (int i = segment.first; i <= segment.second; i++) {
            frequencies[i]++;
        }
    }
    vector<int> cnt(points.size());
    for (int i = 0; i < points.size(); i++) {
        cnt[i] = frequencies[points[i]];
    }
    return cnt;
}

vector<int> naive_count_points(vector<pair<int, int>> &segments, vector<int> &points) {
    vector<int> cnt(points.size());
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < segments.size(); j++) {
            cnt[i] += segments[j].first <= points[i] && points[i] <= segments[j].second;
        }
    }
    return cnt;
}

bool are_equal(const vector<int> &a, const vector<int> &b) {
    int n = a.size();
    int m = b.size();
    if (n != m)
        return false;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void stress_test(int segments_size, int points_size) {
    while (true) {
        int s = rand() % (segments_size + 1) + 5;
        int p = rand() % (points_size + 1) + 5;
        vector<pair<int, int>> segments(s);
        int lower_limit = 0, upper_limit = 0;
        int m = INT_MIN;
        cout << "Segments:\n";
        for (int i = 0; i < s; i++) {
            lower_limit = rand() % 5;
            upper_limit = rand() % 5;
            while (lower_limit > upper_limit) {
                lower_limit = rand() % 5 + 5;
                upper_limit = rand() % 5 + 5;
            }
            m = max(m, lower_limit);
            m = max(m, upper_limit);
            segments[i] = {lower_limit, upper_limit};
            //cout << "(" << lower_limit << ", " << upper_limit << ") ";
        }
        sort(segments.begin(), segments.end());
        for (const auto &segment : segments) {
            cout << "(" << segment.first << ", " << segment.second << ") ";
        }
        cout << "\n\n";
        cout << "Points:\n";
        vector<int> points(p);
        for (int i = 0; i < p; i++) {
            points[i] = rand() % 5 + 5;
            cout << points[i] << " ";
        }
        cout << "\n\n";
        vector<int> res1 = naive_count_points(segments, points);
        vector<int> res2 = fast_count_points(segments, points, m);
        bool compare = are_equal(res1, res2);
        if (!compare) {
            cout << "Wrong answer:\n";
            cout << "Correct answer: ";
            for (const auto &c : res1) {
                cout << c << " ";
            }
            cout << '\n';
            cout << "User's answer:  ";
            for (const auto &c : res2) {
                cout << c << " ";
            }
            cout << '\n';
            break;
        } else {
            cout << "OK\n\n";
        }
    }
}

int main() {
    //stress_test(10, 10);
    int s = 0, p = 0;
    cin >> s >> p;
    vector<pair<int, int>> segments(s);
    int lower_limit = 0, upper_limit = 0;
    int m = INT_MIN;
    for (int i = 0; i < s; i++) {
        cin >> lower_limit >> upper_limit;
        m = max(m, lower_limit);
        m = max(m, upper_limit);
        segments[i] = {lower_limit, upper_limit};
    }
    vector<int> points(p);
    for (int i = 0; i < p; i++) {
        cin >> points[i];
    }
    vector<int> cnt = fast_count_points(segments, points, m);
    for (const auto &c : cnt) {
        cout << c << " ";
    }
    cout << '\n';
    /*int s = 0;
    cin >> s;
    vector<pair<int, int>> segments(s);
    for (int i = 0; i < s; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    sort(segments.begin(), segments.end(), compare_segments1);
    cout << "Sorted segments first component:\n";
    for (const auto &segment : segments) {
        cout << "(" << segment.first << ", " << segment.second << ") ";
    }
    cout << '\n';
    sort(segments.begin(), segments.end(), compare_segments2);
    cout << "Sorted segments second component:\n";
    for (const auto &segment : segments) {
        cout << "(" << segment.first << ", " << segment.second << ") ";
    }
    cout << '\n';*/
    return 0;
}