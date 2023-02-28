#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v){}
};

class DoubleList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addLast(Node* x) {
        x->next = tail;
        x->prev = tail->prev;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    void remove(Node* x) {
        x->prev->next =x->next;
        x->next->prev = x->prev;
        size--;
    }

    Node* removeLeastRecently() {
        if (head->next == tail) {
            return nullptr;
        }
        Node* res = head->next;
        remove(res);
        return res;
    }

    int getSize() {
        return size;
    }
};

class LRUcache {
private:
    unordered_map<int, Node*> map;
    DoubleList cache;
    int cap;
public:
    LRUcache(int capacity) {
        cap = capacity;
    }

    void makeRecently(int key) {
        Node* x = map[key];
        cache.remove(x);
        cache.addLast(x);
    }

    void addRecently(int key, int val) {
        Node* x = new Node(key, val);
        cache.addLast(x);
        map[key] = x;
    }

    void deleteKey(int key) {
        Node* x = map[key];
        cache.remove(x);
        map.erase(key);
    }

    void removeLeastRecently() {
        Node* x = cache.removeLeastRecently();
        map.erase(x->key);
    }

    int get(int key) {
        if (map[key] != nullptr) {
            makeRecently(key);
            return map[key]->val;
        }
        return -1;
    }

    void put(int key, int val) {
        if (map[key] != nullptr) {
            deleteKey(key);
            addRecently(key, val);
        } else {
            if (cache.getSize() == cap) {
                removeLeastRecently();
            }
            addRecently(key, val);
        }

    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
