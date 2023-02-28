#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;

        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << binarySearch(nums, 5);
    return 0;
}
