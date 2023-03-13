#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ThroneInheritance {
private:
    unordered_map<string, vector<string>> family;
    unordered_set<string> dead;
    string king;

public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    void dfs(string name, vector<string>& ans) {
        if (dead.find(name) == dead.end()) ans.push_back(name);
        for (auto f : family[name]) dfs(f, ans);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(king, ans);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
