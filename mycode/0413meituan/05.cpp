#include <bits/stdc++.h>
using namespace std;

unordered_set<string> uset;
string path;

// true 不重复
bool isCopy(string &str)
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }
    return true;
}
void backtracking(string &str, int index, int num)
{
    if (path.size() == str.size() - num && isCopy(path))
    {
        cout << path << endl;
        uset.insert(path);
    }

    for (int i = index; i <= str.size() - num; i++)
    {
        path = "";
        string p1 = "";
        string p2 = "";
        if (i == 0)
        {
            p2 = p2 = str.substr(i + num, str.size());
        }
        else if (i + num == str.size())
        {
            p1 = p1 = str.substr(0, i);
        }
        else
        {

            p1 = str.substr(0, i);
            p2 = str.substr(i + num, str.size());
        }

        path = p1 + p2;

        backtracking(str, i + 1, num);
    }
}

int main()
{
    string s;
    while (cin >> s)
    {
        int res = 0;
        for (int i = 1; i <= s.size() - 1; i++)
        {
            cout << i << "==================" << endl;
            backtracking(s, 0, i);
            res = res + uset.size();
            uset.clear();
        }
        if (isCopy(s))
        {
            res++;
        }
        cout << res << endl;
    }
}
// 64 位输出请用 printf("%lld")