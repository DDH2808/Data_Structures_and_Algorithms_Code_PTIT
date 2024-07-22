#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int n, k;
        cin >>n;
        stack<int> st;
        queue<int> q;
        for(int i=1;i<=n;i++){
            int x;
            cin >>x;
            st.push(x);

        }
        while(!st.empty()){
            cout <<st.top() <<' ';
            st.pop();
        }
        cout <<'\n';
    }


   return 0;
}