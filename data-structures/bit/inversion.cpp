/*
    Using BIT to count the number of inversions to sort an array in O(nlog(n))
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#include"bit.cpp"
#include"compression.cpp"

ll countInversions(vector<ll>& v) 
{
    int n = v.size();
    v = get_compressed(v);

    Bit bit(n);
    ll invCount = 0;

    for (int i = n-1; i >= 0; i--) 
    {
        invCount += bit.query(v[i]-1);
        bit.update(v[i], 1);
    }

    return invCount;
}