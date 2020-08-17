#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int partition(int numbers[], int left, int right) {
    int x = numbers[left];
    int j = left;
    for (int i = left + 1; i <= right; i++) {
        if (numbers[i] <= x) {
            j++;
            swap(numbers[j], numbers[i]);
        }
    }
    swap(numbers[left], numbers[j]);
    return j;
}

pair<int, int> partition2(int numbers[], int left, int right) {
    int x = numbers[left];
    int j = left;
    int k = left;
    for (int i = left + 1; i <= right; i++) {
        if (numbers[i] <= x) {
            j++;
            swap(numbers[j], numbers[i]);
        }
        if (numbers[i] == x)
            k++;
    }
    swap(numbers[left], numbers[j]);
    pair<int, int> res = {k, j};
    return res;
}

void quick_sort(int numbers[], int left, int right) {
    if (left >= right)
        return;
    int m = partition(numbers, left, right);
    quick_sort(numbers, left, m - 1);
    quick_sort(numbers, m + 1, right);
}

void randomized_quick_sort(int numbers[], int left, int right) {
    if (left >= right)
        return;
    int k = rand() % (right - left + 1) + left;
    swap(numbers[left], numbers[k]);
    int m = partition(numbers, left, right);
    quick_sort(numbers, left, m - 1);
    quick_sort(numbers, m + 1, right);
}

void randomized_quick_sort2(int numbers[], int left, int right) {
    if (left >= right)
        return;
    int k = rand() % (right - left + 1) + left;
    swap(numbers[left], numbers[k]);
    pair<int, int> m = partition2(numbers, left, right);
    int m1 = m.first;
    int m2 = m.second;
    quick_sort(numbers, left, m1 - 1);
    quick_sort(numbers, m2 + 1, right);
}

int main() {
    int n = 0;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    randomized_quick_sort2(numbers, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << numbers[i] << " ";
    cout << '\n';
    return 0;
}