#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        //(1) 当所有绳段长度相等时，乘积最大。(2) 最优的绳段长度为 3 。
        if(bamboo_len % 3 == 0){
            if(bamboo_len - 3 == 0){
                return 2;
            }
            return pow(3, (bamboo_len / 3));
        }else if(bamboo_len % 3 == 1){
            return pow(3, (bamboo_len / 3) - 1) * 4;
        }else{
            return pow(3, (bamboo_len / 3)) * 2;
        }

    }
};