#include <bits/stdc++.h>
using namespace std;
int a[105], b[105],n, k, ok, m, cnt;
void Try(int pos1, int pos2, int s){
    for(int i = pos1 + 1; i <= n; ++i){
        if(s + a[i] == k){
            ok=1;
            b[pos2+1] = a[i];
            if(pos2 + 2 == m) cnt++;
        }
        else if(s + a[i] < k){
            b[pos2+1] = a[i];
            Try(i, pos2+1, s + a[i]);
        }
    }
}
int main()
{
    int t;
    cin >>t;
    while(t--){
        ok=0, cnt=0;
        cin >>n >> m>>k;
        for(int i = 1; i <= n; ++i) cin >>a[i];
        sort(a + 1, a + n + 1);
        Try(0,-1,0);
        cout <<cnt;
        cout <<'\n';
    }

   return 0;
}