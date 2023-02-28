#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverseArray(vec);
    for (auto v : vec) {
        cout << v << endl;
    }
    return 0;
}
