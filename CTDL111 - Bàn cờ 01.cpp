#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e7 + 7;
const int mod = 1e9 + 7;
void implement(){
    int n ;
    cin >> n ;
    if(n == 1){
        cout << 1 ;
        return ;
    }
    cout << 2*(n-1);
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        implement();
        cout << endl;
    }
    return 0;
}