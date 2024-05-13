#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5;

struct Seg
{
    vector<ll> input; // Original
    ll seg[4*MAXN]; // Tree
    ll n; // Size

    // tl and tr are boundaries of the current segment
    // idx is the current index of the segment tree (starts at 1)
    ll build(int idx, int tl, int tr)
    {
        if(tl==tr) // The segment is the position on the input array
            return seg[idx] = input[tl];
        int tm = (tl+tr)/2;
        return seg[idx] = min(build(2*idx, tl, tm), build(2*idx+1, tm+1, tr)); // Calls the function for both children of the index and for the two halfs of the current segment
    }

    void build(vector<ll>& v)
    {
        n = v.size();
        input = v;
        build(1, 0, n-1);
    }

    ll query(int l, int r, int idx, int tl, int tr) // Returns minimum in range[l, r]
    {
        if(r < tl or l > tr) return INF; // If this call is out of the range, returns null element (INF, for minimum)
        if(l <= tl and tr <= r) return seg[idx]; // If this interval belongs to [l, r], its part of the answer
        
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

int main(){

    ll n = 8;
    vector<ll> v = {13,3,6,20,18,6,10,4};

    Seg seg;
    seg.build(v);
    cout << seg.query(0,7) << endl;
    cout << seg.query(0,7) << endl;


    return 0;
}