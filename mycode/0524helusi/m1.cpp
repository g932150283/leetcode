/*
将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，例如：
给出的链表为
1→2→3→4→5→NULL, m = 2,n = 4
返回 1→4→3→2→5→NULL
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
    /* data */
};

ListNode* getAns(ListNode* head, int m, int n){
    if(head == nullptr){
        return head;
    }
    if(m < n || m < 1){
        return nullptr;
    }
    
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    // 找到m前一个
    ListNode* mpre = head;
    for(int i = 0; i < m - 1; i++){
        mpre = mpre->next;
    }
    ListNode* mNode = mpre->next;
    // n后一个
    ListNode* nNode = head;
    for(int i = 0; i < n; i++){
        nNode = nNode->next;
    }
    ListNode* pre = nNode->next;
    for(int i = 0; i < n - m + 1; i++){
        ListNode* tmp = mNode->next;
        mNode->next = pre;
        tmp->next = mNode;
        pre = mNode;
        mNode = tmp;
    }
    mpre->next = pre;
    return dummy->next;



    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* mPre = dummy;
    for(int i = 0; i < m - 1; i++){
        mPre = mPre->next;
    }
    ListNode* cur = mPre->next;
    ListNode* pre = nullptr;
    for(int i = 0; i < m - n + 1;i++){
        ListNode* tmp = cur->next;
        cur->next = pre;
        tmp->next = cur;
        pre = cur;
        cur = tmp;
    }
    mPre->next->next = cur;
    mpre->next = pre;
    return dummy;





}