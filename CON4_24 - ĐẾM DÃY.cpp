#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 123456789;

ll Pow(ll n, ll k){
	ll res = 1;
	while(k){
		if(k&1){
			res *= n;
			res %= mod;
		}
		n *= n;
		n %= mod;
		k >>= 1;
	}
	return res;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;
		cout << Pow(2, n - 1) << '\n';
	}	
	return 0;
}