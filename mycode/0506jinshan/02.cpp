#include<bits/stdc++.h>

using namespace std;


int add(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

int mul(int x, int y){
    return x * y;
}

int div1(int x, int y){
    return x / y;
}


int main() {
    string s;
    int x;
    int y;
    while (cin >> s >> x >> y)
    {
        
        // cout << s << " " << x  << " " << y << endl;
        if(s == "add" || s == "ADD"){
            cout << add(x, y) << endl;
        }
        if(s == "sub" || s == "SUB"){
            cout << sub(x, y) << endl;
        }
        if(s == "mul" || s == "MUL"){
            cout << mul(x, y) << endl;
        }
        if(s == "div" || s == "DIV"){
            if(y != 0){
                cout << div1(x, y) << endl;
            }else{ 
                cout << "Error" << endl;
            }
        }
        
        
        
    }
    
}
// 64 位输出请用 printf("%lld")