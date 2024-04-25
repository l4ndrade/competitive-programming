#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

void bfs(vector<int>* adj, int n, int start, int end, int* distance) // Finds only the distance, not the path itself
{
    bool visited[n] = {false}; // Tells if a node was visited
    for(int i = 0 ; i < n ; i++) // Set all distances as INF
        distance[i] = INF;

    queue<int> q; // Auxiliar queue, stores the next node to be visited in the while loop

    visited[start] = true; // Sets the starting node as visited
    distance[start] = 0; // Sets the distance from starting node to the starting node as 0 
    q.push(start); // We beguin visiting the starting node

    while (!q.empty())
    {
        int currNode = q.front();
        // if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want 
        q.pop();

        for(auto neighbor: adj[currNode]) if(!visited[neighbor])  // Visits all nodes
        {
            visited[neighbor] = true;
            q.push(neighbor);
            distance[neighbor] = distance[currNode]+1; // When we get here this, distances[currNode]+1 is already the shortest path
            //if(neighbor == end) return; // Makes the bfs faster if finding the path to end is all you want
        }
    }
}

void bfs(vector<int>* adj, int n, int start, int end, int* distance, int* parent) // Finds the distance and the path
{
    bool visited[n] = {false}; // Tells if a node was visited
    for(int i = 0 ; i < n ; i++) // Set all distances as INF
        distance[i] = INF;
    for(int i = 0 ; i < n ; i++) // Sets all parents as -1 (not valid)
        parent[i] = -1;

    queue<int> q; // Auxiliar queue, stores the next node to be visited in the while loop

    visited[start] = true; // Sets the starting node as visited
    distance[start] = 0; // Sets the distance from starting node to the starting node as 0 
    q.push(start); // We beguin visiting the starting node

    while (!q.empty())
    {
        int currNode = q.front();
        // if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want
        q.pop();

        for(auto neighbor: adj[currNode]) if(!visited[neighbor])  // Visits all nodes
        {
            parent[neighbor] = currNode;
            visited[neighbor] = true;
            q.push(neighbor);
            distance[neighbor] = distance[currNode]+1; // When we get here this, distances[currNode]+1 is already the shortest path
            //if(neighbor == end) return; // Makes the bfs faster if finding the path to end is all you want
        }
    }
}

int main()
{    
    int n, m; // number of nodes and edges
    int a, b; // Aux
    cin >> n >> m;
    vector<int> adj[n];

    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int distance[n], parent[n], end, start;
    
    start = 0;
    end = n-1;

    bfs(adj, n, start, end, distance, parent);
     
    vector<int> path;
    if(distance[end] != INF) // Checks if there is a path
    {
        for(int i = end ; i != -1 ; i = parent[i])
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