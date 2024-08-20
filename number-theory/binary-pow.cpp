#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll x, ll y) // x^y
{
    ll res = 1;
    while (y)
    {
        if(y&1) // If it's odd
            res*=x;
        x*=x;
        y >>= 1;
    }

    return res;
}

int main()
{
    ll a, b; cin >> a >> b;
    cout << binpow(a, b) << endl;

    return 0;
}