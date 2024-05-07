#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (getline(cin, s))
    {
        stack<char> v;
        for(char ch : s){

            v.push(ch);
        }
        string ss = "";
        while (!v.empty())
        {
            ss += v.top();
            v.pop();
            /* code */
        }
        cout << ss << endl;
        
        
    }
    
}
// 64 位输出请用 printf("%lld")