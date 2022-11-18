#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int value) : value(value), next(nullptr) {}
};

Node* getLoopNode(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return nullptr;
    }
    Node* n1 = head->next;
    Node* n2 = head->next->next;
    while (n1 != n2) {
        if (n2->next == nullptr || n2->next->next == nullptr) {
            return nullptr;
        }
        n1 = n1->next;
        n2 = n2->next->next;
    }
    n2 = head;
    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}

Node* noLoop(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node* cur1 = head1;
    Node* cur2 = head2;
    int n = 0;
    while (cur1->next) {
        cur1 = cur1->next;
        n++;
    }
    while (cur2->next) {
        cur2 = cur2->next;
        n--;
    }
    cur1 = n > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1;
    n = abs(n);
    while (n != 0) {
        cur1 = cur1->next;
        n--;
    }
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2) {
    Node* cur1 = nullptr;
    Node* cur2 = nullptr;
    if (loop1 == loop2) {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2) {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) {
            cur1 = cur1->next;
            n--;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    } else {
        cur1 = loop1->next;
        while (cur1 != loop1) {
            if (cur1 != loop2) {
                return loop1;
            }
            cur1 = cur1->next;
        }
        return nullptr;
    }
}

Node* getIntersectNode(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node* loop1 = getLoopNode(head1);
    Node* loop2 = getLoopNode(head2);
    if (loop1 == nullptr && loop2 == nullptr) {
        return noLoop(head1, head2);
    }
    if (loop1 != nullptr && loop2 != nullptr) {
        return bothLoop(head1, loop1, head2, loop2);
    }
    return nullptr;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);

    Node* head2 = new Node(0);
    head2->next = new Node(9);
    head2->next->next = new Node(8);
    head2->next->next->next = head1->next->next->next->next->next;

    cout << getIntersectNode(head1, head2)->value << endl;

    return 0;
}
