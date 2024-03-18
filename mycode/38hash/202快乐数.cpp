#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int getSum(int n){
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
            /* code */
        }
        return sum;
        
    }

    bool isHappy(int n) {
        unordered_set<int> res;
        while (1)
        {
            int sum = getSum(n);
            if(sum == 1){
                return true;        
            }
            if(res.find(sum) != res.end()){
                return false;
            }else{
                res.insert(sum);
            }
            /* code */
            n = sum;
        }
        
    }
};