#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--){
        string s;
        int k;
        cin >> k >>s;
        int n = s.size();
        for(int i=0;i<=n-1;i++){
            char l = s[n-1];
            int vt = n-1;
            for(int j = n-1; j > i && k > 0; --j){
                if(l < s[j]) l = s[j], vt=j;
            }
            if(l > s[i] && k > 0) swap(s[i],s[vt]),k--;
        }
        cout <<s <<'\n';

	}
	return 0;
}
