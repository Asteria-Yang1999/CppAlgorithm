#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> inDegree(n);
    vector<int> outDegree(n);
    for (auto &edge : trust) {
        outDegree[edge[0] - 1]++;
        inDegree[edge[1] - 1]++;
    }
    for (int i = 0; i < n; ++i) {
        if (outDegree[i] == 0 && inDegree[i] == n - 1) {
            return i + 1;
        }
    }
    return -1;

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
