#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return abs(500.0-x); // f -> \/
}

double tsearch(double l, double r) // Finds minimum in continuous interval
{
    double eps = 1e-9;
    double m1, m2;

    while (fabs(r-l) > eps)
    {
        m1 = l+(r-l)/3;
        m2 = r-(r-l)/3;

        if(f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }

    return l;
}

int main()
{
    cout << tsearch(0, 1000) << endl;
    return 0;
}