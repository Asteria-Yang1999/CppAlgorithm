#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> res;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] == target) {
            res.push_back(left);
            res.push_back(right);
            return res;
        } else if (nums[left] + nums[right] < target) {
            left++;
        } else right--;
    }
    return res;
}

int main() {
    vector<int> nums = {5, 7, 6, 4, 9, 22};
    int target = 27;
    vector<int> res = twoSum(nums, target);
    for (auto r : res) {
        cout << r << endl;
    }
    return 0;
}
