#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int intervalSchedule0(vector<vector<int>>& intvs) {
    sort(intvs.begin(), intvs.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    int res = 1;
    int pre = 0;
    for (int i = 1; i < intvs.size(); ++i) {
        if (intvs[i][0] >= intvs[pre][1]) {
            pre = i;
            res++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> intvs = {{1, 3}, {2, 4}, {3, 6}};
    cout << intervalSchedule0(intvs);
    return 0;
}
