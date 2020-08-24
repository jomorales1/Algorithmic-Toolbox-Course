#include <bits/stdc++.h>

using namespace std;

int edit_distance(string a, string b) {
    int n = a.length();
    int m = b.length();
    int dp[n + 1][m + 1];
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

int main() {
    string a, b;
    cin >> a >> b;
    cout << "Edit distance: " << edit_distance(a, b) << '\n';
    return 0;
}