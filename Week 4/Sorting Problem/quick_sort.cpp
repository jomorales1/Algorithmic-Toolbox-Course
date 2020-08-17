#include <bits/stdc++.h>

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

void quick_sort(int numbers[], int left, int right) {
    if (left >= right)
        return;
    int m = partition(numbers, left, right);
    quick_sort(numbers, left, m - 1);
    quick_sort(numbers, m + 1, right);
}

int main() {
    int n = 0;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    quick_sort(numbers, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << numbers[i] << " ";
    cout << '\n';
    return 0;
}