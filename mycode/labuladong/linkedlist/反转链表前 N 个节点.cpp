#include<bits/stdc++.h>

using namespace std;


/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* successor = nullptr;
public:
    ListNode* reverseN(ListNode* head,int n) {
        if(n == 1){
            successor = head->next;
            return head;
        }
        ListNode* re = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return re;
    }
};


int main(){

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    Solution* s = new Solution();
    auto ans = s->reverseN(l1, 3);
    while (ans)
    {
        cout << ans->val << " ";
        /* code */
        ans = ans->next;
    }
    cout << endl;

    
    return 0;
}