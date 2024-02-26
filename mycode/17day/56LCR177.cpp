#include<bits/stdc++.h>

using namespace std;
/*
整数数组 sockets 记录了一个袜子礼盒的颜色分布情况，
其中 sockets[i] 表示该袜子的颜色编号。
礼盒中除了一款撞色搭配的袜子，每种颜色的袜子均有两只。
请设计一个程序，在时间复杂度 O(n)，空间复杂度O(1) 内找到这双撞色搭配袜子的两个颜色编号。
*/
class Solution {
public:
    vector<int> sockCollocation(vector<int>& sockets) {
        int res = 0;
        int m = 1;
        int x = 0;
        int y = 0;
        for(auto i : sockets){
            res = res ^ i;
        }
        // 求m
        while (!(m & res))
        {
            m = m << 1;
            /* code */
        }

        // 划分两个数组
        for(auto i : sockets){
            if(i & m){
                x = x ^ i;
            }else{
                y = y ^ i;
            }
        }
        return vector<int>{x, y};
    }
};

int main(){

    return 0;
}