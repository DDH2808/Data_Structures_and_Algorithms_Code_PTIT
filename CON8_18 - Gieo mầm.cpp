#include <bits/stdc++.h>
using namespace std;
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
struct data
{
    int x, y, s;
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m, ans = 0;
        cin >> n >> m;
        int a[n + 1][m + 1];
        struct data u, v;
        queue<struct data> q;
        u.s = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
                if (a[i][j] == 2){
                    u.x = i;
                    u.y = j;
                    q.push(u);
                }
            }
        }
        while (q.size()){
            u = q.front();
            q.pop();
            ans = max(ans, u.s);
            for (int i = 0; i < 4; i++){
                v.x = u.x + rx[i];
                v.y = u.y + ry[i];
                if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && a[v.x][v.y] == 1)
                {
                    a[v.x][v.y] = 2;
                    v.s = u.s + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == 1)
                    ans = -1;
        cout << ans << endl;
    }
}