#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;

void backTrack(int n, int k, int start, vector<int>& track) {
    if (track.size() == k) {
        res.push_back(track);
        return;
    }
    for (int i = start; i <= n; ++i) {
        track.push_back(i);
        backTrack(n, k, i + 1, track);
        track.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> track;
    backTrack(n, k, 1, track);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = combine(4, 2);
    for (auto m : ans) {
        for (auto n : m) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
