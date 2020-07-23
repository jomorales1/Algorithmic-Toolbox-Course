#include <bits/stdc++.h>

using namespace std;

long long maximum_pairwise_product(const vector<int>& numbers) {
    int n = numbers.size();
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j++) {
            if (((long long) numbers[i]) * numbers[j] > res) {
                res = ((long long) numbers[i]) * numbers[j];
            }
        }
    }
    return res;
}

long long maximum_pairwise_product_fast(const vector<int>& numbers) {
    int n = numbers.size();

    int first_max_index = -1;
    for (int i = 0; i < n; ++i) {
        if ((first_max_index == -1) || (numbers[i] > numbers[first_max_index])) {
            first_max_index = i;
        }
    }

    int second_max_index = -1;
    for (int i = 0; i < n; ++i) {
        if ((first_max_index != i) && ((second_max_index == -1) || (numbers[i] > numbers[second_max_index]))) {
            second_max_index = i;
        }
    }

    return ((long long) numbers[first_max_index]) * numbers[second_max_index];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = maximum_pairwise_product_fast(numbers);
    cout << result << "\n";
    return 0;
}