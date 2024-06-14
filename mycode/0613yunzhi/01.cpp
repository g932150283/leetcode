#include<bits/stdc++.h>

using namespace std;

// 合并递增有序链表
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};


ListNode* merge(ListNode* l1, ListNode *l2){
    ListNode *root = new ListNode(0);
    ListNode *cur = root;
    while (l1 && l2)
    {
        if(l1->val < l2->val){
            cur->next = new ListNode(l1->val);
            cur = cur->next;
            l1 = l1->next;
        }else{
            cur->next = new ListNode(l2->val);
            cur = cur->next;
            l2 = l2->next;
        }
    }
    while (l1)
    {
        cur->next = new ListNode(l1->val);
        cur = cur->next;
        l1 = l1->next;
    }
    while (l2)
    {
        cur->next = new ListNode(l2->val);
        cur = cur->next;
        l2 = l2->next;
    }
    return root->next;  
}

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode *l11 = new ListNode(0);
    ListNode *l22 = new ListNode(2);
    ListNode *l33 = new ListNode(4);
    ListNode *l44 = new ListNode(4);
    ListNode *l55 = new ListNode(5);
    l11->next = l22;
    l22->next = l33;
    l33->next = l44;
    l44->next = l55;

    ListNode *r = merge(l1, l11);
    while (r)
    {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    
    return 0;
}