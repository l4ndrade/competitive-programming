#include<bits/stdc++.h>
using namespace std;

int binpow(int x, int y)
{
    int res = 1;
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
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}