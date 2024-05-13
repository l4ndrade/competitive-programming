#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Segment Tree for range minimum query
    tl and tr: boundaries of the current segment
    l and r: query boundaries
    NULLVALUE: For minimum, a very high value works
*/

const int NULLVALUE = 0x3f3f3f3f;
const int MAXN = 1e5;

struct Seg
{
    vector<ll> input;
    ll seg[4*MAXN];
    ll n;

    ll build(int idx, int tl, int tr)
    {
        if(tl==tr)
            return seg[idx] = input[tl];
        int tm = (tl+tr)/2;
        return seg[idx] = min(build(2*idx, tl, tm), build(2*idx+1, tm+1, tr));
    }

    void build(vector<ll>& v)
    {
        n = v.size();
        input = v;
        build(1, 0, n-1);
    }

    ll query(int l, int r, int idx, int tl, int tr)
    {
        if(r < tl or l > tr) return NULLVALUE;
        if(l <= tl and tr <= r) return seg[idx];
        
        int tm = tl+(tr-tl)/2;
        return min(query(l, r, 2*idx, tl, tm), query(l, r, 2*idx+1, tm+1, tr));
    }

    ll query(int l, int r)
    {
        return query(l, r, 1, 0, n-1);
    }

    ll update(int i, ll k, int idx, int l, int r)
    {
        if(i < l or i > r) return seg[idx];
        if(l==r) return seg[idx] = k;
        int m = l+(r-l)/2;
        return seg[idx] = min(update(i, k, 2*idx, l, m), update(i, k, 2*idx+1, m+1, r));
    }

    void update(int i, ll k) 
    {
        update(i, k, 1, 0, n-1);
    }
};