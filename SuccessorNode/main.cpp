#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data): value(data){}
};

Node* getLeftMost(Node* node) {
    if (!node) {
        return node;
    }
    while (!node->left) {
        node = node->left;
    }
    return node;
}

Node* getSuccessorNode(Node* node) {
    if (!node) {
        return node;
    }
    if (!node->right) {
        return getLeftMost(node->right);
    } else {
        Node* parent = node->parent;
        while (parent != nullptr && parent->left != node) {
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}

int main() {
    Node* head = new Node(6);
    head->parent = nullptr;
    head->left = new Node(3);
    head->left->parent = head;
    head->left->left = new Node(1);
    head->left->left->parent = head->left;
    head->left->left->right = new Node(2);
    head->left->left->right->parent = head->left->left;
    head->left->right = new Node(4);
    head->left->right->parent = head->left;
    head->left->right->right = new Node(5);
    head->left->right->right->parent = head->left->right;
    head->right = new Node(9);
    head->right->parent = head;
    head->right->left = new Node(8);
    head->right->left->parent = head->right;
    head->right->left->left = new Node(7);
    head->right->left->left->parent = head->right->left;
    head->right->right = new Node(10);
    head->right->right->parent = head->right;

    Node* test = head->left->left;
    cout << test->value << " NEXT: " << getSuccessorNode(test)->value << endl;

    return 0;
}
