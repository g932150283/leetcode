


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
    ListNode* successor = nullptr;
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            successor = head->next;
            return head;
        }
        ListNode* re = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return re;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};