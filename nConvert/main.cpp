#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows < 2) return s;
    vector<string> path(numRows);
    int i = 0, flag = -1;
    for (auto ch : s) {
        path[i] += ch;
        if (i == 0 || i == numRows - 1) flag = -flag;
        i += flag;
    }
    string res;
    for (auto p : path) {
        res += p;
    }
    return res;
}

int main() {
    string s = "PAYPALISHIRING";
    cout << convert(s, 3);
    return 0;
}
