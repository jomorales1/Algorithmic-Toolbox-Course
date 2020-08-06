#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0 ? true : false;
}

void largest(vector<string> numbers) {
    sort(numbers.begin(), numbers.end(), comp);
    for (auto n: numbers) {
        cout << n;
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    largest(numbers);
    return 0;
}