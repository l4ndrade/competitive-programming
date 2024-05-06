#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPowerOf2(int n)
{
    return !(n&(n-1));
}

int main()
{
    for(int i = 1 ; i <= 1024 ; i++)
    {
        if(isPowerOf2(i))
            cout << i << endl;
    }
}