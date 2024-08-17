#include<bits/stdc++.h>
using namespace std;

/*
    dp aproach to get the number of ways we can get to value n with a set of coins (O(n*m) where n is the value and m the size of the coin set)
*/

vector<int> c; // All coin values
vector<int> ways; // Ways to get to value i

void fill()
{
    ways[0] = 1;
    for(auto coin: c)
        for(int i = 0 ; i+coin <= ways.size() ; i++)
            if(ways[i])
                ways[i+coin] += ways[i];
}

int main()
{
    int n, value; cin >> n >> value;
    c.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> c[i];
    ways.resize(value+1, 0);
    fill();
    cout << ways[value] << endl;
}