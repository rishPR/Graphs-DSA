#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    void addEdge(int v, int u, unordered_map<int, set<int>>& adj) {
        adj[u].insert(v);
        adj[v].insert(u); // Add this line for undirected graph
    }
};
void dfs(unordered_map<int, set<int>>& adj, unordered_map<int, bool>&visited,vector<int>& ans,int node){
  ans.push_back(node);
  visited[node] = true;
  for(auto i:adj[node]){
    if(!visited[i]){
      dfs(adj,visited,ans,i);
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
            dfs(adj, visited, ans, i);
    }
    cout << endl;
    for (auto i : ans) {
        cout << i << " ";
    }
}
