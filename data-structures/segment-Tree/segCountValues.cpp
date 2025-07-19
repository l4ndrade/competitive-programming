#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Segment Tree for range minimum query just like the one from segBasics.cpp, but finds minimum and counts it appears
*/

struct Node // Representa um vértice na árvore
{
    ll val; // Valor
    ll occ; // Número de ocorrências
};

const int NULLVALUE = 0x3f3f3f3f; // Elemento neutro da operação (nesse caso min(x, INF) = x sempre)

// Combina 2 vértices filhos em um vértice pai
Node combine(Node a, Node b) // Combina 2 vértices filhos em um vértice pai
{
    if(a.val < b.val)
        return {a.val, a.occ};
    if(b.val < a.val)
        return {b.val, b.occ};
    return {a.val, a.occ+b.occ};
}

struct Seg
{
    vector<ll> input;
    vector<Node> seg;
    ll n;

    // Constroi a segtree
    Node build(int node, int tl, int tr)
    {
        if(tl == tr) // Se o range é 1, retorna a posicao
            return seg[node] = {input[tl], 1};

        int tm = (tl+tr)/2;

        // Retorna a combinação dos resultados dos filhos
        return seg[node] = combine(build(2*node, tl, tm), build(2*node+1, tm+1, tr));
    }

    // Atribui o vector de entrada e constroi a segtree
    void build(vector<ll>& v)
    {
        n = v.size();
        input = v;
        seg.resize(4*n+5);
        build(1, 0, n-1);
    }

    Node query(int node, int tl, int tr, int l, int r)
    {
        if(l > r)
            return {NULLVALUE, 0};
        if(l == tl and r == tr)
            return seg[node];

        int tm = tl+(tr-tl)/2;

        return combine(query(2*node, tl, tm, l, min(r, tm)), 
                       query(2*node+1, tm+1, tr, max(l, tm+1), r));
    }

    Node query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    Node update(int node, int tl, int tr, int i, ll k)
    {
        if(tl > i or tr < i)
            return {NULLVALUE, 0};
        if(tl == tr)
            return seg[node] = {k, 1};
        int tm = tl+(tr-tl)/2;
        return seg[node] = combine(update(2*node, tl, tm, i, k), update(2*node+1, tm+1, tr, i, k));
    }

    void update(int i, ll k) 
    {
        update(1, 0, n-1, i, k);
    }
};
