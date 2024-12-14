#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    Prim's minimum spanning tree algorithm
    returns total weight
*/

vector<vector<pair<int, ll>>> adj; // <node, weight>

ll prim(int start=0)
{
    int n = adj.size();

    ll totalWeight = 0; 
    int numTaken = 0; // Number of nodes taken

    vector<bool> taken(n, false); // Stores for every node, if it was taken
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    while (!pq.empty() and numTaken < n)
    {
        auto [w1, u] = pq.top(); pq.pop();

        if(taken[u]) continue;

        taken[u] = true;
        numTaken++;
        totalWeight += w1;

        for(auto [v, w2]: adj[u])
            if(!taken[v])
                pq.push({w2, v});
    }

    return totalWeight;
}