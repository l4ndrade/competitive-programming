#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

// Float, but with more precison

class newFloat
{
private:
    ld data;
    ld eps;
public:
    newFloat(ld data, ld eps = 1e-7): data(data), eps(eps) {}
    newFloat(): eps(1e-7) {}

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
    
    template<typename T>
    newFloat operator+(const T& other) {return newFloat(data + other);}
    template<typename T>
    newFloat operator-(const T& other) {return newFloat(data - other);}
    template<typename T>
    newFloat operator*(const T& other) {return newFloat(data * other);}
    template<typename T>
    newFloat operator/(const T& other) {return newFloat(data / other);}

    template<typename T>
    newFloat operator=(const T& other) {return newFloat(data = other);}

    friend std::ostream &operator<<(std::ostream &os, newFloat const &n) {return os << n.data;}
};

