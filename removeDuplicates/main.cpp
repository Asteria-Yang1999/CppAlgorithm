#include <iostream>
#include <vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr){}
    ListNode(int val, ListNode* next) :val(val), next(next){}
};

int removeDuplicates(vector<int>& nums) {
    int slow = 0, fast = 1;
    while (fast < nums.size()) {
        if (nums[slow] != nums[fast]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}


ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode *slow = head, *fast = head->next;
    while (fast != nullptr) {
        if (slow->val != fast->val) {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = nullptr;
    return head;
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 4, 4, 5, 6};
    cout << removeDuplicates(nums) << endl;

    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(5);

    ListNode* res = deleteDuplicates(root);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
