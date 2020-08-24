#include <bits/stdc++.h>

using namespace std;

const int s = (int) 1e3 + 1;
int dp[s][s];

int edit_distance(string a, string b) {
    int n = a.length();
    int m = b.length();
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int insertion = dp[i][j - 1] + 1;
            int deletion = dp[i - 1][j] + 1;
            int match = dp[i - 1][j - 1];
            int mismatch = dp[i - 1][j - 1] + 1;
            if (a[i] == b[j])
                dp[i][j] = min(insertion, min(deletion, match));
            else
                dp[i][j] = min(insertion, min(deletion, mismatch));
        }
    }
    return dp[n][m];
}

void output_alignment(string a, string b, int i, int j) {
    if (i == -1 && j == -1)
        return;
    if (i >= 0 && dp[i][j] == dp[i - 1][j] + 1) {
        output_alignment(a, b, i - 1, j);
        cout << a[i] << ' ' << '-' << '\n';
    }
    else if (j >= 0 && dp[i][j] == dp[i][j - 1] + 1) {
        output_alignment(a, b, i, j - 1);
        cout << '-' << ' ' << b[j] << '\n';
    } else {
        output_alignment(a, b, i - 1, j - 1);
        cout << a[i] << ' ' << b[j] << '\n';
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << "Edit distance: " << edit_distance(a, b) << '\n';
    output_alignment(a, b, a.length(), b.length());
    return 0;
}