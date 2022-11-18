#include <iostream>
using namespace std;

struct DoubleNode {
	int val;
	DoubleNode *last;
	DoubleNode *next;
    DoubleNode() : val(0), last(nullptr), next(nullptr) {}
    DoubleNode(int x) : val(x), last(nullptr), next(nullptr) {}
    DoubleNode(int x, DoubleNode *last, DoubleNode *next) :
		val(x), last(last), next(next) {}
};

DoubleNode* reverseList(DoubleNode* head) {
    DoubleNode* prev = nullptr;
    DoubleNode* next = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = prev;
        head->last = next;
        prev = head;
        head = next;
    }
    return prev;
}

void printDoubleLinkedList(DoubleNode* head) {
    cout << "Double Linked List: " << endl;
    DoubleNode* end = nullptr;
    while (head != nullptr) {
        cout << head->val << " ";
        end = head;
        head = head->next;
    }
//    cout << "| ";
//    while (end != nullptr) {
//        cout << end->val << " ";
//        end = end->last;
//    }
    cout << endl;
}

int main() {
    DoubleNode* node1 = new DoubleNode(3);
    node1->next = new DoubleNode(5);
    node1->next->last = node1;
    node1->next->next = new DoubleNode(6);
    node1->next->next->last = node1->next;
    node1->next->next->next = new DoubleNode(7);
    node1->next->next->next->last = node1->next->next;
//    cout << node1->val << " ";
//    cout << node1->next->val << " ";
//    cout << node1->next->next->val << " ";
//    cout << endl;
    DoubleNode* node2 = reverseList(node1);
    printDoubleLinkedList(node2);
    return 0;
}
