#include <bits/stdc++.h>
#include <cstdlib>

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
        if ((numbers[first_max_index] != numbers[i]) && ((second_max_index == -1) || (numbers[i] > numbers[second_max_index]))) {
            second_max_index = i;
        }
    }

    cout << first_max_index << " " << second_max_index << "\n";

    return ((long long) numbers[first_max_index]) * numbers[second_max_index];
}

int main() {
    while (true) {
        int n = rand() % 4 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; i++) {
            a.push_back(rand() % 10);
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";

        long long res1 = maximum_pairwise_product(a);
        long long res2 = maximum_pairwise_product_fast(a);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << " " << res2 << "\n";
            break;
        } else {
            cout << "OK\n";
        }
    }
    return 0;
}