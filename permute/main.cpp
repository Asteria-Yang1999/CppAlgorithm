#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

void backTrack(vector<int>& nums, vector<int>& track) {
    if (track.size() == nums.size()) {
        res.push_back(track);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (find(track.begin(), track.end(),nums[i]) != track.end()) {
            continue;
        }
        track.push_back(nums[i]);
        backTrack(nums, track);
        track.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> track;
    backTrack(nums, track);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (auto m : ans) {
        for (auto n : m) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
