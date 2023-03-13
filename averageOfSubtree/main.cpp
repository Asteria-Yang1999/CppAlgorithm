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

int res = 0;
int cnt = 0;

int dfs(TreeNode* root) {
    if (root == nullptr) return 0;
    int cur = cnt;
    cnt++;
    int left = dfs(root->left);
    int right = dfs(root->right);
    int sum = root->val + left + right;
    if (sum / (cnt - cur) == root->val) {
        res++;
    }
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);
    cout << dfs(root) << endl;
    cout << res << endl;

    return 0;
}
