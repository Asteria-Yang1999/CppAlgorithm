#include <iostream>
#include <vector>
using namespace std;

void backTrack(int left, int right, string &track, vector<string>& res) {
    if (left < 0 || right < 0) return;
    if (left > right) return;
    if (left == 0 && right == 0)  {
        res.push_back(track);
        return;
    }
    track.push_back('(');
    backTrack(left - 1, right, track, res);
    track.pop_back();

    track.push_back(')');
    backTrack(left, right - 1, track, res);
    track.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string track;
    backTrack(n, n, track, res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
