#include<bits/stdc++.h>
using namespace std;

void xu_ly(){
    vector<int> arr[1005];
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    for(int i = 1;i <= n;i++){
        cout << i << ": ";
        for(int j = 0;j < arr[i].size();j++){
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

void solution(){
    int t;
    cin >> t;
    while(t--){
        xu_ly();
    }
}

int main(){
    solution();
    return 0;
}