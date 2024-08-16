#include<bits/stdc++.h>
using namespace std;

string a, b;
int n, m;

vector<vector<int>> dp;

int lcs(int i, int j) // longest common subsequence (lcs) ate in [0, i) and [0, j)
{
    if(!i or !j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i-1] == b[j-1])
        return dp[i][j] = 1 + lcs(i-1, j-1);
    else
        return dp[i][j] = max(lcs(i, j-1), lcs(i-1, j));
}

int main()
{
    getline(cin, a);
    getline(cin, b);
    n = a.size();
    m = b.size();

    dp.resize(n+1, vector<int>(m+1, -1));
    cout << lcs(n, m) << endl;
}
