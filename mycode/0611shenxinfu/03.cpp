#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    string ip;
    vector<Node*> pre;
    vector<Node*> next;
    Node(int _id, string _ip) : id(_id), ip(_ip){};
    /* data */
};


int main() {
    int n, m;
    while (cin >> n >> m) { // 注意 while 处理多个 case
        vector<Node*> v;
        for(int i = 0; i < n; i++){
            string ip;
            int id;
            cin >> ip;
            cin >> id;
            // cout << ip << endl;
            // cout << id << endl;
            v.push_back(new Node(id, ip));
        }
        // for(auto i : v){
        //     cout << i->id << endl;
        // }
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            v[a - 1]->next.push_back(v[b - 1]);
            v[b - 1]->pre.push_back(v[a - 1]);
        }
        unordered_map<string, Node*> umap;
        for(auto i : v){
            umap[i->ip] = i;
        }
        // cout << v[1 - 1]->next.size() << endl;
        int num;
        cin >> num;
        vector<int> res;
        for(int i = 0; i < num; i++){
            string s1, s2;
            cin >> s1;
            cin >> s2;
            if(s1 == s2){
                res.push_back(0);
            }
        }
    }
}
// 64 位输出请用 printf("%lld")
/*

7 7
192.168.0.1 1
192.168.0.2 2
192.168.0.3 3
192.168.0.4 4
192.168.0.5 5
192.168.0.6 6
192.168.0.7 7
1 2
2 3
1 3
3 6
6 7
2 7
4 5
5
192.168.0.1 192.168.0.1
192.168.0.1 192.168.0.2
192.168.0.1 192.168.0.6
192.168.0.1 192.168.0.7
192.168.0.3 192.168.0.4
*/