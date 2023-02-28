#include <iostream>
using namespace std;

class Base {
private:
    int a;
public:
    Base();
    Base(int a) {
        this->a = a;
    }
    Base(Base const &c_a) {
        this->a = c_a.getA();
    }
    int getA() const {
        return a;
    }

};


int main() {
    Base A = Base(3);
    Base B = A;
    cout << A.getA() << endl;
    return 0;
}
