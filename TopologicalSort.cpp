#include <bits/stdc++.h>
using namespace std;

class graph {
public:
  void addEdge(int v, int u, unordered_map<int, set<int>> &adj) {
    adj[u].insert(v);
  }
};
void topodfs(unordered_map<int, set<int>> &adj,
             unordered_map<int, bool> &visited, int node, stack<int> &s) {
  visited[node] = true;
  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      topodfs(adj, visited, neighbour, s);
    }
  }
  s.push(node);
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
  stack<int> s;
  bool result = 0;
  for (int i = 0; i <= n; i++) {
    if (!visited[i]) {
      topodfs(adj, visited, i, s);
    }
  }
  while (s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
}