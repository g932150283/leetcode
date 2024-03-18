
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ha = headA;
        ListNode* hb = headB;
        while (ha != hb)
        {

            if(ha == nullptr){
                ha = headB;
            }else{
                ha = ha->next;
            }
            if(hb == nullptr){
                hb = headA;
            }else{
                hb = hb->next;
            }           
            /* code */
        }
        return ha;
        
    }   
};