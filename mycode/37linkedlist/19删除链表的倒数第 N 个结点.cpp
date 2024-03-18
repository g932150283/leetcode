#include<bits/stdc++.h>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* l) : val(0), next(l) {}
    /* data */
};



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* s = dummy;
        ListNode* q = dummy;
        while (n-- && q != nullptr)
        {
            q = q->next;
            /* code */
        }
        q = q->next;
        while (q)
        {
            q = q->next;
            s = s->next;
            /* code */
        }
        ListNode* tmp = s->next;
        s->next = tmp->next;
        delete tmp;
        return dummy->next;
        
        
    }
};