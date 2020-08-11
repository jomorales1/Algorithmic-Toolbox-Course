#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &numbers, int a) {
    int low = 0;
    int high = numbers.size() - 1;
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
    return low - 1;
}

int recursive_binary_search(const vector<int> &numbers, int low, int high, int a) {
    if (high < low)
        return low - 1;
    int mid = (low + high) / 2;
    if (numbers[mid] == a)
        return mid;
    else if (numbers[mid] > a)
        return recursive_binary_search(numbers, low, mid - 1, a);
    else
        return recursive_binary_search(numbers, mid + 1, high, a);
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
    cout << "Sorted array: \n";
    for (auto number : numbers) {
        cout << number << " ";
    }
    cout << '\n';
    int obj = 0;
    cin >> obj;
    int index1 = binary_search(numbers, obj);
    int index2 = recursive_binary_search(numbers, 0, n - 1, obj);
    cout << "Iterative: " << index1 << '\n';
    cout << "Recursive: " << index2 << '\n';
}