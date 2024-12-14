#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dsu
{
    vector<int> parent; // parent of a node (not always the root of the tree)
    vector<int> r; // rank
    int n; // number of nodes

    dsu(int n)
    {
        parent.resize(n);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
        r.resize(n);
        for(int i = 0 ; i < n ; i++)
            r[i] = 0;
    }

    void make(int v) 
    {
        parent[v] = v;
        r[v] = 0;
    }

    int find(int v) 
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b) 
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if(r[a] < r[b])
                swap(a, b);
            parent[b] = a;
            if(r[a] == r[b])
                r[a]++;
        }
    }
};

vector<pair<int, pair<int, int>>> edg; // [w, u, v], store all edges in the graph

ll kruskal(int n, vector<pair<int, pair<int, int>>>& mst_edges)
{
    dsu dsu(n); // DSU in O(a(n))

    sort(edg.begin(), edg.end());

    ll cost = 0;
    for(auto [w, e]: edg)
    {
        auto [u, v] = e;
        if(dsu.find(u) != dsu.find(v))
        {
            mst_edges.push_back({w, {u, v}});
            cost += w;
            dsu.unite(u, v);
        }
        
    }

    return cost;
}