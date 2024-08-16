#include<bits/stdc++.h>
using namespace std;

#define value first
#define weight second
vector<pair<int, int>> v; // knapsack
vector<vector<int>> dp; // dp table (has to be initialized)

int maximize(int i, int j) // Greatest value using items in [0, i) using at max j capacity
{
    if(!i or !j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(j-v[i-1].weight >= 0)
        return dp[i][j] = max(maximize(i-1, j), maximize(i-1, j-v[i-1].weight)+v[i-1].value);
    else
        return maximize(i-1, j);
}

int main()
{
    int n, maxCapacity, sum = 0;
    cin >> n >> maxCapacity;
    v.resize(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i].value >> v[i].weight;
        sum+=v[i].value;
    }

    dp.resize(n+1, vector<int>(sum+1, -1));
    
    cout << maximize(n, maxCapacity) << endl;

}