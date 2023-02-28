#include <iostream>
#include <string>
using namespace std;

void printNext(int* next) {
//    while (*next) {
//        cout << *(next++) << " ";
//    }
//    cout << endl;
    for (int i = 0; i < 12; ++i) {
        cout << next[i] << " ";
    }
    cout << endl;
}

void getNext (int* next, const string& s){
    next[0] = 0;
    int j = 0;
    for(int i = 1;i < s.size(); i++){
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
        printNext(next);
    }
}
bool repeatedSubstringPattern (string s) {
    if (s.size() == 0) {
        return false;
    }
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
        return true;
    }
    return false;
}


int main() {
    string s = "asdfasdfasdf";
    bool res = repeatedSubstringPattern(s);
    cout << res << endl;
    return 0;
}
