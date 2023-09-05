#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    void addEdge(int v, int u, unordered_map<int, set<int>>& adj) {
        adj[u].insert(v);
    }
};
bool  cyclicdfs(unordered_map<int, set<int>>& adj, unordered_map<int, bool>&visited,int node,int parent,unordered_map<int,bool>&dfsvisited;){
  visited[node] = true;
  dfsvisited[node] = true;
  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool result =  cyclicdfs(adj,visited,neighbour,node,dfsvisited);
      if(result) return true;
    }
    else if(dfsvisited[neighbour] && visited[node]){
      return true;
    }
  }
  dfsvisited[node] = false;
  return false;
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
        // Creating an directed graph
        g.addEdge(u, v, adj);
    }
    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int,bool>dfsvisited;
    bool result = 0;
    for (int i = 1; i <= n; i++) { // Iterate over all nodes
        if (!visited[i]){
         result = cyclicdfs(adj, visited,i, -1,dfsvisited);
          if(result==1){
            cout<<"YES"<<endl;
            break;
          }
        }
            
    }
    if(result==0){
      cout<<"NO"<<endl;
    }
}
