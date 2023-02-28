#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
    int n = envelopes.size();
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        height[i] = envelopes[i][1];
    }
    vector<int> dp;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < i; ++j) {
//            if (height[i] > height[j]) {
//                dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//    }
    for (auto en : envelopes) {
        int index = lower_bound(dp.begin(), dp.end(), en[1]) - dp.begin();
        if (index > dp.size()) {
            dp.emplace_back(en[1]);
        } else {
            dp[index] = en[1];
        }
    }
//    int res = 0;
//    for (auto d : dp) {
//        res = max(d, res);
//    }
//    return res;
    return dp.size();
}

int LIS(vector<int>& nums) {
    vector<int> top(nums.size());
    int piles = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int poker = nums[i];

        int left = 0, right = piles;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (top[mid] < poker) {
                left = mid + 1;
            } else if (top[mid] > poker) {
                right = mid;
            } else {
                right = mid;
            }
        }
        if (left == piles) piles++;
        top[left] = poker;
    }
    return piles;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
