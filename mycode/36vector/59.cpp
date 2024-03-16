#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //循环不变量
        // 从几开始走
        int sum = 1;
        int startI = 0;
        int startJ = 0;
        // 每圈走多少步
        int step = n - 1;
        // 走几圈 n / 2
        int num = n / 2;
        int i, j;
        vector<vector<int>> res(n, vector<int>(n));
        while (num--)
        {
            // 右
            for(int j = 0; j < step; j++){
                // startJ = startJ + 1;
                res[startI][startJ++] = sum++;
            }
            // startJ++;

            // 下
            for(int i = 0; i < step; i++){
                // startI += 1;
                res[startI++][startJ] = sum++;
            }
            // startI++;

            // 左
            for(int j = 0; j < step; j++){
                // startJ -= 1;
                res[startI][startJ--] = sum++;
            }
            // startJ--;

            // 上
            for(int i = 0; i < step; i++){
                // startI -= 1;
                res[startI--][startJ] = sum++;
            }
            startI++;
            startJ++;

            if(step == 2 ){
                step = 1;
            }else{
                step = step - 2;
            }
        }

        if(n % 2 == 1){
            res[n / 2][n /2] = sum;
        }

        return res;
        
    }
};

int main(){

    Solution* s = new Solution();
    vector<vector<int>> res = s->generateMatrix(6);
    cout << res.size() << endl;
    return 0;
}