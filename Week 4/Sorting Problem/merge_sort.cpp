#include <bits/stdc++.h>

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

vector<int> merge_sort(vector<int> &A) {
    if (A.size() == 1)
        return A;
    int m = (A.size() - 1) / 2;
    vector<int> b = subarr(A, 0, m);
    vector<int> c = subarr(A, m + 1, A.size() - 1);
    vector<int> B = merge_sort(b);
    vector<int> C = merge_sort(c);
    vector<int> A_p = merge(B, C);
    return A_p;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    vector<int> res = merge_sort(numbers);
    print_vector(res);
    return 0;
}