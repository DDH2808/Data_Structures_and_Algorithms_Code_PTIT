#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
	cin >> t;
	while(t--){
        int s, t;
        cin >> s >> t;
        pair<int, int> u;
        u.first = s;
        u.second = 0;
        map<int, int> mp;
        queue<pair<int, int>> q;
        q.push(u);
        while (q.size()){
            u = q.front();q.pop();
            if (u.first == t){
                cout << u.second <<'\n';
                break;
            }
            if (u.first <= t && !mp[u.first * 2]){
                mp[u.first * 2]++;
                q.push({u.first * 2, u.second + 1});
            }
            if (u.first > 1 && !mp[u.first - 1]){
                mp[u.first - 1]++;
                q.push({u.first - 1, u.second+ 1});
            }
        }
	}

   return 0;
}