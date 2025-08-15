/*
    Compressing an array to be used in a BIT, SegTree, etc.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()

vector<ll> get_compressed(vector<ll> v) 
{
    vector<ll> aux = v;
    sort(all(aux));
    aux.erase(unique(all(aux)), aux.end());
    
    for (auto& x: v)
        x = lower_bound(all(aux), x) - aux.begin();
    return v;
}
