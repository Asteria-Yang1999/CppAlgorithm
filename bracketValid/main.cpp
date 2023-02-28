#include <iostream>
#include <stack>
using namespace std;

char rightOf(char ch) {
    if (ch == '(') return ')';
    if (ch == '[') return ']';
    return '}';
}

bool isValid(string str) {
    stack<char> s;
    for (auto ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(rightOf(ch));
        } else {
            if (!s.empty() && ch == s.top()) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {

    return 0;
}
