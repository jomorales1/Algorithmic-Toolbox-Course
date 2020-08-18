#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void print_vector(const vector<int> &elements) {
    for (auto element : elements)
        cout << element << " ";
    cout << '\n';
}

vector<int> subarr(vector<int> &A, int left, int right) {
    vector<int> res;
    for (int i = left; i <= right; i++) {
        res.push_back(A[i]);
    }
    return res;
}

vector<int> merge(vector<int> &B, vector<int> &C) {
    int index_b = 0;
    int index_c = 0;
    vector<int> D;
    while(index_b < B.size() && index_c < B.size()) {
        int b = B[index_b];
        int c = C[index_c];
        if (b <= c) {
            D.push_back(b);
            index_b++;
        } else {
            D.push_back(c);
            index_c++;
        }
    }
    while (index_b < B.size()) {
        int b = B[index_b];
        D.push_back(b);
        index_b++;
    }
    while (index_c < C.size()) {
        int c = C[index_c];
        D.push_back(c);
        index_c++;
    }
    return D;
}

int merge_sort(vector<int> &A) {
    if (A.size() == 1)
        return 0;
    int m = (A.size() - 1) / 2;
    vector<int> b = subarr(A, 0, m);
    vector<int> c = subarr(A, m + 1, A.size() - 1);
    int res = 0;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            if (b[i] > c[j])
                res++;
        }
    }
    return res + merge_sort(b) + merge_sort(c);
}

int naive_solution(const vector<int> &A) {
    int res = 0;
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j])
                res++;
        }
    }
    return res;
}

void stress_test() {
    while(true) {
        int n = rand() % 10 + 6;
        vector<int> numbers(n);
        int element = -1;
        for (int i = 0; i < n; i++) {
            element = rand() % 10 + 1;
            numbers[i] = element;
            cout << element << " ";
        }
        cout << '\n';
        int res1 = naive_solution(numbers);
        int res2 = merge_sort(numbers);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << " " << res2 << '\n';
            break;
        } else {
            cout << "0K\n";
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int res = merge_sort(numbers);
    cout << res << '\n';
    //stress_test();
    return 0;
}