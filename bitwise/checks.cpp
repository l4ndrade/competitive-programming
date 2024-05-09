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

int main()
{
    for(int i = 1 ; i <= 1024 ; i++)
    {
        if(isPowerOf2(i))
            cout << i << endl;
    }
    
    return 0;
}