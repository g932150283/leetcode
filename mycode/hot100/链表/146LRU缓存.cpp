#include<bits/stdc++.h>

using namespace std;
// struct Node
// {
//     int key, value;
//     Node *pre, *next;

//     Node(int k = 0, int v = 0) : key(k), value(v){}
//     /* data */
// };

// class LRUCache {
//     // 一个哨兵，双向链表
// private:
//     int capacity;
//     Node *dummy; // 哨兵结点，dummy->next第一个，dummy->pre最后一个
//     unordered_map<int, Node*> key_to_node;
    
//     // delete node
//     void remove(Node *node){
//         // x -> node -> y
//         // x <- node <- y
//         node->pre->next = node->next;
//         node->next->pre = node->pre;
//     }

//     // add node top
//     void push_front(Node *node){
//         // dummy  ->  x
//         // dummy  <-  x
//         // dummy  ->  node  ->  x 
//         // dummy  <-  node  <-  x
//         node->pre = dummy;
//         node->next = dummy->next;
//         node->pre->next = node;
//         node->next->pre = node; 
//     }

//     Node *get_node(int key){
//         // 查找，不存在返回空；存在将其移动到队头
//         auto it = key_to_node.find(key);
//         if(it == key_to_node.end()){
//             return nullptr;
//         }
//         auto node = it->second;
//         remove(node);
//         push_front(node);
//         return node;
//     }
// public:

//     LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
//         dummy->next = dummy;
//         dummy->pre = dummy;
//     }   
    
//     int get(int key) {
//         auto node = get_node(key);
//         if(node){
//             return node->value;
//         }else{
//             return -1;
//         }
//     }
    
//     void put(int key, int value) {
//         auto node = get_node(key);
//         if(node){
//             node->value = value;
//             return;
//         }
//         node = new Node(key, value);
//         key_to_node[key] = node;
//         push_front(node);
//         if(key_to_node.size() > capacity){
//             auto end_node = dummy->pre;
//             key_to_node.erase(end_node->key);
//             remove(end_node);
//             delete end_node;
//         }
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */

struct Node
{
    int key, value;
    Node *pre, *next;
    Node(int k = 0, int v = 0) : key(k), value(v) {}
    /* data */
};


class LRUCache {
private:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_value;

    void remove(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void push_front(Node *node){
        node->next = dummy->next;
        node->pre = dummy;
        node->next->pre = node;
        node->pre->next = node;
    }

    Node* get_node(int key){
        auto it = key_to_value.find(key);
        if(it == key_to_value.end()){
            return nullptr;
        }
        Node *node = it->second;
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
        Node *node = get_node(key);
        if(node){
            return node->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Node *node = get_node(key);
        if(node){
            node->value = key;
            return;
        }
        node = new Node(key, value);
        key_to_value[key] = node;
        push_front(node);
        if(capacity < key_to_value.size()){
            Node *end_node = dummy->pre;
            remove(end_node);
            delete end_node;
        }
    }
};