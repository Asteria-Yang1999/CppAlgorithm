#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int count(TreeNode* head) {
    if (head == nullptr) return 0;
    return count(head->left) + count(head->right) + 1;
}

int depth(TreeNode* head) {
    if (head == nullptr) return -1;
    return max(depth(head->left), depth(head->right)) + 1;
}

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    cout << count(root) << endl;
    cout << depth(root) << endl;
    return 0;
}
