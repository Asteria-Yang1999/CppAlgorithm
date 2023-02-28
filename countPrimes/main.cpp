#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes0(int n) {
    int res = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) {
            res++;
        }
    }
    return res;
}

int countPrimes(int n) {
    vector<bool> prime(n - 1, true);
    for (int i = 2; i * i < n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }

    }
    int res = 0;
    for (auto p : prime) {
        if (p) res++;
    }
    return res - 2;

}

int main() {
    cout << countPrimes(10);
    return 0;
}
