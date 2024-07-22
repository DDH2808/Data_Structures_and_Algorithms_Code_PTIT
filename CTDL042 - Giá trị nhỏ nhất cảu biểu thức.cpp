#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a1(n), a2(n);
        for(int i = 0; i < n; ++i)
        	cin >> a1[i];
        for(int i = 0; i < n; ++i)
        	cin >> a2[i];
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end(), greater<ll>());
        ll res = 0;
        for(int i = 0; i < n; ++i){
        	res += a1[i] * a2[i];
        }
        cout << res << '\n';
    }
    return 0;
}
