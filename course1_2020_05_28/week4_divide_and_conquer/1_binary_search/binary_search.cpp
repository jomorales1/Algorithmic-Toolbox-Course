#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int binary_search(const vector<int> &a, int x) {
    int left = 0;
    int right = a.size() - 1; 
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

void stress_test() {
    while(true) {
        int n = rand() % 100 + 100;
        vector<int> numbers(n);
        int element = 0;
        for (int i = 0; i < n; i++) {
            element = rand() % 100 + 1;
            numbers[i] = element;
        }
        sort(numbers.begin(), numbers.end());
        int k = rand() % 100 + 10;
        vector<int> s(k);
        for (int i = 0; i < k; i++) {
            element = rand() % 100 + 1;
            s[i] = element;
        }
        int res1 = -1;
        int res2 = -1;
        bool diff = true;
        for (int i = 0; i < k; i++) {
            res1 = binary_search(numbers, s[i]);
            res2 = linear_search(numbers, s[i]);
            diff = res1 == res2;
            if (!diff) {
                for (int j = 0; j < n; j++) {
                    cout << numbers[j] << " ";
                }
                cout << '\n';
                cout << "Wrong answer\n";
                cout << "Element: " << s[i] << '\n';
                cout << "BS: " << res1 << ", " << "LS: " << res2 << '\n';
                break;
            }
            cout << "OK\n";
        }
        if (!diff)
            break;
    }
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
    //stress_test();
    return 0;
}
