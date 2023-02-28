#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

void sort(vector<int> cakes, int n) {
    if (n == 1) return;
    int maxCake = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (cakes[i] > maxCake) {
            maxCake = cakes[i];
            maxIndex = i;
        }
    }
    reverse(cakes.begin(), cakes.begin() + maxIndex);
    res.push_back(maxIndex + 1);
    reverse(cakes.begin(), cakes.end() + n - 1);
    res.push_back(n);
    sort(cakes, n - 1);
}

vector<int> pancakeSort(vector<int>& cakes) {
    sort(cakes, cakes.size());
    return res;
}

int main() {
    vector<int> cakes = {3, 2, 4, 1};
    vector<int> res = pancakeSort(cakes);
    for (auto r : res) {
        cout << r << " ";
    }
    return 0;
}
