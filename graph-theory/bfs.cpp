#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

vector<int> d, p;

void bfs(vector<int>* adj, int n, int start=0, int end=-1)
{
    d.assign(n, INF);
    p.assign(n, -1);

    d[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cNode = q.front();
        q.pop();
        if(cNode == end) return;
        
        for(auto nNode: adj[cNode]) if(d[nNode] == INF)
        {
            q.push(nNode);
            d[nNode] = d[cNode]+1;
            p[nNode] = cNode;
        }
    }
}

vector<int> restore_path(int start, int end)
{
    vector<int> res;
    for(int node = end ; node != start ; node = p[node])
        res.push_back(node);
    
    res.push_back(start);
    reverse(res.begin(), res.end());
    return res;
}