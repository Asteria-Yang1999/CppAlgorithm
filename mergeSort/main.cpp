#include <iostream>
#include <vector>
using namespace std;

//void merge(vector<int>& num, int L, int M, int R) {
//    int help[R - L + 1];
//    int i = 0;
//    int p1 = L;
//    int p2 = M + 1;
//    while (p1 <= M && p2 <= R) {
//        help[i++] = num[p1] <= num[p2] ? num[p1++] : num[p2++];
//    }
//    while (p1 <= M) {
//        help[i++] = num[p1++];
//    }
//    while (p2 <= R) {
//        help[i++] = num[p2++];
//    }
//    for (int i = 0; i < R - L + 1; ++i) {
//        num[L + i] = help[i];
//    }
//}
//
//void process(vector<int>& num, int L, int R) {
//    if (L == R) {
//        return;
//    }
//    int mid = L + ((R - L) >> 1);
//    process(num, L, mid);
//    process(num, mid + 1, R);
//    merge(num, L, mid, R);
//}
//
//void mergeSort(vector<int>& num) {
//    if (num.size() < 2) {
//        return;
//    }
//    process(num, 0, num.size() - 1);
//}

void merge(vector<int>& nums, int left, int mid, int right) {
    // 通过新建一个数组来在原数组上进行归并操作
    vector<int> tmp(nums.begin() + left, nums.begin() + right + 1);
    int leftStart = left - left, leftEnd = mid - left;
    int rightStart = mid + 1 - left, rightEnd = right - left;

    int i = leftStart, j = rightStart;
    for (int k = left; k <= right; ++k) {
        if (i > leftEnd) {
            nums[k] = tmp[j++];
        } else if (j > rightEnd || tmp[i] <= tmp[j]) {
            nums[k] = tmp[i++];
        } else {
            nums[k] = tmp[j++];
        }
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main() {
    vector<int> nums = {5, 6, 98, 65, 15, 35, 45};
    mergeSort(nums, 0, 6);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
