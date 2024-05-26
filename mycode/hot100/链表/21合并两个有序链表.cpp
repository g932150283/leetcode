#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;


        // ListNode* cur = new ListNode(0);
        // ListNode* head = cur;
        // while (list1 != nullptr && list2 != nullptr)
        // {
        //     if(list1->val <= list2->val){
        //         head->next = new ListNode(list1->val);
        //         head = head->next;
        //         list1 = list1->next;
        //     }else{
        //         head->next = new ListNode(list2->val);
        //         head = head->next;
        //         list2 = list2->next;
        //     }
        //     /* code */
        // }
        // while (list1 != nullptr)
        // {
        //     head->next = new ListNode(list1->val);
        //     head = head->next;
        //     list1 = list1->next;
        //     /* code */
        // }
        // while (list2 != nullptr)
        // {
        //     head->next = new ListNode(list2->val);
        //     head = head->next;
        //     list2 = list2->next;
        //     /* code */
        // }
        // return cur->next;
        
        
    }   
};