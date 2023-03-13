#include <iostream>
#include <vector>

using namespace std;

class TrieNode{
public:
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() : children(26, nullptr), isWord(false){}
    ~TrieNode() {
        for (auto c : children) delete c;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* p = root;
        for (auto w : word) {
            int i = w - 'a';
            if (!p->children[i]) {
                p->children[i] = new TrieNode();
            }
            p = p->children[i];
        }
        p->isWord = true;
    }

    bool match(string word, TrieNode* root, int start) {
        if (!root) return false;
        if (start == word.size()) return root->isWord;
        char c = word[start];
        if (c != '.') {
            return match(word, root->children[c - 'a'], start + 1);
        } else {
            for (auto child : root->children) {
                if (match(word, child, start + 1)) return true;
            }
        }
        return false;
    }

    bool search(string word) {
        return match(word, root, 0);
    }
};

int main() {
//    cout << findWord("a", "aa");
    return 0;
}
