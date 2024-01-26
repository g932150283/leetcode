//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
// #include<bits/stdc++.h>
#include "../include/include.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int cnt) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < cnt; i++){
            if(fast == nullptr){
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
        
    }
};

int main(){

    // ListNode *head = vectorToLinkedList(vector<int>{1, 2, 3, 4, 5});
    ListNode *head = vectorToLinkedList(vector<int>{4, 5, 1, 9});
    int k = 2;
    // ====== Driver Code ======
    Solution *slt = new Solution();
    ListNode *res = slt->getKthFromEnd(head, k);
    PrintUtil::printLinkedList(res);

    return 0;
}