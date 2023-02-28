#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return ans;
}

vector<int> nextWarmerWeather(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> dic;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!dic.empty() && nums[dic.top()] <= nums[i]) {
            dic.pop();
        }
        ans[i] = dic.empty() ? 0 : (dic.top() - i);
        dic.push(i);
    }
    return ans;
}

vector<int> nextGreaterElement0(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums[i % n]) {
            s.pop();
        }
        ans[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> res = nextGreaterElement(nums);
    vector<int> res0 = nextGreaterElement0(nums);
    for (auto i : res) {cout << i << " ";}
    cout << endl;
    for (auto j : res) {cout << j << " ";}
    cout << endl;
    vector<int> w = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = nextWarmerWeather(w);
    for (auto i : ans) {cout << i << " ";}
    cout << endl;

    return 0;
}
