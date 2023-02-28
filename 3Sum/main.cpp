#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {
    int left = start, right = nums.size() - 1;
    vector<vector<int>> res;
    while (left < right) {
        int leftNum = nums[left], rightNum = nums[right];
        int sum = leftNum + rightNum;
        if (sum < target) {
            while (nums[left] == leftNum && left < right) left++;
        } else if (sum > target) {
            while (nums[right] == rightNum && left < right) right--;
        } else {
            res.push_back({leftNum, rightNum});
            while (nums[left] == leftNum && left < right) left++;
            while (nums[right] == rightNum && left < right) right--;
        }
    }
    return res;
}

vector<vector<int>> threeSumTarget(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
        vector<vector<int>> twoSum = twoSumTarget(nums, i + 1, target - nums[i]);
        for (auto &two : twoSum) {
            two.push_back(nums[i]);
            res.push_back(two);
        }
        while (nums[i] == nums[i + 1] && i + 1 < nums.size()) ++i;
    }
    return res;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    return threeSumTarget(nums, 0);
}

vector<vector<int>> threeSum0(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int other = target - nums[i];
        int left = i + 1, right = n - 1;
        vector<vector<int>> ans;
        while (left < right) {
            int sum = nums[left] + nums[right];
            int leftNum = nums[left], rightNum = nums[right];
            if (sum < other) {
                while (leftNum == nums[left] && left < right) left++;
            } else if (sum > other) {
                while (rightNum == nums[right] && left < right) right--;
            } else {
                ans.push_back({leftNum, rightNum});
                while (leftNum == nums[left] && left < right) left++;
                while (rightNum == nums[right] && left < right) right--;
            }
        }
        for (auto & a : ans) {
            a.push_back(nums[i]);
            res.push_back(a);
        }
        while (nums[i] == nums[i + 1] && i + 1 < n) i++;
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
//            {0, 0, 0, 0};
    auto res = threeSum0(nums,0);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
