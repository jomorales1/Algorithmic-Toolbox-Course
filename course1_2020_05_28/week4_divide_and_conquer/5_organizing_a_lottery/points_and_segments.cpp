#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int point_m = 0;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return abs(point_m - a.first) < abs(point_m - b.first) && abs(point_m - a.second) < abs(point_m - b.second); 
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

bool comp_segments(pair<int, int> a, pair<int, int> b) {
    int l1 = abs(point_m - a.second);
    int l2 = abs(point_m - b.second);
    return l1 < l2;
}

bool comp_segments2(pair<int, int> a, pair<int, int> b) {
    int l1 = abs(point_m - a.first);
    int l2 = abs(point_m - b.first);
    return l1 < l2;
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

vector<pair<int, int>> choose(vector<pair<int, int>> &segments, vector<bool> &chosen, int point) {
    vector<pair<int, int>> res;
    for (int i = 0; i < segments.size(); i++) {
        if (!chosen[i] && point >= segments[i].first && point <= segments[i].second) {
            chosen[i] = 1;
            res.push_back(segments[i]);
        }
    }
    point_m = point;
    sort(res.begin(), res.end(), compare);
    return res;
}

vector<pair<int, vector<pair<int, int>>>> optimal_points(vector<pair<int, int>> &segments) {
    vector<pair<int, vector<pair<int, int>>>> res;
    vector<bool> chosen(segments.size());
    for (int j = 0; j < segments.size(); j++) {
        if (chosen[j])
            continue;
        res.push_back({segments[j].second, choose(segments, chosen, segments[j].second)});
    }
    return res;
}

vector<int> count_segments(vector<pair<int, int>> &segments, vector<int> &points) {
    sort(segments.begin(), segments.end(), comp);
    vector<pair<int, vector<pair<int, int>>>> sets = optimal_points(segments);
    vector<int> cnt(points.size());
    for (auto &s : sets) {
        point_m = s.first;
        /*cout << "M: " << point_m << '\n';
        for (const auto &segment : s.second) {
            cout << "(" << segment.first << ", " << segment.second << ") ";
        }
        cout << '\n';*/
        for (int i = 0; i < points.size(); i++) {
            int aux = 0;
            bool a = false;
            //sort(s.second.begin(), s.second.end(), comp_segments);
            /*for (const auto &segment : s.second) {
                cout << "(" << segment.first << ", " << segment.second << ") ";
            }
            cout << '\n';*/
            while(aux < s.second.size()) {
                //cout << "(" << point_m << ", " << s.second[aux].second << ")\n";
                if (points[i] >= point_m && points[i] <= s.second[aux].second) {
                    cnt[i] += (s.second.size() - aux);
                    a = true;
                    /*cout << "Point: " << points[i] << '\n';
                    cout << "Count: " << cnt[i] << '\n';*/
                    break;
                }
                aux++;
            }
            aux = 0;
            if (!a) {
                //sort(s.second.begin(), s.second.end(), comp_segments2);
                /*for (const auto &segment : s.second) {
                    cout << "(" << segment.first << ", " << segment.second << ") ";
                }
                cout << '\n';*/
                while(aux < s.second.size()) {
                    if (points[i] >= s.second[aux].first && points[i] <= point_m) {
                        cnt[i] += (s.second.size() - aux);
                        /*cout << "Point: " << points[i] << '\n';
                        cout << "Count: " << cnt[i] << '\n';*/
                        break;
                    }
                    aux++;
                }
            }
        }
    }
    return cnt;
}

vector<int> fast_count_segments(vector<pair<int, int>> &segments, vector<int> points) {
    sort(segments.begin(), segments.end(), comp_segments);
    int n = points.size();
    vector<int> cnt(n);
    //write your code here
    int left, right, mid;
    for (int i = 0; i < n; i++) {
        left = 0;
        right = segments.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (points[i] >= segments[mid].first && points[i] <= segments[mid].second) {
                cnt[i]++;
                int index_a = mid - 1;
                if (index_a >= 0) {
                    while (points[i] >= segments[index_a].first && points[i] <= segments[index_a].second && index_a >= 0) {
                        cnt[i]++; index_a--;
                    }
                }
                int index_b = mid + 1;
                if (index_b < segments.size()) {
                    while (points[i] >= segments[index_b].first && points[i] <= segments[index_b].second && index_b < n) {
                        cnt[i]++; index_b++;
                    }
                }
                break;
            }
            if (points[i] > segments[mid].second)
                left = mid + 1;
            if (points[i] < segments[mid].first)
                right = mid - 1;
        }
    }
    return cnt;
}

vector<int> count(vector<pair<int, int>> &segments, vector<int> &points) {
    unordered_map<int, int> frequencies;
    vector<int> res(points.size());
    for (const auto &segment : segments) {
        for (int i = segment.first; i <= segment.second; i++) {
            frequencies[i]++;
        }
    }
    for (int i = 0; i < points.size(); i++) {
        res[i] = frequencies[points[i]];
    }
    return res;
}

vector<int> naive_count_segments(vector<pair<int, int>> &segments, vector<int> &points) {
    vector<int> cnt(points.size());
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < segments.size(); j++) {
            cnt[i] += segments[j].first <= points[i] && points[i] <= segments[j].second;
        }
    }
    return cnt;
}

bool contains(const vector<int> &elements, int x) {
    int n = elements.size();
    for (int i = 0; i < n; i++) {
        if (elements[i] == x)
            return true;
    }
    return false;
}

bool are_equal(const vector<int> &a, const vector<int> &b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void stress_test() {
    while(true) {
        int n = rand() % 4 + 1;
        int m = rand() % 4 + 1;
        vector<pair<int, int>> segments(n);
        int lower_limit = -1, upper_limit = -1;
        for (int i = 0; i < n; i++) {
            lower_limit = rand() % 5 + 1;
            upper_limit = rand() % 5 + 1;
            while (lower_limit >= upper_limit) {
                lower_limit = rand() % 5 + 1;
                upper_limit = rand() % 5 + 1;
            }
            segments[i].first = lower_limit;
            segments[i].second = upper_limit;
        }
        //sort(segments.begin(), segments.end());
        vector<int> points(m);
        int point = -1;
        for (int i = 0; i < m; i++) {
            point = rand() % 6 + 1;
            points[i] = point;
        }
        cout << "Segments\n";
        for (int i = 0; i < n - 1; i++) {
            cout << "(" << segments[i].first << ", " << segments[i].second << "), ";
        }
        cout << "(" << segments[n - 1].first << ", " << segments[n - 1].second <<")";
        cout << "\n\n";
        cout << "Points\n";
        for (const auto &point : points) {
            cout << point << " ";
        }
        cout << "\n\n";
        vector<int> res1 = naive_count_segments(segments, points);
        vector<int> res2 = count_segments(segments, points);
        int equal = are_equal(res1, res2);
        if (!equal) {
            cout << "Wrong answer:\n";
            for (const auto &c : res1) {
                cout << c << " ";
            }
            cout << '\n';
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
    stress_test();
    /*int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < segments.size(); i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    vector<int> points(m);
    for (int i = 0; i < points.size(); i++) {
        cin >> points[i];
    }
    //use fast_count_segments
    vector<int> cnt = count_segments(segments, points);
    for (int i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << ' ';
    }
    cout << '\n';*/
    return 0;
}
