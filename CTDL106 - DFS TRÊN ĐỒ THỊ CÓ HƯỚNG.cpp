#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<bool> check(n + 1, 1);
        vector<vector<int>> a(n + 1);
        stack<int> st;
        while (m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        st.push(u);
        check[u] = 0;
        cout << u << " ";
        while (st.size())
        {
            u = st.top();
            st.pop();
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (check[v])
                {
                    cout << v << " ";
                    check[v] = 0;
                    st.push(u);
                    st.push(v);
                    break;
                }
            }
        }
        cout << endl;
    }
}