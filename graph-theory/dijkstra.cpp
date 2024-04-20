#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

void dijkstra(vector<pair<int, int>> adjList[], int n, int start, int end, int* distances) // Finds only the distance, not the path itself
{
    for(int i = 0 ; i < n ; i++) // Set all distances as INF
        distances[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Minimum priority queue <distance, node>
    distances[start] = 0; // Sets the distance from starting node to the starting node as 0 
    pq.push({0, start}); // We beguin visiting the starting node

    while (!pq.empty())
    {
        int currDist = pq.top().first, currNode = pq.top().second; 
        pq.pop();

        //if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want
        if(currDist > distances[currNode]) continue; // Mean a better path was already found

        for(auto neighbor: adjList[currNode])
        {
            int neighborDist = neighbor.first, neighborNode = neighbor.second;
            if(distances[currNode]+neighborDist < distances[neighborNode])  // Visits all nodes
            {
                distances[neighborNode] = distances[currNode]+neighborDist;
                pq.push({distances[neighborNode], neighborNode});
            }
        }
    }
}

void dijkstra(vector<pair<int, int>> adjList[], int n, int start, int end, int* distances, int* parents) // Finds the distance and the path
{
    for(int i = 0 ; i < n ; i++) // Set all distances as INF
        distances[i] = INF;
    for(int i = 0 ; i < n ; i++) // Sets all parents as -1 (not valid)
        parents[i] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Minimum priority queue <distance, node>
    distances[start] = 0; // Sets the distance from starting node to the starting node as 0 
    pq.push({0, start}); // We beguin visiting the starting node

    while (!pq.empty())
    {
        int currDist = pq.top().first, currNode = pq.top().second; 
        pq.pop();

        //if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want
        if(currDist > distances[currNode]) continue; // Mean a better path was already found

        for(auto neighbor: adjList[currNode])
        {
            int neighborDist = neighbor.first, neighborNode = neighbor.second;
            if(distances[currNode]+neighborDist < distances[neighborNode])  // Visits all nodes
            {
                parents[neighborNode] = currNode;
                distances[neighborNode] = distances[currNode]+neighborDist;
                pq.push({distances[neighborNode], neighborNode});
            }
        }
    }
}

int main()
{    
    int n, m, a, b, c;
    cin >> n >> m;
    vector<pair<int, int>> adjList[n];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        adjList[a].push_back({c, b});
        adjList[b].push_back({c, a});
    }
    int distances[n], parents[n], end=n-1, start=0;
    dijkstra(adjList, n, start, end, distances, parents);
     
    vector<int> path;
    if(distances[end] != INF) // Checks if there is a path
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