#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void preOrderUnRecur(Node* head) {
    if (head != nullptr) {
        stack<Node*> stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            cout << head->value << " ";
            if (head->right) {
                stack.push(head->right);
            }
            if (head->left) {
                stack.push(head->left);
            }
        }
    }
    cout << endl;
}

void inOrderUnRecur(Node* head) {
    if (head != nullptr) {
        stack<Node*> stack;
        while (!stack.empty() || head != nullptr) {
            if (head != nullptr) {
                stack.push(head);
                head = head->left;
            } else {
                head = stack.top();
                stack.pop();
                cout << head->value << " ";
                head = head->right;
            }
        }
    }
    cout << endl;
}

void posOrderUnRecur(Node* head) {
    if (head != nullptr) {
        queue<Node*> queue;
        stack<Node*> s;
        stack<Node*> res;
        s.push(head);
        while (!s.empty()) {
            head = s.top();
            s.pop();
            res.push(head);
            if (head->left) {
                s.push(head->left);
            }
            if (head->right) {
                s.push(head->right);
            }
        }
        while (!res.empty()) {
            cout << res.top()->value << " ";
            res.pop();
        }
        cout << endl;
    }
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
    cout << "pre-order: " ;
    preOrderUnRecur(head);
    cout << endl;
    cout << "in-order: ";
    inOrderUnRecur(head);
    cout << endl;
    cout << "pos-order: ";
    posOrderUnRecur(head);
    cout << endl;

    return 0;
}
