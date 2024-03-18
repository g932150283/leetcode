
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
    ListNode *detectCycle(ListNode *head) {
        // 是否有环
        ListNode *s = head;
        ListNode *q = head;
        ListNode *tmp = head;
        ListNode *tmp1;
        while (q != nullptr && q->next != nullptr)
        {
            s = s->next;
            q = q->next;
            q = q->next;
            if(q == s){
                tmp1 = s;
                while (tmp1 != tmp)
                {
                    tmp1 = tmp1->next;
                    tmp = tmp->next;
                    /* code */
                }
                return tmp;
            }
            /* code */
        }
        return nullptr;
        
        
    }
};