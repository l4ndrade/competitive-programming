#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int n, m;
vector<int> d(n, INF);
vector<pair<int, int>> edges;
vector<int> w; // weights

// Returns true if there's a negative weight cycle
bool bellman_ford(int u)
{
    d[u] = 0;
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(d[edges[j].second] > d[edges[j].first] + w[j])
            {
                if(i == n) return true;
                d[edges[j].second] = d[edges[j].first] + w[j];
            }
        }
    }

    return false;
}