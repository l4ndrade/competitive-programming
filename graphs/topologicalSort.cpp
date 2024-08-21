#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs(int v)
{
    if(visited[v]) return;

    visited[v] = true;
    for(int u: adj[v])
        dfs(u);
    ans.push_back(v);
}

void topoSort(int n)
{
    visited.assign(n, false);
    ans.clear();

    for(int i = 0 ; i < n ; i++)
        dfs(i);
    reverse(all(ans));
}

