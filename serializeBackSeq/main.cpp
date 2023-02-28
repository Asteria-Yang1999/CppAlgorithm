#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
private:
    string res = "";

    void traversal(TreeNode* root) {
        if (root == nullptr) {
            res += "#,";
            return;
        }
        traversal(root->left);
        traversal(root->right);
        res += (to_string(root->val) + ",");
    }
public:
    stack<string> split(string& str) {
        stack<string> ans;
        if (str.empty()) return ans;
        int size = str.size();
        int pre = 0;
        for (int i = 0; i <= size; ++i) {
            if (i == size || str[i] == ',') {
                ans.emplace(str.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        return ans;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traversal(root);
        res.pop_back();
        return res;
//        if (root == nullptr) {
//            return "#";
//        }
//        string left = serialize(root->left);
//        string right = serialize(root->right);
//        return left + " " + right + " " + to_string(root->val);
//        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    TreeNode* deserialize(stack<string> data) {
        if (data.empty()) return nullptr;
        string tmp = data.top();
        data.pop();
        if (tmp == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(tmp));
        root->right = deserialize(data);
        root->left = deserialize(data);
        return root;
    }

    // Decodes your encoded data to tree.



    TreeNode* deserialize(string data) {
        stack<string> st = split(data);
        return deserialize(st);
    }
};

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(50);
    Codec c1;
    cout << c1.serialize(root) << endl;
    string s = "#,#,3,#,#,4,1,#,#,50,#,2,0";
    stack<string> que = c1.split(s);
    return 0;
}
