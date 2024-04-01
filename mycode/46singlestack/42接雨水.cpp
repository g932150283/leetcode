#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // 双指针
        // vector<int> l(height.size());
        // vector<int> r(height.size());

        // l[0] = height[0];
        // for(int i = 1; i < height.size(); i++){
        //     l[i] = max(height[i], l[i - 1]);
        // }

        // r[height.size() - 1] = height[height.size() - 1];
        // for(int i = height.size() - 2; i >= 0; i--){
        //     r[i] = max(height[i], r[i + 1]);
        // }
        // int sum = 0;
        // for(int i = 1; i < height.size() - 1; i++){
        //     int count = min(l[i], r[i]) - height[i];
        //     if(count > 0){
        //         sum += count;
        //     }
        // }
        // return sum;
        int sum = 0;
        stack<int> s;
        s.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] <= height[s.top()])
            {
                s.push(i);
            }
            else
            {
                while (!s.empty() && height[i] > height[s.top()])
                {

                    int cur = s.top();
                    s.pop();
                    if (!s.empty())
                    {
                        int r = i;
                        int l = s.top();
                        int w = r - l - 1;
                        int h = min(height[r], height[l]) - height[cur];
                        sum += w * h;
                    }
                }
                s.push(i);
            }
        }
        return sum;
    }
};

int main()
{

    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution *s = new Solution();
    s->trap(v);
    return 0;
}