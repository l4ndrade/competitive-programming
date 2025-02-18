#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// Max flow using Edmonds-Karp algorithm

vector<vector<int>> cap;
vector<vector<int>> adj;

// Searches for augmenting path
int bfs(int s, int t, vector<int>& parent) 
{
    parent.assign(parent.size(), -1);
    parent[s] = s; // No parent

    queue<pair<int, int>> q; // {vertex, flow}
    q.push({s, INF});

    while (q.size()) 
    {
        int curr, flow; // Vertex, flow
        curr = q.front().first; flow = q.front().second; q.pop();

        for (auto next: adj[curr])
        {
            // For each not visited vertex with cap > 0 
            if (parent[next] == -1 and cap[curr][next]) 
            {
                parent[next] = curr;

                int path_flow = min(flow, cap[curr][next]);

                if (next == t) // Found the augmenting path
                    return path_flow;
                
                q.push({next, path_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, int n) 
{
    int flow = 0, path_flow;
    vector<int> parent(n);

    while (path_flow = bfs(s, t, parent)) 
    {
        int curr = t;
        flow += path_flow;

        // Update capacities
        while (curr != s) 
        {
            int prev = parent[curr];
            cap[prev][curr] -= path_flow; // Direct
            cap[curr][prev] += path_flow; // Reverse
            curr = prev;
        }
    }

    return flow;
}