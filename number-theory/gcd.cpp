#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) // Euclidean Algorithm
{
    if (!b)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a/gcd(a, b)*b;
}


int main()
{
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}