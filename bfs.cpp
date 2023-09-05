#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    void addEdge(int v, int u, unordered_map<int, set<int>>& adj) {
        adj[u].insert(v);
        adj[v].insert(u); // Add this line for undirected graph
    }
};

void bfs(unordered_map<int, set<int>>& adj, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for (auto i : adj[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    cout << "enter the no of nodes" << endl;
    cin >> n;
    int m;
    cout << "enter the no of edges" << endl;
    cin >> m;
    graph g;
    unordered_map<int, set<int>> adj;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, adj);
    }
    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) { // Iterate over all nodes
        if (!visited[i])
            bfs(adj, visited, ans, i);
    }
    cout << endl;
    for (auto i : ans) {
        cout << i << " ";
    }
}
