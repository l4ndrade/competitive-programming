#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFLL 0x3f3f3f3f3f3f3f3f

/*
    Segment Tree for range minimum query counting occurances
*/

struct Node
{
    ll val, occ;

    Node(ll val): val(val), occ(1) {} // Constrói a partir de 1 item
    Node(ll val, ll occ): val(val), occ(occ) {} // Constroi a partir dos parametros
    Node() {}
};

const Node NULLNODE = {INFLL, 0}; // Nodo de elemento neutro

// Combina 2 vértices filhos em um vértice pai
Node combine(Node a, Node b)
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
            return seg[node] = Node(input[tl]);

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
            return NULLNODE;
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
            return NULLNODE;
        if(tl == tr)
            return seg[node] = Node(k);
        int tm = tl+(tr-tl)/2;
        return seg[node] = combine(update(2*node, tl, tm, i, k), update(2*node+1, tm+1, tr, i, k));
    }

    void update(int i, ll k) 
    {
        update(1, 0, n-1, i, k);
    }
};
