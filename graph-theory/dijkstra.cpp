#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    This implementation finds minimum path from start to end or from start to every other node

    If end is passed to the function, it only finds the path from start to end

    c stands for current (cNode = current node)
    n stands for neighbor (nNode = neighbor node)
*/

#define INFLL 0x3f3f3f3f3f3f3f3f

vector<ll> d;
vector<int> p;

void dijkstra(vector<pair<ll, int>>* adj, int n, int start=0, int end=-1)
{
    d.assign(n, INFLL);
    p.assign(n, -1);
    d[start] = 0;
 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
    pq.push({0, start});
 
    while (!pq.empty())
    {
        ll cDist = pq.top().first;
        int cNode = pq.top().second;
 
        pq.pop();
 
        if(cDist > d[cNode]) continue;
        if(cNode == end) return;
 
        for(auto neighbor: adj[cNode])
        {
            ll nDist = neighbor.first;
            int nNode = neighbor.second;
 
            if(d[cNode]+nDist < d[nNode])
            {
                p[nNode] = cNode;
                d[nNode] = d[cNode] + nDist; 
                pq.push({d[nNode], nNode});
            }
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