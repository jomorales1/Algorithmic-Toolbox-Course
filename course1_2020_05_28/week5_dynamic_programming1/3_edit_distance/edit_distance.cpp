#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

const int s = (int) 1e3 + 1;
int dp[s][s];

int min_t(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int edit_distance1(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
	vector<vector<int>> dp2(m + 1, vector<int>(n + 1));
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp2[i][j] = j;
			else if (j == 0)
				dp2[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
				dp2[i][j] = dp2[i - 1][j - 1];
			else
				dp2[i][j] = 1 + min(min(dp2[i][j - 1], dp2[i - 1][j]), dp2[i - 1][j - 1]);
		}
	}
	return dp[m][n];
}

int edit_distance2(string a, string b) {
    int n = a.length();
    int m = b.length();
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[j][0] = j;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int insertion = dp[j][i - 1] + 1;
            int deletion = dp[j - 1][i] + 1;
            int match = dp[j - 1][i - 1];
            int mismatch = dp[j - 1][i - 1] + 1;
            if (a[j - 1] == b[i - 1]) {
                dp[j][i] = dp[j - 1][i - 1];
            } else {
                dp[j][i] = min_t(insertion, deletion, mismatch);
            }
        }
    }
    return dp[n][m];
}

void stress_test() {
    string letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    while (true) {
        int n = rand() % 10 + 10;
        int m = rand() % 10 + 10;
        string a = "";
        for (int i = 0; i < n; i++) {
            a.append(letters[rand() % 26]);
        }
        string b = "";
        for (int i = 0; i < m; i++) {
            b.append(letters[rand() % 26]);
        }
        int res1 = edit_distance1(a, b);
        int res2 = edit_distance2(a, b);
        if (res1 != res2) {
            cout << "Wrong answer\n";
            cout << "Word 1: " << a << '\n';
            cout << "Word 2: " << b << '\n';
            cout << "User's answer:  " << res2 << '\n';
            cout << "Correct answer: " << res1 << '\n';
            break;
        } else {
            cout << "OK\n";
        }
    }
}

int main() {
    stress_test();
    /*string a, b;
    cin >> a >> b;
    cout << edit_distance1(a, b) << '\n';*/
    return 0;
}