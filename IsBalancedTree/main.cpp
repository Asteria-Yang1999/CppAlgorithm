//该代码在clion中运行会有栈溢出的问题，待解决。
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int data) : value(data) {}
};

struct ReturnType {
    int height;
    bool isB;
    ReturnType(bool isB, int hei) : isB(isB), height(hei) {}
};

ReturnType process(Node* head) {
    if (head == nullptr) {
        return ReturnType(true, 0);
    }

    ReturnType leftData = process(head->left);
    ReturnType rightData = process(head->right);
    int height = max(leftData.height, rightData.height);
    bool isBalanced = leftData.isB && rightData.isB && abs(leftData.height - rightData.height) < 2;
    return ReturnType(isBalanced, height);
}

bool isBalanced(Node* head) {
    return process(head).isB;
}

int main() {
    Node* head = new Node(5);
    head->left = new Node(3);
    head->right = new Node(8);
    head->left->left = new Node(2);
    head->left->right = new Node(4);
    head->left->left->left = new Node(1);
    head->right->left = new Node(7);
    head->right->left->left = new Node(6);
    head->right->right = new Node(10);
    head->right->right->left = new Node(9);
    head->right->right->right = new Node(11);
    if (isBalanced(head)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}


