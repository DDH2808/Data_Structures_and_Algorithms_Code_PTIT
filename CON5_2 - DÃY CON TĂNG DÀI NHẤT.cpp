#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int a[n+5], b[n+5];
        for(int i = 1; i <= n; ++i) cin >>a[i];
        int res = 1;
        b[1] = a[1];
        for(int i = 2; i <= n; ++i){
            int x = lower_bound(b + 1,res + b + 1, a[i]) - b;
            b[x] = a[i];
            res = max(res,x);
        }
        cout <<res <<'\n';
    }

   return 0;
}