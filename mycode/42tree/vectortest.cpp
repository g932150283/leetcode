#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {1,2,3,4,5};
    vector<int> v1(v.begin(), v.begin() + 3);
    vector<int> v2(v.begin() + 3 + 1, v.end());
    for(auto num : v1){
        cout << num << endl;
    }
    cout << "============" << endl;
    for(auto num : v2){
        cout << num << endl;
    }
}