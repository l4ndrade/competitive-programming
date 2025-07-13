/*
    Operações com módulo para questões que exigem resposta mod m
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

// Exponenciação binária mod m em O(log(n))
ll binpow(ll x, ll y, ll m) 
{
    ll res = 1;
    x %= m;
    while (y) 
    {
        if (y&1) // If it's odd
            res = res * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return res;
}

ll add(ll a, ll b, ll m)
{
    return (a % m + b% m) % m;
}

// Tem soma m para garantir que nao dá negativo
ll sub(ll a, ll b, ll m)
{
    return (a % m - b % m + m) % m;
}

ll mult(ll a, ll b, ll m)
{
    return (a % m * b% m) % m;
}

// Inverso modular de x mod m (só funciona para m primo)
ll inv(ll x, ll m) 
{
    return binpow(x, m - 2, m);
}

ll div(ll a, ll b, ll m)
{
    return mult(a, inv(b, m), m);
}