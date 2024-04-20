#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

void bfs(vector<int> adjList[], int n, int start, int end, int* distances) // Finds only the distance, not the path itself
{
    bool visited[n] = {false}; // Tells if a node was visited
    for(int i = 0 ; i < n ; i++) // Set all distances as INF
        distances[i] = INF;

    queue<int> q; // Auxiliar queue, stores the next node to be visited in the while loop

    visited[start] = true; // Sets the starting node as visited
    distances[start] = 0; // Sets the distance from starting node to the starting node as 0 
    q.push(start); // We beguin visiting the starting node

    while (!q.empty())
    {
        int currNode = q.front();
        // if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want 
        q.pop();

        for(auto neighbor: adjList[currNode]) if(!visited[neighbor])  // Visits all nodes
        {
            visited[neighbor] = true;
            q.push(neighbor);
            distances[neighbor] = distances[currNode]+1; // When we get here this, distances[currNode]+1 is already the shortest path
            //if(neighbor == end) return; // Makes the bfs faster if finding the path to end is all you want
        }
    }
}

void bfs(vector<int> adjList[], int n, int start, int end, int* distances, int* parents) // Finds the distance and the path
{
    bool visited[n] = {false}; // Tells if a node was visited
    for(int i = 0 ; i < n ; i++) // Set all distances as INF
        distances[i] = INF;
    for(int i = 0 ; i < n ; i++) // Sets all parents as -1 (not valid)
        parents[i] = -1;

    queue<int> q; // Auxiliar queue, stores the next node to be visited in the while loop

    visited[start] = true; // Sets the starting node as visited
    distances[start] = 0; // Sets the distance from starting node to the starting node as 0 
    q.push(start); // We beguin visiting the starting node

    while (!q.empty())
    {
        int currNode = q.front();
        // if(currNode == end) return; // Makes the bfs faster if finding the path to end is all you want
        q.pop();

        for(auto neighbor: adjList[currNode]) if(!visited[neighbor])  // Visits all nodes
        {
            parents[neighbor] = currNode;
            visited[neighbor] = true;
            q.push(neighbor);
            distances[neighbor] = distances[currNode]+1; // When we get here this, distances[currNode]+1 is already the shortest path
            //if(neighbor == end) return; // Makes the bfs faster if finding the path to end is all you want
        }
    }
}

int main()
{    
    int n, m, a, b;
    cin >> n >> m;
    vector<int> adjList[n];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int distances[n], parents[n], end=n-1, start=0;
    bfs(adjList, n, start, end, distances, parents);
     
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