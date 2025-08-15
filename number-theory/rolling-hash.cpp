/*
    Função de hash para tirar o hash de s[l:r] em O(1)
*/

#include"modular_operations.cpp"
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll P = 1e6 + 3;

vector<ll> power;
vector<ll> inv_power;
vector<ll> prefix;

void precompute_powers(int n) 
{
    power.assign(n + 1, 1); // p^i % MOD para i em [0, n]
    inv_power.assign(n + 1, 1); // Inversos modulares de p^i para i em [0, n]

    for (int i = 1; i <= n; i++)
        power[i] = mult(power[i-1], P, MOD);
    for (int i = 0; i <= n; i++)
        inv_power[i] = inv(power[i], MOD);
}

ll get_hash(int l, int r) 
{
    ll raw = sub(prefix[r+1], prefix[l], MOD); // hash(l, r) * p^l
    return mult(raw, inv_power[l], MOD); // Usa inverso modular para dividir por p^l (não usa funcao inv para otimziar)
} 

// Constroi o vetor de prefixo a partir de um container de tipo T
template<class T> 
void build_prefix(T s)
{
    int n = s.size();
    prefix.assign(n, 0);
    for (int i = 0; i < n ; i++)
        prefix[i + 1] = multi(add(prefix[i], s[i]), power[i]);
}