#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &numbers, int a) {
    return 0;
}

int main() {
    // TODO: implement binary search
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int obj = 0;
    cin >> obj;
    int index = binary_search(numbers, obj);
    cout << index << '\n';
}