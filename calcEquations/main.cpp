#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int dfs(unordered_map<string, pair<string, double>> edges, string start, string end, int n) {
    if (edges[start].first != end) {
        n *= edges[start].second;
        dfs(edges, edges[start].first, end, n);
    } else {
        n *= edges[start].second;
        return n;
    }
    return 0;
}


vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, pair<string, double>> edges;
    for (int i = 0; i < values.size(); ++i) {
        edges[equations[i][0]] = {equations[i][1], values[i]};
        edges[equations[i][1]] = {equations[i][0], 1 / values[i]};
    }
    vector<double> res;
    for (auto q : queries) {
        if (edges.find(q[0]) == edges.end() || edges.find(q[1]) == edges.end()) {
            res.push_back(-1);
        } else {
            res.push_back(dfs(edges, q[0], q[1], 1));
        }
    }
    return res;
}

int main() {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    calcEquation(equations, values, queries);

    return 0;
}
