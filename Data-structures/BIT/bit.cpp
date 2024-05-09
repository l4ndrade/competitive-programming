#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define lsOne(n) n & -n
struct Bit 
{
	int n;

	vector<ll> bit;

	Bit(int _n=0)
    {
        n = _n;
        bit.assign(n+1, 0);
    }
	Bit(vector<ll>& v) 
    {
        n = v.size();
        bit.assign(n+1, 0);
        
		for (int i = 1; i <= n; i++) 
        {
			bit[i] += v[i - 1];
			int j = i + lsOne(i);
			if (j <= n) 
                bit[j] += bit[i];
		}
	}

	void add(int i, ll k) 
    {
		for (i++; i <= n; i += lsOne(i)) 
            bit[i] += k;
	}

	ll rsq(int r) 
    {
		ll sum = 0;
		for (r++; r; r -= lsOne(r)) 
            sum += bit[r];
		return sum;
	}

	ll rsq(int l, int r) 
    {
		return rsq(r) - rsq(l - 1); 
	}
};