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

bool isInBST(TreeNode* root, int target) {
    if (root == nullptr) return true;
    if (root->val == target) return true;
    return isInBST(root->left, target) || isInBST(root->right, target);
}

bool isInBST2(TreeNode* root, int target) {
    if (root == nullptr) return true;
    if (root->val == target) return true;
    if (root->val > target) return isInBST2(root->left, target);
    if (root->val < target) return isInBST2(root->right, target);

}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (root->val == val) return root;
    if (root->val > val) root->left = insertIntoBST(root->left, val);
    if (root->val < val) root->right = insertIntoBST(root->right, val);
}

TreeNode* getMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root->val == key) {
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        if (root->left != nullptr && root->right != nullptr) {
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
    } else if (root->val > key) {
        root->left = deleteNode(root, key);
    } else if (root->val < key) {
        root->right = deleteNode(root, key);
    }
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
