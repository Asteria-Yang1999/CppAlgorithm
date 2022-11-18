#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

void sortedArrDistanceLessK(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    int index = 0;
    for (; index <= min(arr.size(), k); ++index) {
        heap.push(arr[index]);
    }
    int i = 0;
    for (; index < arr.size(); ++i, ++index) {
        heap.push(arr[index]);
        arr[i] = heap.top();
        heap.pop();
    }
    while (!heap.empty()) {
        arr[i++] = heap.top();
        heap.pop();
    }
}

int main() {
//    priority_queue<int, vector<int>, greater<int>> heap;
//
//    heap.push(8);
//    heap.push(9);
//    heap.push(2);
//    heap.push(4);
//    heap.push(6);
//    heap.push(7);
//
//    while (!heap.empty()) {
//        cout << heap.top() << " ";
//        heap.pop();
//    }
//    cout << endl;
    vector<int> arr = {6,4,2,1,3,5,0};
    int k = 6;
    sortedArrDistanceLessK(arr, k);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
