#include <iostream>
#include <vector>

using namespace std;

int trap0(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    for (int i = 1; i < n - 1; ++i) {
        int leftMax = 0, rightMax = 0;
        for (int left = 0; left <= i; ++left) {
            leftMax = max(leftMax, height[left]);
        }
        for (int right = n - 1; right >= i; --right) {
            rightMax = max(rightMax, height[right]);
        }
        ans += (min(leftMax, rightMax) - height[i]);
    }
    return ans;
}

int trap1(vector<int> &height) {
    int ans = 0;
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    for (int j = n - 2; j >= 0; --j) {
        rightMax[j] = max(rightMax[j + 1], height[j]);
    }
    for (int i = 1; i < n - 1; ++i) {
        ans += (min(leftMax[i], rightMax[i]) - height[i]);
    }
    return ans;
}

int trap2(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = height[0], rightMax = height[n - 1];
    int ans = 0;
    while (left <= right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);

        if (leftMax < rightMax) {
            ans += leftMax - height[left];
            left++;
        }
        if (rightMax <= leftMax) {
            ans += rightMax - height[right];
            right--;
        }
    }
    return ans;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap0(height) << endl;
    cout << trap1(height) << endl;
    cout << trap2(height);
    return 0;
}
