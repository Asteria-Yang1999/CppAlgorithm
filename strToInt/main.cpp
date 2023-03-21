#include <iostream>
using namespace std;

int strToInt(string str) {
    bool isNeg = false;
    int start = 0;
    int res = 0;
    for (int i = 0; i < str.size() && str[i] == ' '; ++i) {
        start++;
    }
    string newStr = string(str.begin() + start, str.end());

    if (newStr[0] == '-') {
        isNeg = true;
        newStr.erase(newStr.begin());
    } else if (newStr[0] == '+') {
        newStr.erase(newStr.begin());
    } else if (newStr[0] >= 'a' && newStr[0] <= 'z') {
        return 0;
    }

    for (int i = 0; i < newStr.size(); ++i) {
        if (newStr[i] >= '0' && newStr[i] <= '9' && res <= INT_MAX) {
            res = res * 10 + (newStr[i] - '0');
        } else if (newStr[i] >= '0' && newStr[i] <= '9' && res > INT_MAX) {
            res = INT_MAX;
            break;
        }
    }
    if (isNeg) return -res;
    return res;
}

int main() {
    string test = "42";
    cout << strToInt(test);
    return 0;
}
