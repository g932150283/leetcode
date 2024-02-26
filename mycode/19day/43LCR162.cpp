#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int digitOneInNumber(int num) {
        //给定一个整数 num，计算所有小于等于 num 的非负整数中数字 1 出现的个数。
        // cur = 0, h*dig
        // cur = 1, h*dig + low + 1
        // cur      h + 1 * dig
        int ten = 10;
        int cur = num % ten;
        int high = num / ten;
        int low = 0;
        int dig = 1;
        int res = 0;

        while (cur || high)
        {
            if(cur == 0){
                res = res + high * dig;
            }else if(cur == 1){
                res = res + high * dig + low + 1;
            }else{
                res = res + (high + 1) * dig;
            }
            low = num % ten;
            cur = high % 10; 
            ten = ten * 10;
            high = num / ten;
            dig = dig * 10;            
            /* code */
        }
        return res;
    }
};

int main(){
    Solution* s = new Solution();
    cout << s->digitOneInNumber(13);
}