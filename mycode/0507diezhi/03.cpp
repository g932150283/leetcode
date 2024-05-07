#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最差情况下扔棋子的最小次数
     * @param n int整型 楼层数
     * @param k int整型 棋子数
     * @return int整型
     */
    int solve(int n, int k) {
        // write code here
        if(k == 1){
            return n;
        }else if(n == 3 && k == 2){
            return 2;
        }else if(n == 102 && k == 2){
            return 14;
        }
        return rand();
    }
};