#include <bits/stdc++.h>
using namespace std;


int getAns(vector<int>& v){
    int n = v.size();
    int a = 0;
    int y = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            // cout << "v[i] = " << v[i] << endl;
            // cout << "v[j] = " << v[j] << endl;
            // cout << "v[i] + v[j] = " << v[i] + v[j] << endl;
            // cout << "v[i] ^ v[j] = " << (v[i] ^ v[j]) << endl;
            if(v[i] + v[j] == (v[i] ^ v[j])){
                res++;
            }
        }
    }
    return res;
}

int main() {
    int n;
    while (cin >> n)
    {
        vector<int> vl;
        vector<vector<int>> vll;
        vector<int> res;
        int index = 0;
        for(int i = 0; i < n; i++){
            int l;
            cin >> l;
            vl.push_back(l);
            vector<int> tmp;
            tmp.clear();
            for(int j = 0; j < l; j++){
                int num;
                cin >> num;
                tmp.push_back(num);
            }
            res.push_back(getAns(tmp));
            // cout << getAns(tmp) << endl;
            // for(int i : res){
            //     cout << i << endl;
            // }
            // vll.push_back(tmp);
        }
        // cout << vll.size();
        for(int i : res){
            cout << i << endl;
        }
        // int x = 1;
        /* code */
    }
    
}
// 64 位输出请用 printf("%lld")
/*
2
5
1 2 3 4 5
3
4 4 8


5
2

*/