#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
bool visited[MAX];
int disc[MAX], low[MAX], parent[MAX];
vector<pair<int, int>> bridge;

void DFS(int u, int time) {
    visited[u] = true;
    disc[u] = low[u] = time++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v, time);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridge.push_back({u, v});
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges(int V) {
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
        disc[i] = low[i] = -1;
        parent[i] = -1;
    }
    bridge.clear();
    int time = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            DFS(i, time);
        }
    }
}

void printBridges() {
    if (bridge.empty()) {
        cout << "NO" << endl;
    } else {
        for (auto& edge : bridge) {
            if (edge.first > edge.second) {
                swap(edge.first, edge.second);
            }
        }
        sort(bridge.begin(), bridge.end());
        for (auto& edge : bridge) {
            cout << edge.first << " " << edge.second << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        findBridges(V);
        printBridges();
    }
    return 0;
}