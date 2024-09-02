#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int key, value;
    Node *pre, *next;
    Node(int key = 0, int val = 0) : key(key), value(val) {

    }
    /* data */
};


class LRUCache {
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> keyToValue;

    void remove(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void push_front(Node* node){
        node->pre = dummy;
        node->next = dummy->next;
        node->pre->next = node;
        node->next->pre = node;
        
    }

    Node* getNode(int key){
        auto it = keyToValue.find(key);
        if(it == keyToValue.end()){
            return nullptr;
        }
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
        dummy->next = dummy;
        dummy->pre = dummy;
    }
    
    int get(int key) {
        Node* node = getNode(key);
        if(node){
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* node = getNode(key);
        if(node){
            node->value = value;
            return;
        }
        node = new Node(key, value);
        keyToValue[key] = node;
        push_front(node);
        if(keyToValue.size() > capacity){
            Node* endNode = dummy->pre;
            keyToValue.erase(endNode->key);
            remove(endNode);
            delete endNode;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */