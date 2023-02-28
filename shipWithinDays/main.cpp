#include <iostream>
#include <vector>

using namespace std;

bool canFinish(vector<int> &weights, int cap, int D) {
    int i = 0;
    for (int day = 0; day < D; ++day) {
        int maxCap = cap;
        while ((maxCap -= weights[i]) >= 0) {
            i++;
            if (i == weights.size()) {
                return true;
            }
        }
    }
    return false;
}

int getMax(vector<int> weights) {
    int res = 0;
    for (int w : weights) {
        if (res < w) {
            res = w;
        }
    }
    return res;
}

int getSum(vector<int> weights) {
    int res = 0;
    for (int w : weights) {
        res += w;
    }
    return res;
}

int shipWithinDays(vector<int> &weights, int D) {
    int left = getMax(weights), right = getSum(weights) + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canFinish(weights, mid, D)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipWithinDays(weights, 5);
    return 0;
}
