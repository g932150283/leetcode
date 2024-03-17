#include<bits/stdc++.h>

using namespace std;

class MyLinkedList {


public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode():val(0), next(nullptr){}
        LinkedNode(int val):val(val), next(nullptr){}
        LinkedNode(int val, LinkedNode* l):val(val), next(l){}
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode();
        _size = 0;
    }
    // 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
    int get(int index) {
        if(index < 0 || index >= _size){
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
            /* code */
        }
        
        return cur->val;
    }
    // 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = _dummyHead->next;
        _dummyHead->next = node;
        _size++;
    }
    // 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    void addAtTail(int val) {
        LinkedNode* cur = _dummyHead->next;
        while (cur->next != nullptr)
        {
            cur = cur->next;
            /* code */
        }
        
        LinkedNode* node = new LinkedNode(val);
        cur->next = node;
        _size++;
    }
    // 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
    // 如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。
    // 如果 index 比长度更大，该节点将 不会插入 到链表中。
    void addAtIndex(int index, int val) {
        if(index < 0 || index > _size){
            return;
        }
        if(index == _size){
            addAtTail(val);
        }else{
            LinkedNode* cur = _dummyHead->next;
            while (index--)
            {
                cur = cur->next;
                /* code */
            }
            
            LinkedNode* node = new LinkedNode(val);
            node->next = cur->next;
            cur->next = node;
            _size++;
        }
    }
    // 如果下标有效，则删除链表中下标为 index 的节点。
    void deleteAtIndex(int index) {
        if(index < 0 || index >= _size){
            return;
        }
        int curIndex = 0;
        LinkedNode* cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
            /* code */
        }
        LinkedNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        _size--;


    }

private:
    int _size;
    LinkedNode* _dummyHead;
};


int main(){


    MyLinkedList* my = new MyLinkedList();
    my->addAtHead(1);
    my->addAtTail(3);
    my->addAtIndex(1, 2);
    int a = my->get(1);
    return 0;
}