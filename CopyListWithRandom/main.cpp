#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* rand;
    Node(int value) : value(value), next(nullptr), rand(nullptr) {};
};

Node* copyListWithRand1(Node* head) {
    if (head == nullptr) {
        return NULL;
    }
    unordered_map<Node*, Node*> map;
//    Node* newNode = new Node(0);
//    Node* curNew = newNode;
    Node* cur = head;
    while (cur != nullptr) {
//        curNew->next = new Node(cur->value);
//        map[cur] = curNew->next;
//
//        cur = cur->next;
//        curNew = curNew->next;
        Node* newNode = new Node(cur->value);
        map[cur] = newNode;
//        map.insert(pair<Node*, Node*>(cur, new Node(cur->value)));
        cur = cur->next;
    }
//    Node* newHead = map[head];
//    Node* newCur = newHead;
    cur = head;
    while (cur != nullptr) {
//        newCur->next = map[cur->next];
        map[cur]->next = map[cur->next];
        map[cur]->rand = map[cur->rand];
//        map.at(cur)->next = map.at(cur->next);
//        map.at(cur)->rand = map.at(cur->rand);
        cur = cur->next;
    }
    return map[head];
}

Node* copyListWithRand2(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* cur = head;
    Node* next = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = new Node(cur->value);
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    Node* curCopy = nullptr;
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != nullptr ? cur->rand->next : nullptr;
        cur = next;
    }
    Node* res = head->next;
    cur = head;
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next != nullptr ? next->next : nullptr;
        cur = next;
    }
    return res;
}

void printRandLinkedList(Node* head) {
    Node* cur = head;
    cout << "order: ";
    while (cur != nullptr) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
    cur = head;
    cout << "rand: ";
    while (cur != nullptr) {
        if (cur->rand) {
            cout << cur->rand->value << " ";
        } else {
            cout << "-" << " ";
        }
//        cout << (cur->rand == nullptr ? "-" : cur->rand->value) << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* res1 = nullptr;
    Node* res2 = nullptr;
/*    printRandLinkedList(head);
    res1 = copyListWithRand1(head);
    printRandLinkedList(res1);
    res2 = copyListWithRand2(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);
    System.out.println("=========================");*/

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head->rand = head->next->next->next->next->next; // 1 -> 6
    head->next->rand = head->next->next->next->next->next; // 2 -> 6
    head->next->next->rand = head->next->next->next->next; // 3 -> 5
    head->next->next->next->rand = head->next->next; // 4 -> 3
    head->next->next->next->next->rand = nullptr; // 5 -> null
    head->next->next->next->next->next->rand = head->next->next->next; // 6 -> 4

    printRandLinkedList(head);
    res1 = copyListWithRand1(head);
    res2 = copyListWithRand2(head);
    printRandLinkedList(res1);
    printRandLinkedList(res2);
    return 0;
}
