#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int key, val;
    Node *next, *pre;
    Node() : key(0), val(0), next(nullptr), pre(nullptr) {}
    Node(int _key, int _val) : key(_key), val(_val), next(nullptr), pre(nullptr) {}
    /* data */
};


class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> umap;
    Node* dummy;

    void remove(Node* node){
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    void push_front(Node* node){
        node->next = dummy->next;
        node->pre = dummy;
        node->next->pre = node;
        node->pre->next = node;
    }

    Node* get_node(int key){
        auto it = umap.find(key);
        if(it == umap.end()){
            // 找不到
            return nullptr;
        }
        Node* node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
    
public:

    LRUCache(int capacity) : capacity(capacity), dummy(new Node()){
        dummy->next = dummy;
        dummy->pre = dummy;
    }   
    
    int get(int key) {
        Node* node = get_node(key);
        if(node){
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Node* node = get_node(key);
        if(node){
            node->val = value;
            return;
        }else{
            node = new Node(key, value);
            umap[key] = node;
            push_front(node);
            if(capacity < umap.size()){
                Node* tmp = dummy->pre;
                remove(tmp);
                // 擦除
                umap.erase(tmp->key);
                delete tmp;
            }
        }
    }
};