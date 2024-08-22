#include<bits/stdc++.h>
using namespace std;

/*
    Larger increasing subsequence
*/

vector<int> v;
vector<int> dp;

int lis(int i) // lis in v[0, i]
{
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];

    int res = 1;
    for(int j = 0 ; j < i ; j++)
    {
        if(v[j] < v[i])
            res = max(res, lis(j)+1);
        else
            res = max(res, lis(j));
    }
    return dp[i] = res;
}

int main()
{
    int n; cin >> n;
    v.resize(n);
    dp.resize(n, -1);
    for(int i= 0 ; i < n ; i++)
        cin >> v[i];
    cout << lis(n-1) << endl;
}
