#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &numbers) {
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (numbers[j] < numbers[minIndex])
                minIndex = j;
        swap(numbers[i], numbers[minIndex]);
    }
}

void print_vector(const vector<int> &elements) {
    for (auto element : elements)
        cout << element << " ";
    cout << '\n';
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    selection_sort(numbers);
    print_vector(numbers);
    return 0;
}