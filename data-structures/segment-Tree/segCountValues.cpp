#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

/*
    Segment Tree for range minimum query just like the one from segBasics.cpp, but finds minimum and counts it appears
*/

const int NULLVALUE = 0x3f3f3f3f;
const int MAXN = 1e5;

pll compare(pll a, pll b)
{
    if(a.first == b.first)
        return {a.first, a.second+b.second};
    return min(a, b);
}

struct Seg
{
    vector<ll> input;
    pll seg[4*MAXN];
    ll n;

    pll build(int node, int tl, int tr)
    {
        if(tl == tr)
            return seg[node] = {input[tl], 1};

        int tm = (tl+tr)/2;
        return seg[node] = compare(build(2*node, tl, tm), build(2*node+1, tm+1, tr));
    }

    void build(vector<ll>& v)
    {
        n = v.size();
        input = v;
        build(1, 0, n-1);
    }

    pll query(int node, int tl, int tr, int l, int r)
    {
        if(l > r)
            return {NULLVALUE, 0};
        if(l == tl and r == tr)
            return seg[node];
        int tm = tl+(tr-tl)/2;
        return compare(query(2*node, tl, tm, l, min(r, tm)), query(2*node+1, tm+1, tr, max(l, tm+1), r));

    }

    pll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    pll update(int node, int tl, int tr, int i, ll k)
    {
        if(tl > i or tr < i)
            return {NULLVALUE, 0};
        if(tl == tr)
            return seg[node] = {k, 1};
        int tm = tl+(tr-tl)/2;
        return seg[node] = compare(update(2*node, tl, tm, i, k), update(2*node+1, tm+1, tr, i, k));
    }

    void update(int i, ll k) 
    {
        update(1, 0, n-1, i, k);
    }
};
