#include<bits/stdc++.h>
using namespace std;

long long tinh(long long a,long long b,char c){
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
    if(c == '/') return a / b;
}

long long tinh_hau_to(string s){
    stack<long long> st;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            long long a = st.top();st.pop();
            long long b = st.top();st.pop();
            long long tmp = tinh(b,a,s[i]);//phải lấy b trước để đảm bảo thứ tự
            st.push(tmp);
        }
        else{
            st.push((long long)(s[i] - '0'));
        }
    }
    return st.top();
}

void solution(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << tinh_hau_to(s) << endl;
    }
}

int main(){
    solution();
    return 0;
}