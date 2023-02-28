#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Codec {
//private:
//    string SEP = " ";
//    string EMPTY = "#";
//    string res = "";
//
//    TreeNode* change(istringstream &ss) {
//        string tmp;
//        ss >> tmp;
//        while (tmp == "#") return nullptr;
//        TreeNode* root = new TreeNode(stoi(tmp));
//        root->left = change(ss);
//        root->right = change(ss);
//        return root;
//    }
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        if (root == nullptr) {
//            return EMPTY;
//        }
//        string left = serialize(root->left);
//        string right = serialize(root->right);
//        return to_string(root->val) + SEP + left + SEP + right;
////        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        string &res = data;
//        reverse(res.begin(), res.end());
//        istringstream ss(res);
//        return change(ss);
//    }
//};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur == nullptr) {
                res.append("#").append(" ");
                continue;
            }
            res.append(to_string(cur->val)).append(" ");
            que.push(cur->left);
            que.push(cur->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    queue<string> split(string data) {
        queue<string> res;
        int pos = data.find(" ");
        while (pos != data.npos)
        {
            string temp = data.substr(0, pos);
            res.emplace(temp);
            //去掉已分割的字符串,在剩下的字符串中进行分割
            data = data.substr(pos + 1, data.size() - pos - 1);
            pos = data.find(" ");
        }
        return res;
    }

    TreeNode* deserialize(queue<string>& data) {
        if (data.empty()) return nullptr;
        string tmp = data.front();
        data.pop();
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> que;
        que.push(root);
        while (!data.empty()) {
            TreeNode* parent = que.front();
            que.pop();
            string left = data.front();
            data.pop();
            if (left != "#") {
                parent->left = new TreeNode(stoi(left));
                que.push(parent->left);
            } else {
                parent->left = nullptr;
            }
            string right = data.front();
            data.pop();
            if (right != "#") {
                parent->right = new TreeNode(stoi(right));
                que.push(parent->right);
            } else {
                parent->right = nullptr;
            }
        }
        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> res = split(data);
        return deserialize(res);
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
    queue<string> res = c1.split(c1.serialize(root));
    while (!res.empty()) {
        cout << res.front() << endl;
        res.pop();
    }
    return 0;
}
