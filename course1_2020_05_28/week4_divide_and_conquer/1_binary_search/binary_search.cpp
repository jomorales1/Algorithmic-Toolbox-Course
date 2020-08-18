#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size(); 
    //write your code here
    while (left <= right) {
        int k = (left + right) / 2;
        if (a[k] == x)
            return k;
        if (a[k] < x)
            left = k + 1;
        if (a[k] > x)
            right = k - 1;
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    int m = 0;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        cout << binary_search(a, b[i]) << ' ';
    }
    cout << '\n';
    return 0;
}
