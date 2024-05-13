#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPowerOf2(int n)
{
    return !(n&(n-1));
}

bool LSOne(int n) // Least Significant One
{
    return n&(-n);
}
