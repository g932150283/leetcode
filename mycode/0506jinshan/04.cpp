#include<bits/stdc++.h>

using namespace std;

int numzero(vector<pair<int, char>>& rb, int begin, int end){
    int r = 1;
    int b = 1;
    int numr = 0;
    int numb = 0;
    for(int i = begin; i <= end; i++){
        if(rb[i].second == 'B'){
            b = b * rb[i].first;
        }
        if(rb[i].second == 'R'){
            r = r * rb[i].first;
        }


    }
    while (r % 10 == 0)
    {
        numr++;
        r = r / 10;
    }
    while (b % 10 == 0)
    {
        numb++;
        b = b / 10;
    }
    
    return numr + numb;
}


int main() {
    int m;
    int k;
    while (cin >> m >> k)
    {
        vector<int> v1;
        vector<char> v2;
        vector<pair<int, char>> rb;
        
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            v1.push_back(x);
        }
        for(int i = 0; i < m; i++){
            char x;
            cin >> x;
            v2.push_back(x);
        }
        for(int i = 0; i < m; i++){
            rb.push_back({v1[i], v2[i]});
        }

        int res = INT_MAX;
        for(int i = 0; i < m;i++){
            int l = 0;
            while (l <= i)
            {
                int num0 = numzero(rb, l, i);
                if(num0 >= k){
                    res = min(res, i - l + 1);
                }
                l++;
            }
        }
        if(res == INT_MAX){
            cout << 0 << endl;
        }else{
            cout << res << endl;
        }
        

        

        
        
    }
    
}
// 64 位输出请用 printf("%lld")