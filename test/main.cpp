#include <iostream>
#include <vector>
using namespace std;

//template<class T>
//int getSize(T & arr) {
//    return (sizeof(arr) / sizeof(arr[0]));
//}

void printOddTimesNum(vector<int>& num) {
    int eor = 0;
    int n = num.size();
    for (int i = 0; i < n; i++) {
        eor ^= num[i];
    }
    int rightOne = eor & (~eor + 1);        //提取出最右的1

    int onlyOne = 0;        //eor'
    for (int i = 0; i < n; i++) {
        if ((num[i] & rightOne) == 1) {
            onlyOne ^= num[i];
        }
    }
    cout << onlyOne << " and " << (eor ^ onlyOne) << endl;
}

int main() {
    vector<int> arr = {3, 3, 4, 4, 5, 6};
    printOddTimesNum(arr);
    return 0;
}
