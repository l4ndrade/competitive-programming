#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) // Euclidean Algorithm
{
    if (!b)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    return a/gcd(a, b)*b;
}


int main()
{
    ll a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}