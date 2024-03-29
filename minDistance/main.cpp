#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int minDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) dp[i][0] = i;
    for (int j = 0; j < n; ++j) dp[0][j] = j;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

    }
    return dp[m][n];

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
