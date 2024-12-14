#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Graph
vector<int> low, tin; // lowest tin that can be reached from a node; time of discovery

vector<bool> is_cutpoint;
set<pair<int, int>> bridges;

int t = 0;

void tarjan(int u, int p)
{
    low[u] = tin[u] = t++;

    int children = 0;

    for(auto v: adj[u]) if(v != p)
    {
        
        if(tin[v] != -1) // Visited
            low[u] = min(low[u], tin[v]); // Check if v has lower tin
        else // Not visited
        {
            tarjan(v, u);

            low[u] = min(low[u], low[v]); // Check is v has lower `low`

            if(low[v] >= tin[u] and p != -1) // If low[v] is not lower than u (No back-edge)
                is_cutpoint[u] = true;
            
            if(tin[u] < low[v]) // If low[v] is not lower than or equal to u (No back-edge)
                bridges.insert({min(u, v), max(u, v)});
            
            children++;
        }
    }

    // Checks for when the root is a cutpoint
    if(p == -1 and children > 1)
        is_cutpoint[u] = true;
}