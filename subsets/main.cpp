#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets0(vector<int> nums) {
    if (nums.empty()) return {{}};
    int n = nums.back();
    nums.pop_back();
    vector<vector<int>> res = subsets0(nums);
    int size = res.size();
    for (int i = 0; i < size; ++i) {
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}

vector<vector<int>> res;

void backTrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);

    for (int i = start; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        backTrack(nums, i + 1, track);
        track.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    res.clear();
    vector<int> track;
    backTrack(nums, 0, track);
    return res;
}


int main() {
    vector<int> nums = {1, 2, 3};
//    vector<vector<int>> ans = subsets0(nums);

    vector<vector<int>> ans = subsets(nums);
    for (auto m : ans) {
        for (auto n : m) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
