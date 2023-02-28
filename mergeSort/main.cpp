#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& num, int L, int M, int R) {
    int help[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        help[i++] = num[p1] <= num[p2] ? num[p1++] : num[p2++];
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
}

void process(vector<int>& num, int L, int R) {
    if (L == R) {
        return;
    }
    int mid = L + ((R - L) >> 1);
    process(num, L, mid);
    process(num, mid + 1, R);
    merge(num, L, mid, R);
}

void mergeSort(vector<int>& num) {
    if (num.size() < 2) {
        return;
    }
    process(num, 0, num.size() - 1);
}

int main() {
    vector<int> num = {5, 6, 98, 65, 15, 35, 45};
    mergeSort(num);
    for (int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
