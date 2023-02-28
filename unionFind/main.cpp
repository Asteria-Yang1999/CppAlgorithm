#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    int count;
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        size = vector<int>(n);
        count = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int getCount() {
        return count;
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        if (size[rootP] < size[rootQ]) {
            size[rootQ] += size[rootP];
            parent[rootP] = rootQ;
        } else {
            size[rootP] += size[rootQ];
            parent[rootQ] = rootP;
        }
    }

    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }
};

bool equationsPossible(vector<string>& equations) {
    UnionFind *uf = new UnionFind(26);
    for (string eq : equations) {
        if (eq[1] == '=') {
            uf->Union(eq[0] - 'a', eq[3] - 'a');
        }
    }
    for (string eq : equations) {
        if (eq[1] == '!') {
            if (uf->find(eq[0] - 'a') == uf->find(eq[3] - 'a') ) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
