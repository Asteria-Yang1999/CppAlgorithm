#include <iostream>
#include <vector>
#include <string>

using namespace std;

void input1dimN() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void input1dim() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.emplace_back(num);
        if (getchar() == '\n') {
            break;
        }
    }

    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void input2dimMN() {
    int m;
    int n;

    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (auto &v : matrix) {
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
}

void input2dimDotMN() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;

        vector<int> vec;
        int start = 0;
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ',') {
                string temp = s.substr(start, i - start);
                vec.push_back(stoi(temp));
                num++;
                start = i + 1;
            }
            if (num == n - 1) {
                string temp = s.substr(start, s.size() - start);
                vec.push_back(stoi(temp));
                break;
            }
        }
        matrix[i] = vec;
        vec.clear();
    }

    for (auto &v : matrix) {
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
}

void inputStringsN() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    for (auto s : strings) {
        cout << s << " ";
    }
    cout << endl;
}

void inputStrings() {
    vector<string> strings;
    string s;
    while (cin >> s) {
        strings.push_back(s);
        if (getchar() == '\n') {
            break;
        }
    }

    for (auto s : strings) {
        cout << s << " ";
    }
    cout << endl;
}

void inputStringToInteger() {
    vector<int> vec;
    string s;
    cin >> s;

    int start = 0;
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ',') {
            string tmp = s.substr(start, i - start);
            vec.push_back(stoi(tmp));
            num++;
            start = i + 1;
        }
        if (i == s.size() - 1) {
            string tmp = s.substr(start, s.size() - start);
            vec.push_back(stoi(tmp));
        }
    }

    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    //固定数目的数组输入
//    input1dimN();

    //不固定数目的数组输入
//    input1dim();

    //固定数目的二维数组输入
//    input2dimMN();

//    input2dimDotMN();

//    inputStringsN();
//    inputStrings();

    inputStringToInteger();
    return 0;
}

