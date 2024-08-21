#include<bits/stdc++.h>
using namespace std;

/*
    Using bfs to find shortest path in a graph
*/

#define INF 0x3f3f3f3f
vector<int> d, p;
vector<vector<int>> adj;

void bfs(int start=0, int end=-1)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front(); q.pop();
        if(curr == end) return;
        
        for(auto nei: adj[curr]) if(d[nei] == INF)
        {
            q.push(nei);
            d[nei] = d[curr]+1;
            p[nei] = curr;
        }
    }
}

void restore_path(int start, int end, vector<int>& res)
{
    res.clear();
    for(int u = end ; u != start ; u = p[u])
        res.push_back(u);
    
    res.push_back(start);
    reverse(res.begin(), res.end());
}