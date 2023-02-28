#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> memo;

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int dp(int n, int a_num, int copy) {
    if (n <= 0) return a_num;

    if (memo.count(n)) return memo[n];

    memo[n] =  max(dp(n - 1, a_num + 1, copy), dp(n - 1, a_num + copy, copy), dp(n - 2, a_num, a_num));
    return memo[n];
}

int maxA0(int n) {
    return dp(n, 0, 0);
}

int maxA(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j < i; ++j) {
            dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
        }
    }
    return dp[n];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
