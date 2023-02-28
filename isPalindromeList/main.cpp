#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//1, 使用快慢指针确定链表中间节点的位置

//2, 反转中间节点以后的链表部分

//3, 对反转后的部分和从头节点出发的部分进行比较

//4, 比较完毕，将链表反转的部分复原
ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* next;
    ListNode* cur = head;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head, *fast = head;
//    ListNode* p , *q;
    while (fast != nullptr && fast->next != nullptr) {
//        p = slow;
//        q = fast;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != nullptr) {
//        p = slow;
        slow = slow->next;
    }
    ListNode* left = head;
    ListNode* right = reverse(slow);

    while (right != nullptr) {
        if (right->val != left->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
//    p->next = reverse(p);
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
