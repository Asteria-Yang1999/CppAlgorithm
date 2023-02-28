#include <iostream>
using namespace std;

int countBits(int num) {
    if (abs(num) < 10) return 1;
    else return 1 + countBits(num / 10);
}

double pow(double x, int n) {
    if (x == 0 && n <= 0) {
        return INT_MIN;
    }
    else if (x == 0) return 0;
    else if (n == 0) return 1;
    else if (n > 0 && (n % 2 == 0)) {
        double tmp = pow(x, n / 2);
        return tmp * tmp;
    }
    else if (n > 0 && (n % 2 == 1)) return pow(x, n - 1) * x;
    else return 1 / pow(x, -n);
}

int main() {
    cout << countBits(3450) << endl;
    cout << pow(5.2, -3);
    return 0;
}
