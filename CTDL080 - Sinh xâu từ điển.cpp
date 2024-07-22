#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
        string s;
        cin >>s;
        int n = s.size();
        for(int i = 0; i < n; ++i) if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' -'A';
        int dp[404]={}, mx=-1e9;
        for(int i = 0; i < n; ++i){
            dp[s[i]] = max(dp[s[i]], 1);
            for(int j = 'a'; j < s[i]; ++j){
                dp[s[i]] = max(dp[s[i]], dp[j]+1);
            }
            mx = max(mx, dp[s[i]]);
        }
        cout <<mx <<'\n';

	}
	return 0;
}