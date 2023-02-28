#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;

string plusOne(string str, int i) {
    if (str[i] == '9') {
        str[i] = '0';
    } else str[i] += 1;
    return str;
}

string minusOne(string str, int i) {
    if (str[i] == '0') {
        str[i] = '9';
    } else str[i] -= 1;
    return str;
}


int openLock(vector<string>& deadends, string target) {
    set<string> dead;
    queue<string> que;
    set<string> visited;
    int res = 0;
    for (auto s : deadends) {
        dead.insert(s);
    }
    que.push("0000");
    visited.insert("0000");
    while (!que.empty()) {
        int sz = que.size();
        for (int i = 0; i < sz; ++i) {
            string cur = que.front();
            que.pop();
            if (dead.count(cur)) {
                continue;
            }
            if (cur == target) {
                return res;
            }
            for (int j = 0; j < 4; ++j) {
                string up = plusOne(cur, j);
                if (!visited.count(up)) {
                    visited.insert(up);
                    que.push(up);
                }
                string down = minusOne(cur, j);
                if (!visited.count(down)) {
                    visited.insert(down);
                    que.push(down);
                }
            }
        }
        res++;
    }
    return -1;
}

int openLock2(vector<string>& deadends, string target) {
    set<string> s1;
    set<string> s2;
    set<string> dead;
    set<string> visited;
    int res = 0;
    for (auto d : deadends) {
        dead.insert(d);
    }
    s1.insert("0000");
    s2.insert(target);
    while (!s1.empty() && !s2.empty()) {
        set<string> tmp;
        for (auto s : s1) {
            if (dead.count(s)) continue;
            if (s2.count(s)) return res;
            visited.insert(s);
            for (int j = 0; j < 4; ++j) {
                string up = plusOne(s, j);
                if (!visited.count(up)) {
                    // visited.insert(up);
                    tmp.insert(up);
                }

                string down = minusOne(s, j);
                if (!visited.count(down)) {
                    // visited.insert(down);
                    tmp.insert(down);
                }
            }
        }
        res++;
        s1 = s2;
        s2 = tmp;

    }
    return -1;
}

int main() {
    vector<string> deadends = {"8888"};
    string target = "0009";
    cout << openLock(deadends, target) << endl;
    cout << openLock2(deadends, target) << endl;
    return 0;
}
