#include<bits/stdc++.h>
using namespace std;
/*
    This is a struct representing Points and Vectors in 2d
*/
struct Point2d
{
    double x, y;

    Point2d(double x=0, double y=0): x(x), y(y) {} // Constructor
    
    // Standard operations
    Point2d operator+(Point2d other) {return Point2d(x+other.x, y+other.y);}
    Point2d operator-(Point2d other) {return Point2d(x-other.x, y-other.y);}
    Point2d operator*(double s) {return Point2d(s*x, s*y);}
    Point2d operator/(double s) {return Point2d(x/s, y/s);}
    
    double operator*(Point2d other) {return x*other.x + y*other.y;} // Dot product
    double operator^(Point2d other) {return x*other.x - y*other.y;} // Cross Product

    // Comparison
    bool operator==(Point2d other) {return x==other.x and y==other.y;}
    bool operator!=(Point2d other) {return !(*this==other);}

    // cout for debug
    friend ostream &operator<<(ostream &os, Point2d const &p) {return os << "(" << p.x << ", " << p.y << ")";}
};

// returns vector from a to b
Point2d toVector(Point2d a, Point2d b){return b-a;}

// If cross product equals 0, a, b and c are collinear
bool collinear(Point2d a, Point2d b, Point2d c){return toVector(a, b) ^ toVector(a, c) == 0;}

// Triangle Area
double area(Point2d a, Point2d b, Point2d c){return 0.5 * (toVector(a, b) ^ toVector(a, c));}

/*
The cross product can be used to check if a vector is closer to another rotating clockwise or counter-clockwise.
Take 2 vectors v and u. 
v^u == 0 -> the vectors are in the same line;
v^u > 0 -> v rotates counter-clockwise to meet u;
v^u < 0 -> v rotates clockwise to meet u.
*/

// Returns vec's norm^2
double norm2(Point2d vec){return vec.x*vec.x + vec.y*vec.y;}

// Returns if p is between p1 and p2 but NOT equal to p1 or p2
bool between(Point2d p1, Point2d p2, Point2d p)
{
    return collinear(p1, p2, p) and toVector(p, p1)*toVector(p, p2) < 0;
}