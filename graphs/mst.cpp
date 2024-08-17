#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    Prim's minimum spanning tree algorithm
    returns total weight
*/

vector<vector<pair<ll, int>>> adj;

ll prim(int start)
{
    int n = adj.size();
    ll totalWeight = 0; 
    int numUsed = 0; // Number of nodes used
    vector<bool> used(n, false);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    while (pq.size() and numUsed < n)
    {
        ll dist = pq.top().first, curr = pq.top().second; pq.pop();

        if(used[curr]) continue;

        used[curr] = true;
        numUsed++;
        totalWeight += dist;

        for(auto e: adj[curr])
        {
            ll distToNei, nei;
            distToNei = e.first;
            nei = e.second;

            if(!used[nei])
                pq.push({distToNei, nei});
        }
    }

    return totalWeight;
}