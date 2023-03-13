#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//void swap(vector<int>& arr, int L, int R) {
//    int tmp = arr[L];
//    arr[L] = arr[R];
//    arr[R] = tmp;
//}
//
//vector<int> partition(vector<int>& arr, int L, int R) {
//    int less = L - 1;
//    int more = R;
//    while (L < more) {
//        if (arr[L] < arr[R]) {
//            swap(arr, ++less, L++);
//        } else if (arr[L] > arr[R]) {
//            swap(arr, --more, L);
//        } else {
//            L++;
//        }
//    }
//    swap(arr, more, R);
//    return {less + 1, more};
//}
//
//void quickSort(vector<int>& arr, int L, int R) {
//    if (L < R) {
//        swap(arr, L + (rand() % (R - L + 1)), R);
//        vector<int> p = partition(arr, L, R);
//        quickSort(arr, L, p[0] - 1);
//        quickSort(arr, p[1] + 1, R);
//    }
//}

void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int partition(vector<int>& nums, int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[i] < nums[left]) {
            ++i;
        }
        while (i < j && nums[j] > nums[left]) {
            --j;
        }
        swap(nums, i, j);
    }
    swap(nums, i, left);
    return i;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

int main() {
    vector<int> arr = {1, 52, 23, 65, 48, 56};
    quickSort(arr, 0, 5);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
