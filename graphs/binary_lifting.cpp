#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

struct Binary_Lifting
{
    int n; // number of nodes
    int l; // log(n)
    vector<vector<int>> ancestor;
    vector<int> tin, tout;
    int t; // Timter

    // loads tin, tout and ancestor[u][0]
    void dfs(int u, int p)
    {
        tin[u] = t++;
        ancestor[u][0] = p;

        for (int v : adj[u]) if (v != p)
            dfs(v, u);
        
        tout[u] = t++;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    }

    // lower common ancestor
    int lca(int u, int v)
    {
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        
        // Moves u up until u is directly below an ancestor of v
        for(int i = l-1 ; i >= 0 ; i--)
            if(ancestor[u][i] != -1 and !is_ancestor(ancestor[u][i], v))
                u = ancestor[u][i];

        // Returns the node above u
        return ancestor[u][0];
    }

    int kth(int u, int k)
    {
        for(int i = l-1 ; i >= 0 ; i--)
            if(k >= (1 << i))
            {            
                u = ancestor[u][i];
                k -= (1 << i);
            
                if(u == -1)
                    return -1;
            }

        return u;
    }

    Binary_Lifting(int root)
    {
        n = adj.size();
        tin.resize(n);
        tout.resize(n);

        t = 0;
        l = ceil(log2(n)) + 2;
        ancestor.assign(n, vector<int>(l, -1));
        dfs(root, -1);
        
        // dp to calculate uuper ancestors
        for(int i = 1 ; i < l ; i++)
            for(int u = 0 ; u < n ; u++) if(ancestor[u][i-1] != -1)
                ancestor[u][i] = ancestor[ancestor[u][i-1]][i-1];
    }
};