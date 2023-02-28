#include <iostream>
#include <string>
using namespace std;

void cheers1(int n) {
    if (n <= 1) {
        cout << "Hurrah" << " ";

    } else {
        cheers1(n - 1);
        cout << "Hip" << " ";
    }
}

void cheers2(int n) {
    if (n <= 1) {
        cout << "Hurrah" << " ";
    } else {
        cout << "Hip" << " ";
        cheers2(n - 1);
        cout << "Hip" << " ";
    }
}

void cheers3(int n) {
    if (n <= 1) {
        cout << "Hurrah" << " ";
    } else {
        if (n % 2 == 0) cout << "Hip" << " ";
        cheers3(n - 1);
        if (n % 2 == 1) cout << "Hip" << " ";
    }
}

void star(int n) {
    cout << "*" << endl;
    if (n > 1) star(n - 1);
    cout << "!" << endl;
}

int main() {
    cheers1(3);
    cout << endl;
    cheers2(3);
    cout << endl;
    cheers3(4);
    cout << endl;
    star(3);
    return 0;
}
