#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Prints all subsets in O(2^n)
*/

const int MAXN = 12; // Maximum solutuion size
vector<int> s; // Set of all elements
vector<bool> p; // Stores partial solutions

void print(int n)
{
    for(int i = 0 ; i < n ; i++)
        if(p[i])
            cout << s[i] << ' ';
    cout << endl;
}

void generate(int pos, int n) // pos is the current position in s
{
    if(pos == n) // Stops in the last position
    {
        print(n);
        return;
    }

    p[pos] = true; // subset that contains element in s[pos]
    generate(pos+1, n);
    p[pos] = false; // subset that does not contain element in s[pos]
    generate(pos+1, n);
}

int main()
{
    p.resize(MAXN, 1);
    s = {1, 2, 3};

    generate(0, s.size());

    return 0;
}
