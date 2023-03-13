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

TreeNode* newRoot = new TreeNode(-1);
TreeNode* head = newRoot;
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    TreeNode* cur = new TreeNode(root->val);
    newRoot->right = cur;
    newRoot->left = nullptr;
    newRoot = cur;
    inorder(root->right);
}


TreeNode* increasingBST(TreeNode* root) {
    inorder(root);
    return head->right;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);

    cout << increasingBST(root)->val << endl;

    return 0;
}
