#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum0(vector<int>& nums, int k) {
    vector<int> sum(nums.size() + 1);
    sum[0] = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum[i + 1] = sum[i] + nums[i];
    }

    int res = 0;
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (sum[i] - sum[j] == k) {
                res++;
            }
        }
    }
    return res;
}

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> preSum;
    preSum[0] = 1;
    int res = 0;
    int sum_i = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum_i += nums[i];
        int sum_j = sum_i - k;
        if (preSum.count(sum_j)) {
            res += preSum[sum_j];
        }
        preSum[sum_i]++;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 1, 1, 2};
    cout << subarraySum(nums, 2);
    return 0;
}
