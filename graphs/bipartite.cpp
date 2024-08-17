#include<bits/stdc++.h>
using namespace std;

vector<int> color;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int curr, bool& isBipartite)
{
    if(visited[curr]) return;
    visited[curr] = true;
    for(auto e: adj[curr])
    {
            if(color[e] == -1)
            {
                color[e] = color[curr] == 0 ? 1 : 0;
                dfs(e, isBipartite);
            }
            else if(color[e] == color[curr])
            {
                // ends the executuion as soon as possible
                isBipartite = false;
                visited.assign(visited.size(), true);
                return;
            }
    }
}

bool isBipartite() // Runs a dfs starting in every node (every component needs to be searched)
{
    bool res;
    for(int i = 0 ; i < adj.size() ; i++)
        dfs(i, res);
    return res;
}