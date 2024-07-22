#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1005];
int n,m;
bool check[1005];


void init(){
    cin >> n >> m;
    for(int i = 1;i <= 1005;i++){
        arr[i].clear();
    }
    for(int i = 1;i <= m;i++){
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    memset(check,true,sizeof(check));
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    check[u] = false;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i = 0;i < arr[s].size();i++){
            if(check[arr[s][i]]){
                q.push(arr[s][i]);
                check[arr[s][i]] = false;
            }
        }
    }
}

void solution(){
    int t;
    cin >> t;
    while(t--){
        init();
        int count = 0;
        for(int i = 1;i <= n;i++){
            if(check[i]){
                count++;
                BFS(i);
            }
        }
        cout << count << endl;
    }
}

int main(){
    solution();
    return 0;
}