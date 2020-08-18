#include <bits/stdc++.h>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    //write your code here
    int m = (left + right) / 2;
    int a1 = get_majority_element(a, left, m);
    int a2 = get_majority_element(a, m, right);
    if (a1 == a2) {
        return a1;
    }
    int count1 = 0, count2 = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == a1)
            count1++;
        if (a[i] == a2)
            count2++;
    }
    if (count1 > count2 && count1 > (right - left) / 2)
        return a1;
    if (count2 > count1 && count2 > (right - left) / 2)
        return a2;
    return -1;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
    return 0;
}
