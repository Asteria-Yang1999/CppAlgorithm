#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& num, int L, int M, int R) {
    int help[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    int res = 0;
    while (p1 <= M && p2 <= R) {
        res += num[p1] < num[p2] ? (R - p2 + 1) * num[p1] : 0;
        help[i++] = num[p1] < num[p2] ? num[p1++] : num[p2++];
    }
    while (p1 <= M) {
        help[i++] = num[p1++];
    }
    while (p2 <= R) {
        help[i++] = num[p2++];
    }
    for (int i = 0; i < R - L + 1; ++i) {
        num[L + i] = help[i];
    }
    return res;
}

int process(vector<int>& num, int L, int R) {
    if (L == R) {
        return 0;
    }
    int mid = L + ((R - L) >> 1);
    return process(num, L, mid) + process(num, mid + 1, R) + merge(num, L, mid, R);
}

int smallSum(vector<int>& num) {
    if (num.size() < 2) {
        return 0;
    }
    return process(num, 0, num.size() - 1);
}


int main() {
    vector<int> num = {1, 3, 4, 2, 5};
    int res = smallSum(num);
    cout << res << endl;
    return 0;
}
