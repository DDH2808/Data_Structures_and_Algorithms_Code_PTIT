#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size(), ans = 1;
		vector<vector<bool>> a(n, vector<bool>(n));
		for (int i = 0; i < n; i++)
			a[i][i] = 1;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n - i; j++)
			{
				int k = i + j;
				a[j][k] = ((j + 1 > k - 1 || a[j + 1][k - 1]) && s[j] == s[k]);
				if (a[j][k])
					ans = i + 1;
			}
		cout << ans << endl;
	}
}