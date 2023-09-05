#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    void addEdge(int v, int u, unordered_map<int, set<int>>& adj) {
        adj[u].insert(v);
        adj[v].insert(u); 
    }
};
void bfs(unordered_map<int, set<int>> adj, unordered_map<int, bool> visited,vector<int> ans,int node,unordered_map<int,bool>&parent){
  parent[node] =-1;
  visited[node] =1;
  queue<int> q;
  q.push(node);
    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();
        for (auto i : adj[frontnode]) {
            if(!visited[i]){
               q.push(i);
               parent[i] = frontnode;
               visited[i] = 1;
            }
        }
    }
}
void shortestpath(unordered_map<int,int>parent,int target,vector<int>&ans){
  int current = target;
  ans.push_back(current);

  while(target==1){
     shortestpath(parent,parent[current],ans);
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
        g.addEdge(u, v, adj);
    }
    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int,int>parent;
    for (int i = 0; i < n; i++) { 
        if (!visited[i]) 
          bfs(adj, visited, ans, i,parent);
    }
   reverse(ans.begin(),ans.end());
}
