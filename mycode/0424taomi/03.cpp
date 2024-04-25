#include<bits/stdc++.h>

using namespace std;


/**

 */

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 链表的头结点
     * @return ListNode类
     */
    ListNode* sortList(ListNode* head) {
        // write code here
        vector<int> res;
        ListNode* cur = new ListNode(0);
        cur->next = head;
        ListNode* curnext = cur->next;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
            /* code */
        }
        sort(res.begin(), res.end());
        for(int r : res){
            curnext->val = r;
            curnext = curnext->next;
        }
        return cur->next;
        
    }
};


int main(){

    ListNode* l1 = new ListNode(4);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(1);
    ListNode* l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    Solution* s = new Solution();
    s->sortList(l1);
    return 0;
}