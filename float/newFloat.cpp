#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

// Float, but with more precison (simple implementation)

ld eps = 1e-7;

struct newFloat
{
    ld data;
    
    newFloat(ld data): data(data) {}
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

