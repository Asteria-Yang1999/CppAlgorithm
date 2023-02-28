#include <iostream>
#include <string>
#include <stack>

using namespace std;

int stringToInt(string str) {
    int n = 0;
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        n = 10 * n + (c - '0');
    }
    return n;
}

/*int caculate(string s) {
    stack<int> stk;
    char sign = '+';
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = 10 * num + (c - '0');
        }
        if (!isdigit(c) || i == s.size() - 1) {
            switch (sign) {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
            }
            sign = c;
            num = 0;
        }
    }
    int res = 0;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}*/

int caculate(deque<char>& dq) {
    stack<int> stk;
    char sign = '+';
    int num = 0;
    while (!dq.empty()) {
        char c = dq.front(); dq.pop_front();
        if (isdigit(c)) {
            num = 10 * num + (c - '0');
        }
        if (c == '(') {
            num = caculate(dq);
        }
        if ((!isdigit(c) && c != ' ') || dq.size() == 0) {
            int pre;
            switch (sign) {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * num);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / num);
                    break;
            }
            sign = c;
            num = 0;
        }
        if (c == ')') break;
    }
    int res = 0;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}

int caculate(string s) {
    deque<char> dq;
    for (auto n : s) {
        dq.push_back(n);
    }
    return caculate(dq);
}

int main() {
    cout << stoi("458") / 2 << endl;
    cout << stringToInt("458") / 3 << endl;

//    cout << caculate("2 - 3 * 4 + 5") << endl;

    cout << caculate("3 * (4 - 5 / 2) - 6") << endl;
    return 0;
}
