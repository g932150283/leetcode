/**
 * Definition for singly-linked list.

 */

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
    
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto head : lists){
            if(head){
                pq.push(head);
            }
        }
        ListNode dummy(0);
        auto cur = &dummy;
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if(node->next){
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
            /* code */
        }
        return dummy.next;
        
    
    }
};