#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    /* data */
};


class Solution {
    ListNode* endOfFirstHalf(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            /* code */
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            /* code */
        }
        return pre;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        // ListNode* cur = head;
        // ListNode* h1 = new ListNode(0);
        // while (cur != nullptr)
        // {
        //     ListNode* node = new ListNode(cur->val);
        //     node->next = h1->next;
        //     h1->next = node;
        //     cur = cur->next;
        //     /* code */
        // }

        // h1 = h1->next;
        // while (head != nullptr)
        // {
        //     if(h1->val == head->val){
        //         h1 = h1->next;
        //         head = head->next;
        //     }else{
        //         return false;
        //     }
        //     /* code */
        // }
        // return true;
        // vector<int> res;
        // while (head != nullptr)
        // {
        //     res.push_back(head->val);
        //     head = head->next;
        //     /* code */
        // }
        // for(int i = 0, j = res.size() - 1; i < j; i++, j--){
        //     if(res[i] != res[j]){
        //         return false;
        //     }
        // }
        // return true;

        
        if(head == nullptr){
            return true;
        }

        // slow->next 是后半段的开始
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secodeBegin = reverseList(firstHalfEnd->next);

        ListNode* l1 = head;
        ListNode* l2 = secodeBegin;
        while (l2 != nullptr)
        {
            if(l1->val != l2->val){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
            /* code */
        }
        firstHalfEnd->next = reverseList(secodeBegin);
        return true;
        
        
        
        
        
    }
};