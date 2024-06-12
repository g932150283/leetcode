#include <bits/stdc++.h>
using namespace std;


int res = 0;
// int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int path = 0;
int tili = 0;

void dfs(int x, int y,int m, int n, vector<vector<int>> visited){
    if(path == tili){
        res++;
        return;
    }
    if(path > tili){
        return;
    }
    
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    for(int i = 0;i < 4; i++){
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if(x1 < 0 || x1 > m || y1 < 0 || y1 > n || visited[x1][y1] == 1){
            continue;
        }else{
            path++;
            visited[x1][y1] = 1;
            dfs(x1, y1, m, n, visited);
            visited[x1][y1] = 0;
            path--;
        }
    }
}
int main() {
    int k, m, n;
    while (cin >> k >> m >> n) { // 注意 while 处理多个 case
        if(k < m + n){
            cout << 0 << endl;
        }else{
            vector<vector<int>> visited(m+1, vector<int>(n+1, 0));
            res = 0;
            path = 0;
            tili = m + n;
            // cout << rand() << endl;
            visited[0][0] = 1;
            dfs(0,0, m, n, visited);
            cout << res << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")