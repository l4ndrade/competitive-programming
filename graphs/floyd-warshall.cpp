#include<bits/stdc++.h>
using namespace std;
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;

/*
    Floy-Warshall algorithm to find minimum distance in a graph with or without negative edges
*/

vector<vector<ll>> d; // Distance from i to j
void floydWarshall()
{
    int n = d.size();
    for (int k = 0; k < n; ++k) 
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) if (d[i][k] < INFLL and d[k][j] < INFLL)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 

}

int main()
{
    int n, m; cin >> n >> m;
    d.resize(n, vector<ll>(n, INFLL));

    int u, v;
    ll w;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    return 0;
}