#include<bits/stdc++.h>
using namespace std;
/*
...........
..*******..
..*..*..*..
..*******..
..*..*..*..
..*******..
.....*.....
..*******..
.....*.....
.*********.
...........

*/

int main() {
    int n;
    
    vector<string> li;
    // li.push_back("...........");
    // li.push_back("..*******..");
    // li.push_back("..*..*..*..");
    // li.push_back("..*******..");
    // li.push_back("..*..*..*..");
    // li.push_back("..*******..");
    // li.push_back(".....*.....");
    // li.push_back("..*******..");
    // li.push_back(".....*.....");
    // li.push_back(".*********.");
    // li.push_back("...........");

    while (cin >> n) { // 注意 while 处理多个 case
        // 先根据n构造里
        for(int i = 0; i < 11; i++){
            string s = "";
            if(i == 0 || i == 10){
                for(int j = 0; j < n*11; j++){
                    s += ".";
                }
                li.push_back(s);
            }
            if(i == 1 || i == 3 || i == 5 || i == 7){
                for(int j = 0; j < n * 2; j++){
                    s += ".";
                }
                for(int j = 0; j < n * 7; j++){
                    s += "*";
                }
                for(int j = 0; j < n * 2; j++){
                    s += ".";
                }
                li.push_back(s);
            }
            if(i == 9){
                for(int j = 0; j < n; j++){
                    s += ".";
                }
                for(int j = 0; j < n * 9; j++){
                    s += "*";
                }
                for(int j = 0; j < n; j++){
                    s += ".";
                }
                li.push_back(s);
            }
            if(i == 2 || i == 4){
                for(int j = 0; j < n * 2; j++){
                    s += ".";
                }
                for(int j = 0; j < n; j++){
                    s += "*";
                }
                for(int j = 0; j < n * 2; j++){
                    s += ".";
                }
                for(int j = 0; j < n; j++){
                    s += "*";
                }
                for(int j = 0; j < n * 2; j++){
                    s += ".";
                }
                for(int j = 0; j < n; j++){
                    s += "*";
                }
                for(int j = 0; j < n * 2; j++){
                    s += ".";
                }
                li.push_back(s);
            }
            if(i == 6 || i == 8){
                for(int j = 0; j < n * 5; j++){
                    s += ".";
                }
                for(int j = 0; j < n; j++){
                    s += "*";
                }
                for(int j = 0; j < n * 5; j++){
                    s += ".";
                }
                li.push_back(s);
            }
        }
        vector<string> res;
        for(int i = 0; i < li.size(); i++){
            for(int j = 0; j < n; j++){
                res.push_back(li[i]);
            }
        }
        for(string s : res){
            cout << s << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")


/*

......................
......................
....**************....
....**************....
....**....**....**....
....**....**....**....
....**************....
....**************....
....**....**....**....
....**....**....**....
....**************....
....**************....
..........**..........
..........**..........
....**************....
....**************....
..........**..........
..........**..........
..******************..
..******************..
......................
......................
*/