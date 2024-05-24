/*
一只青蛙一次可以跳上 1 级台阶，2 级台阶，3 级台阶。求该青蛙跳上一个 n 级的台阶
总共有多少种跳法
*/

#include<bits/stdc++.h>

using namespace std;


int getAns(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 4;
    }
    return getAns(n - 3) + getAns(n - 2) + getAns(n - 1);
}

int main(){
    int n = 4;
    cout << getAns(4) << endl;
    return 0;
}