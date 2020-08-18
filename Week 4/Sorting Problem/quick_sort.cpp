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

pair<int, int> partition2(int a[], int left, int right) {
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
    randomized_quick_sort(numbers, left, m - 1);
    randomized_quick_sort(numbers, m + 1, right);
}

void randomized_quick_sort2(int numbers[], int left, int right) {
    if (left >= right)
        return;
    int k = rand() % (right - left + 1) + left;
    swap(numbers[left], numbers[k]);
    pair<int, int> m = partition2(numbers, left, right);
    int m1 = m.first;
    int m2 = m.second;
    randomized_quick_sort2(numbers, left, m1 - 1);
    randomized_quick_sort2(numbers, m2 + 1, right);
}

void randomized_quick_sort3(int numbers[], int left, int right) {
    while (left < right) {
        int k = rand() % (right - left + 1) + left;
        swap(numbers[left], numbers[k]);
        int m = partition(numbers, left, right);
        if (m - left < right - m) {
            randomized_quick_sort3(numbers, left, m - 1);
            left = m + 1;
        } else {
            randomized_quick_sort3(numbers, m + 1, right);
            right = m - 1;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    randomized_quick_sort3(numbers, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << numbers[i] << " ";
    cout << '\n';
    return 0;
}