#include<bits/stdc++.h>
using namespace std;

bool prime(int x) // O(sqrt(n))
{
    for(int i = 2 ; i*i <= x ; i++)
    {
        if(x%i == 0)
            return false;
    }
    return true;
}

bitset<10000010> b; // For calculating small primes
vector<int> primes; // For calculating bigger primes
void generatePrimes(int n) // Sieve of Eratosthenes
{
    // Sets all bits as true except 0 and 1;
    b.reset(); b.flip(); b.set(0, false); b.set(1, false);

    for(int i = 2 ; i <= n  ; i++)
    {
        if(b[i])
        {
            for(int j = i*i ; j <=n ; j+= i)
            {
                b.set(j, false);
            }
            primes.push_back(i);
        }
    }
}

bool isPrime(int n) // Uses previous algorithm
{
    if(n <= primes.back())
        return b[n];

    for(auto p: primes)
        if(n%p == 0)
            return false;

    return true;
}

int main()
{
    int n; cin >> n;
    generatePrimes(n);
    for(int i = 0 ; i <= n*n ; i++)
        if(isPrime(i))
            cout << i << " is prime\n";

    return 0;
}