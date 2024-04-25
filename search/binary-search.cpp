#include<bits/stdc++.h>
using namespace std;

bool f(int x)
{
    return x>=30; // FFFFFTTTTT (first T: x = 30)
}

bool fc(double x)
{
    return x>=30.51122; // FFFFFFTTTTT (first T: x = 30.5)
}

// ALL FUNCTIONS USE THE INTERVAL [l, r] 

// bsearchANS uses binary search to find answers minimizing the calls os f

// Using this function but with f2(x){return !f(x)} finds the first false
int bsearchANS1(int l, int r) // Finds first True in a function (FFFFFTTT)
{
    int mid;
    while (l<r)
    {
        mid = l+(r-l)/2; // Avoids overflow

        if(f(mid))
            r = mid;
        else
            l = mid+1;
    }

    if(!f(l)) // [l, r] is all False
        return -1;
    else
        return l; 
}
// Using this function but with f2(x){return !f(x)} finds the last true
int bsearchANS2(int l, int r) // Finds last False in a function (FFFFFTTT)
{
    int mid;
    while (l<r)
    {
        mid = l+(r-l+1)/2; // +1 so it rounds up
        
        if(f(mid))
            r = mid-1;
        else
            l = mid;
    }

    if(f(l)) // [l, r] is all True
        return -1;
    else
        return l; 
    
}

double bsearchCON1(double l, double r) // Finds first true in a continuous interval (FFFFTTT)
{
    double mid;

    int p = 100; // more iterations = more precision
    for(int i = 0 ; i < p ; i++)
    {
        mid = l+(r-l)/2;
        if(fc(mid))
            r = mid;
        else
            l = mid;
    }

    if(!f(l)) // [l, r] is all False
        return -1;
    else
        return l;
}

int main()
{
    cout << bsearchANS1(0, 50) << endl;
    cout << bsearchANS2(0, 50) << endl;
    cout << bsearchCON1(0, 50) << endl;
    
    return 0;
}