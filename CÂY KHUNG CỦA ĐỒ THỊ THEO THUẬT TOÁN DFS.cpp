#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()

inline void DFS(int x, vector<vector<int>> &a, bitset<1005> &bs, vector<pair<int, int>> &vp)
{
    bs[x] = 1;
    for(int &i : a[x])
    {
        if(!bs[i])
        {
            vp.pb({x, i});
            DFS(i, a, bs, vp);
        }
    }
}

int main()
{
    int t = 1, e, v, u, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e >> u;
        vector<vector<int>> a(v + 5);
        bitset<1005> bs;
        vector<pair<int, int>> res;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        DFS(u, a, bs, res);
        if(res.sz == v - 1)
            for(pair<int, int> &i : res)
                cout << i.fi << ' ' << i.se << endl;
        else cout << -1 << endl;
    }
    return 0;
}