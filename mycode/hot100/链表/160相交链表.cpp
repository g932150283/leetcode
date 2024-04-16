#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    /* data */
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        while (h1 != h2)
        {
            if(h1 == nullptr){
                h1 = headB;
            }else{
                h1 = h1->next;
            }
            if(h2 == nullptr){
                h2 = headA;
            }else{
                h2 = h2->next;
            }
            /* code */
        }
        return h1;
        
    }
};