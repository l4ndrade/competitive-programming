#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

void dijkstra(vector<pair<int, int>>* adj, int n, int start, int end, int* distance) // Finds only the distance, not the path itself
{
    for(int i = 0 ; i < n ; i++) distance[i] = INF; // Set all distances as INF

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Minimum priority queue <distance, node>
    distance[start] = 0; // Sets the distance from starting node to the starting node as 0 
    pq.push({0, start}); // We beguin visiting the starting node

    while (!pq.empty())
    {
        int currDist = pq.top().first, currNode = pq.top().second; 
        pq.pop();

        //if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want
        if(currDist > distance[currNode]) continue; // Mean a better path was already found

        for(auto neighbor: adj[currNode])
        {
            int neighborDist = neighbor.first, neighborNode = neighbor.second;
            if(distance[currNode]+neighborDist < distance[neighborNode])  // Visits all nodes
            {
                distance[neighborNode] = distance[currNode]+neighborDist;
                pq.push({distance[neighborNode], neighborNode});
            }
        }
    }
}

void dijkstra(vector<pair<int, int>>* adj, int n, int start, int end, int* distance, int* parent) // Finds the distance and the path
{
    for(int i = 0 ; i < n ; i++) distance[i] = INF; // Set all distances as INF
    for(int i = 0 ; i < n ; i++) parent[i] = -1; // Sets all parents as -1 (not valid)
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Minimum priority queue <distance, node>
    distance[start] = 0; // Sets the distance from starting node to the starting node as 0 
    pq.push({0, start}); // We beguin visiting the starting node

    while (!pq.empty())
    {
        int currDist = pq.top().first, currNode = pq.top().second; 
        pq.pop();

        //if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want
        if(currDist > distance[currNode]) continue; // Mean a better path was already found

        for(auto neighbor: adj[currNode])
        {
            int neighborDist = neighbor.first, neighborNode = neighbor.second;
            if(distance[currNode]+neighborDist < distance[neighborNode])  // Visits all nodes
            {
                parent[neighborNode] = currNode;
                distance[neighborNode] = distance[currNode]+neighborDist;
                pq.push({distance[neighborNode], neighborNode});
            }
        }
    }
}

int main()
{    
    int n, m, a, b, c;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int distance[n], parents[n], end=n-1, start=0;
    dijkstra(adj, n, start, end, distance, parents);
     
    vector<int> path;
    if(distance[end] != INF) // Checks if there is a path
    {
        for(int i = end ; i != -1 ; i = parents[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for(auto node: path)
            cout << node << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}