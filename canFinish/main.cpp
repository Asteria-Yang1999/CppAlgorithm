#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> visited;
vector<vector<int>> edges;
bool valid = true;
vector<int> in;


void dfs(int v) {
    visited[v] = 1;
    for (auto n : edges[v]) {
        if (visited[n] == 0) {
            dfs(n);
            if (!valid) return;
        } else if (visited[n] == 1) {
            valid = false;
            return;
        }
    }
    visited[v] = 2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    visited.resize(numCourses);
    edges.resize(numCourses);
    for (auto p : prerequisites) {
        edges[p[1]].push_back(p[0]);
    }
    for (int i = 0; i < numCourses; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return valid;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    in.resize(numCourses);
    for (auto p : prerequisites) {
        edges[p[1]].push_back(p[0]);
        in[p[0]]++;
    }
    vector<int> res;
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        res.push_back(cur);
        for (auto c : edges[cur]) {
            in[c]--;
            if (in[c] == 0) {
                q.push(c);
            }
        }
    }

    if (res.size() == numCourses) {
        return res;
    }
    return {};

}

int main() {
    int numCourses = 2;
    vector<vector<int>> pre = {{1, 0}, {0, 1}};
    cout << canFinish(numCourses, pre) << endl;
    return 0;
}
