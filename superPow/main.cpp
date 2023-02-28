#include <iostream>
#include <vector>

using namespace std;

int base = 1337;

int myPow0(int a, int k) {
    a %= base;
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res *= a;
        res %= base;
    }
    return res;
}

int myPow(int a, int k) {
    if (k == 0) return 1;
    a %= base;
    if (k % 2 == 1) {
        return (a * myPow(a, k - 1)) % base;
    }
    else {
        int pre = myPow(a, k / 2);
        return (pre * pre) % base;
    }
}

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();
    int part1 = myPow(a, last);
    int part2 = myPow(superPow(a, b), 10);
    return part1 * part2 % base;
}

int main() {
    vector<int> b = {1, 2};
    cout << superPow(2, b);
    return 0;
}
