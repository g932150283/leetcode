#include<bits/stdc++.h>

using namespace std;


int main(){

    string nu = "";
    string n = "";
    string s = "abcde";
    cout << nu << endl;
    nu = nu + s;
    cout << nu << endl;
    nu.erase(nu.rfind(s), s.length());

    cout << nu << endl;
    cout << (nu == n) << endl;

    return 0;
}