#include <iostream>
#include <vector>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    if (n == 0) {
        return tasks.size();
    }
    int size = tasks.size();
    vector<int> dp(size, 1);
    for (int i = 1; i < size; ++i) {
        if (tasks[i] == tasks[i - 1]) {
            dp[i] = dp[i - 1] + n + 1;
        } else {
            if (i < dp[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
    }
    return dp[size - 1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
