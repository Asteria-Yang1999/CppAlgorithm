#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0, len = INT_MAX;
    int start = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        while (valid == need.size()) {
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
}

bool checkInclusion(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        while (right - left >= t.size()) {
            if (valid == need.size()) {
                return true;
            }
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int res = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        window[c]++;
        while (window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }
        res = max(res, right - left);
    }
    return res;
}

int main() {
    string s = "eidbaooo";
    string t = "ab";
    string r = "pwwkew";
    cout << minWindow(s, t) << endl;
    cout << checkInclusion(s, t) << endl;
    cout << lengthOfLongestSubstring(r) << endl;
    return 0;
}
