#include <bits/stdc++.h>
using namespace std;
string ts = "+-*/^";
bool check(char c)
{
    for (int i = 0; i < ts.size(); i++)
        if (ts[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ans;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            if (check(s[i]))
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                k = "(" + k + ")";
                st.push(k);
            }
        }
        s = st.top();
        while (!st.empty())
            st.pop();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (Var(s[i]))
                ans = s[i] + ans;
            if (check(s[i]))
                st.push(string(1, s[i]));
            if (s[i] == '(')
            {
                ans = st.top() + ans;
                st.pop();
            }
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}
