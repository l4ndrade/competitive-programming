#include<bits/stdc++.h>
using namespace std;

// Float, but more assertive

double eps = 1e-9;

int comp(double a, double b)
{
    if(fabs(a-b) < eps) return 0;
    else if(a > b) return 1;
    else return -1; 
}

struct newFloat
{
    double data;
    
    newFloat(double data): data(data) {}
    newFloat() {}

    template<typename T>
    bool operator==(const T& other) {return fabs(data-other) < eps;}
    template<typename T>
    bool operator!=(const T& other) {return !(*this == other);}
    template<typename T>
    bool operator>(const T& other) {return !(*this==other) and data > other;}
    template<typename T>
    bool operator>=(const T& other) {return (*this==other) or *this > other;}
    template<typename T>
    bool operator<(const T& other) {return !(*this==other) and data < other;}
    template<typename T>
    bool operator<=(const T& other) {return (*this==other) or *this < other;}

    friend ostream &operator<<(ostream &os, newFloat const &n) {return os << n.data;}
};

