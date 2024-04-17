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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* pre = head;
        ListNode* tail = head;
        int len = 0;
        while (head != nullptr)
        {
            head = head->next;
            len++;
            /* code */
        }
        int end, start;
        if(len % 2 == 1){
            end = len / 2;
            start = len / 2 + 2;
        }else{
            end = len / 2;
            start = len / 2 + 1;
        }
        stack<int> s;
        for(int i = 1; i <= end; i++){
            s.push(pre->val);
            pre = pre->next;
        }
        for(int i = start; i <= len; i++){
            if(s.top() == pre->val){
                s.pop();
                pre = pre->next;
            }else{

                return false;
            }
        }
        
        
        return true;
        
        
    }
};