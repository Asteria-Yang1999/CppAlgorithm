#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;



class LFUCache {
public:
    struct Node {
        int key, val, freq;
        Node* prev;
        Node* next;
        Node() : key(-1), val(-1), freq(0){}
        Node(int k, int v) : key(k), val(v), freq(1){}
    };

    class DoubleList {
    public:
        Node* head;
        Node* tail;
        int freq;
        DoubleList(int frequency) {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
            freq = frequency;
        }
    };

    unordered_map<int, Node*> keyToFreq;
    unordered_map<int, DoubleList*> freqToKey;
    int cap;
    int minFreq;
    LFUCache(int capacity) {
        keyToFreq.clear();
        freqToKey.clear();
        cap = capacity;
        minFreq = 0;
    }

    void deleteNode(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    bool isListEmpty(DoubleList* list) {
        if (list->head->next == list->tail) return true;
        return false;
    }

    void addHead(Node* x) {
        int freq = x->freq;
        if (freqToKey.count(freq) == 0) freqToKey[freq] = new DoubleList(freq);
        DoubleList* l = freqToKey[freq];
        x->prev = l->head;
        x->next = l->head->next;
        l->head->next = x;
        x->next->prev = x;
    }

    int get(int key) {
        if (keyToFreq.count(key) == 0) {
            return -1;
        }
        Node* x = keyToFreq[key];
        int val = x->val;
        deleteNode(x);
        x->freq++;
        if (isListEmpty(freqToKey[minFreq])) {
            minFreq++;
        }
        addHead(x);
        return val;
    }

    void delTail() {
        Node* x = freqToKey[minFreq]->tail->prev;
        deleteNode(x);
        keyToFreq.erase(x->key);
    }

    void put(int key, int val) {
        if (cap == 0) return;
        if (get(key) != -1) {
            Node* en = keyToFreq[key];
            en->val = val;
        } else {
            if (keyToFreq.size() == cap) delTail();
            Node* x = new Node(key, val);
            keyToFreq[key] = x;
            minFreq = 1;
            addHead(x);
        }
    }

};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
