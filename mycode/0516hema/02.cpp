#include <bits/stdc++.h>
using namespace std;

bool isZ(int x){
    if(x <= 2){
        return false;
    }
    for(int i = 2; i <= x / 2; i++){
        if(x % i == 0){
            return true;
        }
    }
    return false;
}

bool isTrue1(int x){
    if(x < 8){
        return false;
    }
    if(x == 9){
        return false;
    }
    if(isZ(x) == false){
        return false;
    }

    int xx;
    if(x % 2 == 0){
        xx = x / 2;
        if(xx % 2 == 0 || (xx % 3 == 0 && xx / 3 > 1) 
            || (xx % 5 == 0 && xx / 5 > 1) || (xx % 7 == 0 && xx / 7 > 1)
            || (xx % 9 == 0 && xx / 9 > 1)){
            return true;
        }else{
            return false;
        }
    }else if(x % 3 == 0){
        xx = x / 3;
        if(xx % 2 == 0 || (xx % 3 == 0 && xx / 3 > 1) 
            || (xx % 5 == 0 && xx / 5 > 1) || (xx % 7 == 0 && xx / 7 > 1)
            || (xx % 9 == 0 && xx / 9 > 1)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

    // for(int i1 = 2; i1 <= x / 3; i1++){
    //     for(int i2 = 2; i2 <= x / 3; i2++){
    //         for(int i3 = 2; i3 <= x / 3; i3++){
    //             if((i1 * i2 * i3) == x){
    //                 return true;
    //             }
    //         }
    //     }
            
    // }
    // return false;
}


bool is2(int x){
    
    if(x < 8){
        return false;
    }
    if(x == 9){
        return false;
    }
    if(isZ(x) == false){
        return false;
    }
    
    for(int i1 = 2; i1 <= x / 3; i1++){
        for(int i2 = 2; i2 <= x / 3; i2++){
            for(int i3 = 2; i3 <= x / 3; i3++){
                if((i1 * i2 * i3) == x){
                    return true;
                }
            }
        }
            
    }
    return false;
}

int getAns(vector<int>& v){
    int n = v.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        if(isTrue1(v[i])){
            // cout << v[i] <<  " ";
            res++;
        }
        // if(is2(v[i])){
        //     cout << v[i] <<  " ";
        //     res++;
        // }
    }
    return res;
}



int main() {
    int n;
    
    while (cin >> n)
    {
        vector<int> nums;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            nums.push_back(num);
        }
        int res = getAns(nums);
        cout << res << endl;

        /* code */
    }
    return 0;
    
}
