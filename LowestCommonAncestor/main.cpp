#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v) {}
};

//class setMotherMap {
//public:
//    unordered_map<Node*, Node*> m;
//
//    setMotherMap(Node* head) {
//        if (head != nullptr) {
//            m[head] = nullptr;
//        }
//        setMap(head);
//    }
//
//    void setMap(Node* head) {
//        if (head == nullptr) {
//            return;
//        }
//        if (head->left != nullptr) {
//            m[head->left] = head;
//        }
//        if (head->right != nullptr) {
//            m[head->right] = head;
//        }
//        setMap(head->left);
//        setMap(head->right);
//    }
//
//    Node* query(Node* o1, Node* o2) {
//        unordered_set<Node*> path;
//        while (m[o1]) {
//            path.insert(o1);
//            o1 = m[o1];
//        }
//        while (path.find(o2) == 0) {
//            o2 = m[o2];
//        }
//        return o2;
//    }
//};
void process(Node* head, unordered_map<Node*, Node*>& motherMap) {
    if (head == nullptr) {
        return;
    }
    motherMap[head->left] = head;
    motherMap[head->right] = head;
    process(head->left, motherMap);
    process(head->right, motherMap);
}


Node* lca(Node* head, Node* o1, Node* o2) {
    unordered_map<Node*, Node*> motherMap;
    motherMap[head] = head;
    process(head, motherMap);
    unordered_set<Node*> set1;
    Node* cur = o1;
    while (cur != motherMap[cur]) {
        set1.insert(cur);
        cur = motherMap[cur];
    }
    set1.insert(head);

    cur = o2;
    while (cur != motherMap[cur]) {
        if (set1.count(cur) != 0) {
            return cur;
        }
        cur = motherMap[cur];
    }
    return nullptr;
}

Node* lowestAncestor(Node* head, Node* o1, Node* o2) {
    if (head == nullptr || head == o1 || head == o2) {
        return head;
    }
    Node* left = lowestAncestor(head->left, o1, o2);
    Node* right = lowestAncestor(head->right, o1, o2);
    if (left != nullptr && right != nullptr) {
        return head;
    }
    return left != nullptr ? left : right;
}


int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->right->right->left = new Node(8);

    Node* o1 = head->left->right;
    Node* o2 = head->right->left;
    cout << "ancestor: " << lca(head, o1, o2)->value << endl;
    return 0;
}
