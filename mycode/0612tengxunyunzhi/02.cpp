#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<long> a, vector<long> b){
    if(a[0] < b[0]){
        return true;
    }else{
        return a[1] > b[1];
    }
}
template<typename _Tp>
struct less : public binary_function<_Tp, _Tp, bool>
{
bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return __x < __y; }
};

struct less1
{
bool
      operator()(vector<long> a, vector<long> b) const
      { return a[0] > b[0]; }
};



int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<vector<long>> med;
        priority_queue<vector<long>, vector<vector<long>>, less1> q;
        for(int i = 0; i < n; i++){
            long a, b;
            cin >> a >> b;
            // med.push_back({a, b});
            q.push({a, b});
        }
        

        // sort(med.begin(), med.end(), cmp);
        int num;
        cin >> num;
        vector<long> res;
        for(int i = 0; i < num; i++){
            long v;
            cin >> v;
            long r = -1;
            priority_queue<vector<long>, vector<vector<long>>, less1> q1;
            q1 = q;
            while (!q1.empty())
            {
                if(v >= q1.top()[0]){
                    r = max(r, q1.top()[1]);
                    q1.pop();
                }else{
                    break;
                }
                /* code */
            }
            
            // for(auto m : med){
            //     if(v >= m[0]){
            //         r = max(r, m[1]);
            //     }else{
            //         break;
            //     }
            // }

            res.push_back(r);
        }
        for(auto r : res){
            cout << r << endl;
        }
        
    }
}
// 64 位输出请用 printf("%lld")
/*
5
3 10
4 2
6 6
9 10
10 9
3
1
6
9
*/