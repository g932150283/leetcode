/**
 * Definition for singly-linked list.

 */
#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool cmp(ListNode* l1, ListNode* l2){
    return l1->val > l2->val;
}



class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

    ListNode* mergeLists(vector<ListNode*> list, int l, int r){
        int m = r - l;
        if(m == 0){
            return nullptr;
        }
        if(m == 1){
            return list[l];
        }
        auto left = mergeLists(list, l, l + m / 2);
        auto right = mergeLists(list, l + m / 2, r);
        return mergeTwoLists(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size());
        // if(lists.size() == 0){
        //     return nullptr;
        // }
        // priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> que(cmp);
        // for(auto l : lists){
        //     if(l){
        //         que.push(l);
        //     }
        // }
        // ListNode* dummy = new ListNode(0);
        // ListNode* cur = dummy;
        
        // while (!que.empty())
        // {
        //     ListNode* node = que.top();
        //     que.pop();
        //     if(node->next != nullptr){
        //         que.push(node->next);
        //     }
        //     cur->next = node;
        //     cur = cur->next;           
        //     /* code */
        // }
        // return dummy->next;
        

    }
};

int main(){

    vector<ListNode*> l;

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(1);
    ListNode* l5 = new ListNode(3);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;

    ListNode* l7 = new ListNode(2);
    ListNode* l8 = new ListNode(6);
    l7->next = l8;

    l.push_back(l1);
    l.push_back(l2);
    l.push_back(l3);

    Solution* s = new Solution();
    s->mergeKLists(l);


    return 0;
}