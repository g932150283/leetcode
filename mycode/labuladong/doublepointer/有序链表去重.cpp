#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val = 0) : val(val){
        next = nullptr;
    }
    /* data */
};


ListNode* remove(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast)
    {
        if(fast->val != slow->val){
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
        /* code */
    }
    slow->next = nullptr;
    return head;
    
}

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    ListNode* ll = remove(l1);
    while (ll)
    {
        cout << ll->val << endl;
        /* code */
        ll = ll->next;
    }
    return 0;
    
    
}