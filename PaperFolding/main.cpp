#include <iostream>
using namespace std;

void printProcess(int i, int N, bool down) {
    if (i > N) {
        return;
    }
    printProcess(i + 1, N, true);
    string res = down ? "down" : "up";
    cout << res << endl;
    printProcess(i + 1, N, false);
}

void printAllFolds(int N) {
    printProcess(1, N, true);
}

int main() {
    int N = 3;
    printAllFolds(3);
    return 0;
}
