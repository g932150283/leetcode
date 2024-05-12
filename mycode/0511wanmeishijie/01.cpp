#include<bits/stdc++.h>

using namespace std;

/**

 */

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
public:
    /**
     * 判断是否为回文链表
     * @param head ListNode类 链表头
     * @return bool布尔型
     */
    bool isPalindrome(ListNode* head) {
        // write code here
        if(head == nullptr){
            return true;
        }
        vector<int> v;
        stack<int> s;
        while (head)
        {
            v.push_back(head->val);
            s.push(head->val);
            head = head->next;
            /* code */
        }
        for(int i = 0; i < v.size(); i++){
            if(v[i] == s.top()){
                s.pop();
            }else{
                return false;
            }
        }
        return true;
        
        
    }
};