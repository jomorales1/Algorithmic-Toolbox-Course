#include <bits/stdc++.h>

using namespace std;

int n;
bool chosen[100];

struct Segment {
  int start, end;
};

bool comp_segments(Segment a, Segment b) {
  return a.start <= b.start && a.end <= b.end;
}

int check_point(vector<Segment> &segments, int point) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!chosen[i] && (point >= segments[i].start && point <= segments[i].end)) {
      res++;
    }
  }
  return res;
}

void choose_segments(vector<Segment> &segments, int point) {
  for (int i = 0; i < n; i++) {
    if (!chosen[i] && (point >= segments[i].start && point <= segments[i].end)) {
      chosen[i] = true;
    }
  }
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (!chosen[i]) {
      int count = 1;
      int point = segments[i].start;
      for (int j = segments[i].start; j <= segments[i].end; j++) {
        int v = check_point(segments, j);
        if (v > count) {
          count = v;
          point = j;
        }
      }
      c += count;
      choose_segments(segments, point);
      points.push_back(point);
    }
    if (c == n)
      break;
  }
  return points;
}

int main() {
  cin >> n;
  vector<Segment> segments(n);
  for (int i = 0; i < n; ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(), segments.end(), comp_segments);
  for (int i = 0; i < n; i++) {
    chosen[i] = false;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (int i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
  cout << "\n";
  return 0;
}
