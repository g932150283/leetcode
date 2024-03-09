#include<bits/stdc++.h>

using namespace std;

class Solution{

public:
    int trap(vector<int>& height){
        stack<int> st;
        st.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); i++){
            while (!st.empty() && height[i] > height[st.top()])
            {
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum = sum + h * w;
                }
                /* code */
            }
            st.push(i);            
        }
        return sum;
    }

};




int trap(vector<int>& height){
    stack<int> s;
    int sum = 0;
    // 存放下标
    s.push(0);
    for(int i = 1; i < height.size(); i++){
        while (!s.empty() && height[i] > height[s.top()])
        {
            int mid = s.top();
            s.pop();
            if(!s.empty()){
                int h = min(height[s.top()], height[i]) - height[mid];
                int w = i - s.top() - 1;
                sum = sum + h * w;
            }
            /* code */
        }
        s.push(i);
        
    }
    return sum;

}