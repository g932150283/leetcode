/*
判断链表中是否有环
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
    /* data */
};

int getAns(ListNode* head){
    if(head == nullptr){
        return 0;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (true)
    {
        if(fast == nullptr || fast->next == nullptr){
            return 0;
        }
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
        if(fast == slow){
            return 1;
        }
        /* code */
    }
    
}


int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    ListNode* l11 = new ListNode(1);
    ListNode* l22 = new ListNode(2);
    ListNode* l33 = new ListNode(3);
    ListNode* l44 = new ListNode(4);

    l11->next = l22;
    l22->next = l33;
    l33->next = l44;
    l44->next = l22;

    cout << getAns(l1) << endl;
    cout << getAns(l11) << endl;



    
}
