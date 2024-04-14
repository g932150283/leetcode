#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<int> nums(a);
        int index = 0;
        for(int i = 0; i < b; i++){
            int u, v;
            cin >> u >> v;
            for(int j = 0; j < v; j++){
                nums[index] = u;
                index++;
            }
        }
        // 数组构建完毕
        int q; 

        cin >> q;
        vector<int> res; 
        vector<int> result; 
        for(int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            int sum = 1;
            for(int j = l - 1; j < r; j++){
                sum = sum * nums[j];
            }
            cout << sum << endl;
            cout << "sumsumsumsumsumsumsumsumsum" << endl;
            for(int i1 = 1; i1 <= sum; i1++){
                for(int i2 = 1; i2 <= sum; i2++){
                    if(i1 * i2 == sum){
                        cout << i1 << endl;
                        res.push_back(i1);
                    }
                }
            }
            result.push_back(res.size());
            res.clear();
        }
        for(int r : result){
            cout << r << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")