#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(int i=a; i<=b; ++i)
const int MOD=1e9+7;

using namespace std;
int s[15], a[15], z[15], ans=MOD, mx, b[15];
void Try(int k){
  int num=0;
  while(k){
    int x=k&1, ok=1;
    f(i,1,6) if(s[i]!=a[i]){ok=0; break;}
    if(ok) {ans=min(ans,num); break;}
    num++;
    k>>=1;
    f(i,1,6) z[i]=s[i];
    if(!x){
      s[1]=z[4], s[2]=z[1], s[4]=z[5], s[5]=z[2];
    }
    else{
      s[2]=z[5], s[3]=z[2], s[5]=z[6], s[6]=z[3];
    }
  }
}
int main()
{
    f(i,1,6) cin >> s[i], b[i]=s[i];
    f(i,1,6) cin >> a[i];
    mx=1<<20;
    f(j,0,mx){
        f(i,1,6) s[i]=b[i];
        Try(j);
    }
    cout<<ans;

   return 0;
}