#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFLL 0x3f3f3f3f3f3f3f3f

vector<ll> d;
vector<int> p;
vector<vector<pair<int, ll>>> adj;

void dijkstra(int start=0, int end=-1)
{
    int n = adj.size();

    d.assign(n, INFLL);
    p.assign(n, -1);
 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
    d[start] = 0;
    pq.push({0, start});
 
    while (!pq.empty())
    {
        auto [w1, u] = pq.top(); pq.pop(); 
        
        if(w1 > d[u]) continue;
        if(u == end) return;
 
        for(auto [v, w2]: adj[u])
        {

            if(d[u]+w2 < d[v])
            {
                p[v] = u;
                d[v] = d[u] + w2; 
                pq.push({d[v], v});
            }
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