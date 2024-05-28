#include <bits/stdc++.h>

using namespace std;




long target = 0;
vector<int> path;
set<vector<int>> s;
unordered_map<int, int> res;
void backtracking(long sum, long cen, int begin){
    // if(cen == 0){
    //     return;
    // }
    if(sum > target){
        return;
    }
    if(sum + cen * 7 < target){
        return;
    }
    if(sum == target && cen == 0){
        vector<int> tmp;
        tmp = path;
        sort(tmp.begin(), tmp.end());
        if(s.count(tmp) == 0){
            for(int ll : tmp){
                res[ll]++;
            }
        }
        return;
    }



    for(int i = begin; i <= 7; i++){
        sum += i;
        path.push_back(i);
        cen--;
        backtracking(sum, cen, i);
        cen++;
        path.pop_back();
        sum -= i;
    }
}

int main(){


    long n,m;
    while (cin >> n >> m)
    {
        target = m;
        path.clear();
        s.clear();
        res.clear();
        /* code */
        backtracking(0, n, 1);
        for(int i = 1; i <= 7; i++){
            cout << res[i] << endl;
        }
    }
    return 0;
    
}