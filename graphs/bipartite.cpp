#include<bits/stdc++.h>
using namespace std;

/*
    DFS used to check if a graph is bipartite
*/ 

vector<int> color; // colors are 0 or 1 and -1 means it is not colored yet
vector<vector<int>> adj;

bool colorize(int curr, int value) // Tries to bipart the component, returns if it could do it
{
    color[curr] = value;
    for(auto e: adj[curr])
    {
        if(color[e] == color[curr]) // Neighboor with the same color -> not bipartite
            return false;
        if(color[e] == -1)
        {
            color[e] = value == 0 ? 1 : 0;
            if(!colorize(e, !value))
                return false;
        }
    }
    return true;
}

bool isBipartite() // Runs a dfs starting in every node (every component needs to be searched)
{
    for(int i = 0 ; i < adj.size() ; i++)
        if(color[i] != -1 and !colorize(i, 0))
            return false;
    return true;
}