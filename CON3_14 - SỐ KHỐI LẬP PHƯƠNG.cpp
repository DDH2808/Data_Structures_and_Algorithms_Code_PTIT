#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_set<ll> st;
string S;
ll res = -1;
void Try(string s = "", int i = 0){
if(i == S.length()){
if(s.length() > 0){
if(st.find(stoll(s)) != st.end()){
res = max(res, stoll(s));
}
}
return;
}
Try(s + S[i], i + 1);
Try(s, i + 1);
}
int main(){
int t;
cin >> t;
for(ll i = 1; i <= 100; ++i){
st.insert(i * i * i);
}
while(t--){
res = -1;
cin >> S;
Try();
cout << res << '\n';
}
return 0;
}
