#include<bits/stdc++.h>
using namespace std;

bool ok(int x){return x>=30;}
bool okc(double x){return x >= 30.51122;}

int firstTrue(int l, int r)
{
    int mid;
    while (l<r)
    {
        mid = l+(r-l)/2;
        
        if(ok(mid))
            r = mid;
        else
            l = mid+1;
    }

    if(!ok(l)) // [l, r] is all False
        return -1;
    else
        return l; 
}

// Using this function but with f2(x){return !f(x)} finds the last true
int lastFalse(int l, int r) // Finds last False in a function (FFFFFTTT)
{
    int mid;
    while (l<r)
    {
        mid = l+(r-l+1)/2; // +1 so it rounds up
        
        if(ok(mid))
            r = mid-1;
        else
            l = mid;
    }

    if(ok(l)) // [l, r] is all True
        return -1;
    else
        return l; 
}

double firstTrue(double l, double r) // Finds first true in a continuous interval (FFFFTTT)
{
    double mid;

    int p = 100; // more iterations = more precision
    for(int i = 0 ; i < p ; i++)
    {
        mid = l+(r-l)/2;
        if(okc(mid))
            r = mid;
        else
            l = mid;
    }

    if(!okc(l)) // [l, r] is all False
        return -1;
    else
        return l;
}

int main()
{
    cout << firstTrue(0, 50) << endl;
    cout << lastFalse(0, 50) << endl;
    cout << firstTrue((double)0, (double)50) << endl;
    
    return 0;
}