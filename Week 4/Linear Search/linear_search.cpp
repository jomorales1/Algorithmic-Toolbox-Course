#include <bits/stdc++.h>

using namespace std;

int linear_search(const vector<int> &numbers, int low, int high, int a) {
    if (low > high)
        return -1;
    if (numbers[low] == a)
        return low;
    return linear_search(numbers, low + 1, high, a);
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int obj = 0;
    cin >> obj;
    int index = linear_search(numbers, 0, n - 1, obj);
    cout << (index != -1 ? "Element found: " : "Element not found.");
    cout << (index != -1 ? to_string(index) : "");
    cout << '\n';
    return 0;
}