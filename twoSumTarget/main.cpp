#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<vector<int>> res;
    while (left < right) {
        int leftNum = nums[left], rightNum = nums[right];
        int sum = leftNum + rightNum;
        if (sum < target) {
            while (nums[left] == leftNum && left < right) left++;
        } else if (sum > target) {
            while (nums[right] == rightNum && left < right) right--;
        } else {
            res.push_back({left, right});
            while (nums[left] == leftNum && left < right) left++;
            while (nums[right] == rightNum && left < right) right--;
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
