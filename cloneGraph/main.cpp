#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* bfs(Node* node) {
    if (node == nullptr) return node;
    queue<Node*> que;
    que.push(node);
    unordered_map<Node*, Node*> visited;
    visited[node] = new Node(node->val);

    while (!que.empty()) {
        Node* cur = que.front(); que.pop();
        for (auto neighbor : cur->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited[neighbor] = new Node(neighbor->val);
                que.push(neighbor);
            }
            visited[cur]->neighbors.push_back(visited[neighbor]);
        }
    }

    return visited[node];
}

unordered_map<Node*, Node*> memo;

Node* dfs(Node* node) {
    if (node == nullptr) return node;

    if (memo.find(node) != memo.end()) {
        return memo[node];
    }

    Node* cloneNode = new Node(node->val);
    memo[node] = cloneNode;

    for (auto neighbor : node->neighbors) {
        cloneNode->neighbors.push_back(dfs(neighbor));
    }

    return cloneNode;
}

int main() {

    return 0;
}
