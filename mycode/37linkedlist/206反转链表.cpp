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
    ListNode* reverseList(ListNode* head) {
        // ListNode* cur = head;
        // ListNode* tmp ;
        // ListNode* pre = nullptr;
        // while (cur != nullptr)
        // {
        //     tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        //     /* code */
        // }
        // return pre;
        if(head == nullptr){
            return nullptr;
        }else if(head ->next == nullptr){
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
        
    }
};