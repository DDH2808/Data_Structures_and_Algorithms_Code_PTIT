#include <bits/stdc++.h>
using namespace std;
int a[105];
bool check(int n){
    int x = sqrt(n);
    return x*x == n;
}
int main()
{
	a[1] = 1, a[2] = 2;
	for(int i = 3; i <= 55; ++i){
        int k = i;
        if(check(k)) a[k] = 1;
        else{
            a[k] = 1e9;
            for(int j = 1; j <= k/2; ++j){
                a[k] = min(a[j]+a[k-j],a[k]);
            }
        }
	}
	int t;
	cin >> t;
	while (t--){
        int n;
        cin >>n;
        cout <<a[n] <<' ';

	}
	return 0;
}