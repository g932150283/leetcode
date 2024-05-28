#include <bits/stdc++.h>

using namespace std;

/*
atkper 30
1
spd 4

atk 100
2
spd 30
atk 50

def 10
1
atkper 20

atkper 30
4
atk 150
def 20
spd 5
atkper 20

spd 15
0

atk 100
1
spd 5
*/
pair<string, long> getD(string s)
{
    int i = 0;
    int l = 0;
    while (s[l] != ' ')
    {
        l++;
        /* code */
    }
    string s1 = s.substr(i, l);
    string s2 = s.substr(l + 1, s.size());
    long i2 = stol(s2);
    return {s1, i2};
}

int main()
{

    string s1;
    while (cin >> s1)
    {
        // vector<int> a1;
        // vector<int> a2;
        // vector<int> d;
        // vector<int> s;
        // unordered_set<string> four;
        // four.insert("atk");
        // four.insert("atkper");
        // four.insert("def");
        // four.insert("spd");

        unordered_map<string, long> umap;
        umap.clear();

        // string s1;
        // cin >> s1;
        long a1;
        cin >> a1;
        umap[s1] = umap[s1] + a1;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s2;
            cin >> s2;
            long a2;
            cin >> a2;
            umap[s2] = umap[s2] + a2;
        }
            // string sss;
            // cin >> sss;


        for (int i = 1; i < 6; i++)
        {
            string s1;
            cin >> s1;
            long a1;

            cin >> a1;
            umap[s1] = umap[s1] + a1;
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                string s2;
                cin >> s2;
                long a2;
                cin >> a2;
                umap[s2] = umap[s2] + a2;
            }
            // if (i < n - 1)
            // {
            //     string sss;
            //     cin >> sss;
            // }
        }
        cout << "atk" << " " << umap["atk"] << endl;
        cout << "atkper" << " " << umap["atkper"] << endl;
        cout << "def" << " " << umap["def"] << endl;
        cout << "spd" << " " << umap["spd"] << endl;

        /* code */
    }

    return 0;
}