#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &numbers, int a) {
    int low = 0;
    int high = numbers.size();
    int k;
    while (low <= high) {
        k = (low + high) / 2;
        if (numbers[k] == a)
            return k;
        if (numbers[k] > a)
            high = k - 1;
        else
            low = k + 1;
    }
    return -1;
}

int main() {
    // TODO: implement binary search
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int obj = 0;
    cin >> obj;
    int index = binary_search(numbers, obj);
    cout << index << '\n';
}