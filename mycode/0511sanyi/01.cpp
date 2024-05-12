#include<bits/stdc++.h>

using namespace std;

bool static cmp(double a, double b){
    return a > b;
}
int main(){

    // int a = 1;

    // a += (a++);
    // cout << a << endl;


    // int b = 1;
    // b += (++b);
    // cout << b << endl;


    // int c = 1;
    // (c++) += c;
    // cout << c << endl;

    // int d = 1;
    // (++d) += (d++);
    // cout << d << endl;

    vector<double> v(10);
    for(int i = 0; i < 10; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    for(double d : v){
        cout << d << " ";
    }
    cout << endl;


    return 0;
}