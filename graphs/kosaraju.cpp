#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Graph
vector<int> comp; // Component of each node

vector<vector<int>> r_adj; // Reversed graph
vector<bool> vis; // Visited nodes
stack<int> s; // Aux stack

void dfs(int u) // Load stack
{
    vis[u] = true;
    
    for(auto v: adj[u])
        if(!vis[v])
            dfs(v);
    
    s.push(u);
}

void scc(int u, int c) // Index the nodes
{
    vis[u] = true;
    comp[u] = c;

    for(auto v: r_adj[u])
        if(!vis[v])
            scc(v, c);
}

int kosaraju()
{
    int n = adj.size();

    vis.assign(n, false);
    for(int u = 0 ; u < n ; u++)
        if(!vis[u])
            dfs(u);
        
    vis.assign(n, false);
    
    int cont = 0;
    while (s.size())
    {
        int u = s.top(); s.pop();
        if(!vis[u])
            scc(u, cont++);
    }

    return cont;
}