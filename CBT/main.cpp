#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode* root) {
    TreeNode* l = root, *r = root;
    int hr = 0, hl = 0;
    while (l) {
        hl++;
        l = l->left;
    }
    while (r) {
        hr++;
        r = r->right;
    }
    if (hr == hl) return pow(2, hl) - 1;
    else return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    cout << countNodes(root);
    return 0;
}
