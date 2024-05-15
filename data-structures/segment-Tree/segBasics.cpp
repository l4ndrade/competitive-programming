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

    ll build(int node, int tl, int tr)
    {
        if(tl == tr)
            return seg[node] = input[tl];

        int tm = (tl+tr)/2;
        return seg[node] = min(build(2*node, tl, tm), build(2*node+1, tm+1, tr));
    }

    void build(vector<ll>& v)
    {
        n = v.size();
        input = v;
        build(1, 0, n-1);
    }

    ll query(int node, int tl, int tr, int l, int r)
    {
        if(l > r)
            return NULLVALUE;
        if(l == tl and r == tr)
            return seg[node];
        int tm = tl+(tr-tl)/2;
        return min(query(2*node, tl, tm, l, min(r, tm)), query(2*node+1, tm+1, tr, max(l, tm+1), r));

    }

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    ll update(int node, int tl, int tr, int i, int k)
    {
        if(tl > i or tr < i)
            return NULLVALUE;
        if(tl == tr)
            return seg[node] = k;
        int tm = tl+(tr-tl)/2;
        return seg[node] = min(update(2*node, tl, tm, i, k), update(2*node+1, tm+1, tr, i, k));
    }

    void update(int i, ll k) 
    {
        update(1, 0, n-1, i, k);
    }
};