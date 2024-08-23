#include<bits/stdc++.h>
using namespace std;

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

    void make_set(int v) 
    {
        parent[v] = v;
        r[v] = 0;
    }

    int find_set(int v) 
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
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