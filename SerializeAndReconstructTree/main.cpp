#include <iostream>
#include <queue>
#include <list>
#include <string.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int data) : value(data) {}
};

//string operator+(string& s1, string& s2) {
//    string res = s1.append(s2);
//    return res;
//}

string serialByPre(Node* head) {
    if (!head) {
        return "#!";
    }
    string res = to_string(head->value) + "!";
    res += serialByPre(head->left);
    res += serialByPre(head->right);
    return res;
}

//Node* reconByPreString(string preStr) {
//    string values = preStr.
//}

string serial(Node* head) {
    if (!head) {
        return "#";
    }
    string res;
    queue<Node*> nodeQueue;
    Node* cur = nullptr;
    int isValid = false;
    int size = 0;
    nodeQueue.push(head);
    while (!nodeQueue.empty()) {
        size = nodeQueue.size();
        for (int i = 0; i < size; ++i) {
            cur = nodeQueue.front();
            nodeQueue.pop();
            if (!cur) {
                res.append("#,");
                continue;
            }
            res.append(to_string(cur->value) + ",");
            nodeQueue.push(cur->left);
            nodeQueue.push(cur->right);
        }
    }
    return res;
}

void toStrArr(const string& data, vector<string>& valsStr) {
    string valStr;
    valStr.reserve(10);
    for (const char& ch : data) {
        if (ch == ',') {
            valsStr.push_back(valStr);
            valStr.clear();
        } else {
            valStr.push_back(ch);
        }
    }
}

Node* deserialize(string data) {
    if (!data.compare("#")) {
        return nullptr;
    }
    vector<string> valsStr;
    toStrArr(data, valsStr);
    int size = valsStr.size();
    Node* head = new Node(stod(valsStr[0]));
    Node* mother = nullptr;
    queue<Node*> nodeQueue;
    nodeQueue.push(head);

    for (int i = 0; i < size; ++i) {
        mother = nodeQueue.front();
        nodeQueue.pop();
        if (valsStr[i].compare("#")) {
            mother->left = new Node(stod(valsStr[i]));
            nodeQueue.push(mother->left);
        }
        if (valsStr[++i].compare("#")) {
            mother->right = new Node(stod(valsStr[i]));
            nodeQueue.push(mother->right);
        }
    }
    return head;
}

int main() {
    Node* head = new Node(5);
    head->left = new Node(3);
    head->right = new Node(8);
    head->left->left = new Node(2);
    head->left->right = new Node(4);
    head->left->left->left = new Node(1);
    head->right->left = new Node(7);
    head->right->left->left = new Node(6);
    head->right->right = new Node(10);
    head->right->right->left = new Node(9);
    head->right->right->right = new Node(11);
//    string result = serial(head);
    string result0 = serialByPre(head);
    cout << result0 << endl;
    return 0;
}
