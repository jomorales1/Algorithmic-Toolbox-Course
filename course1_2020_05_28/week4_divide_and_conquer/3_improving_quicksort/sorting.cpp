#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

pair<int, int> partition(vector<int> &a, int left, int right) {
    int x = a[left];
    int k = left;
    for (int i = left + 1; i <= right; i++) {
        if (a[i] == x) {
            k++;
            swap(a[k], a[i]);
        }
    }
    int j = k;
    int aux = left;
    for (int i = k + 1; i <= right; i++) {
        if (a[i] < x) {
            j++;
            swap(a[j], a[i]);
            swap(a[j], a[aux]);
            aux++;
        }
    }
    return {aux, k};
}

pair<int, int> partition3(vector<int> &a, int left, int right) {
    int x = a[left];
    int j = left;
    int aux = left - 1;
    for (int i = left + 1; i <= right; i++) {
        if (a[i] == x) {
            j++;
            swap(a[i], a[j]);
        } else if(a[i] < x) {
            j++;
            aux++;
            swap(a[i], a[j]);
            swap(a[j], a[aux]);
        }
    }
    if (aux < left)
        aux = left;
    return {aux, j};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    pair<int, int> m = partition3(a, l, r);
    int m1 = m.first;
    int m2 = m.second;

    randomized_quick_sort(a, l, m1);
    randomized_quick_sort(a, m2 + 1, r);
}

bool compare(vector<int> &a, vector<int> &b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void stress_test() {
    while (true) {
        int n = rand() % 10 + 5;
        vector<int> numbers;
        vector<int> test;
        int element;
        for (int i = 0; i < n; i++) {
            element = rand() % 5 + 1;
            numbers.push_back(element);
            test.push_back(element);
        }
        cout << "Array:\n";
        for (int i = 0; i < n; i++) {
            cout << numbers[i] << " ";
        }
        cout << '\n';
        randomized_quick_sort(numbers, 0, n - 1);
        sort(test.begin(), test.end());
        for (const auto &x : numbers) {
            cout << x << " ";
        }
        cout << '\n';
        for (const auto &x : test) {
            cout << x << " ";
        }
        cout << '\n';
        bool res = compare(numbers, test);
        if (res) {
            cout << "OK\n\n";
        } else {
            cout << "Wrong answer\n";
            break;
        }
    }
}

int main() {
    //stress_test();
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
