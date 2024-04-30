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

#define MAX 31700

vector<bool> b(MAX+100, 1);
vector<int> primes; // For calculating bigger primes
void generatePrimes(int n) // Sieve of Eratosthenes
{
    b[0] = b[1] = false;

    for(int i = 2 ; i <= n  ; i++)
    {
        if(b[i])
        {
            for(int j = i*i ; j <= n ; j+= i)
            {
                b[j] = false;
            }
            primes.push_back(i);
        }
    }
}

bool isPrime(int n) // Uses previous algorithm
{
    if(n <= primes.back())
        return b[n];

    for(int i = 0 ; i <= b.size() ; i++)
    {
        if(n%primes[i] == 0)
            return false;
        if(primes[i]*primes[i] > n) break;
    }

    return true;
}

int main()
{
    int n; cin >> n;
    generatePrimes(MAX);
    for(int i = 0 ; i <= n*n ; i++)
        if(isPrime(i))
            cout << i << " is prime\n";

    return 0;
}