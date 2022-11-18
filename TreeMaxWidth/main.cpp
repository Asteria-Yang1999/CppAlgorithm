#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int getMaxWidth(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    int maxWidth = 0;
    int curWidth = 0;
    int curLevel = 0;
    unordered_map<Node*, int> levelMap;
    levelMap[head] = 1;
    queue<Node*> q;
    q.push(head);
    Node* node = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        left = node->left;
        right = node->right;
        if (left != nullptr) {
            levelMap[left] = levelMap[node] + 1;
            q.push(left);
        }
        if (right != nullptr) {
            levelMap[right] = levelMap[node] + 1;
            q.push(right);
        }
        if (levelMap[node] > curLevel) {
            curWidth = 0;
            curLevel = levelMap[node];
        } else {
            curWidth++;
        }
        maxWidth = max(maxWidth, curWidth);
    }
    return maxWidth;
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

    cout << getMaxWidth(head) << endl;

    return 0;
}
