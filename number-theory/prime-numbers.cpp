#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = sqrt(10000010)+10; // Insert maximum input 

vector<bool> prime;
vector<ll> allPrimes; // For calculating bigger primes
void sieve(int n) // Sieve of Eratosthenes
{
    prime.assign(n+10, true);
    prime[0] = prime[1] = false;

    for(ll i = 2 ; i <= n  ; i++)
    {
        if(prime[i])
        {
            for(ll j = i*i ; j <= n ; j += i)
                prime[j] = false;

            allPrimes.push_back(i);
        }
    }
}

bool isPrime(ll n) // Uses previous algorithm
{
    if(n <= allPrimes.back())
        return prime[n];

    for(ll i = 0 ; i <= prime.size() ; i++)
    {
        if(n%allPrimes[i] == 0)
            return false;
        if(allPrimes[i]*allPrimes[i] > n) break;
    }
    return true;
}

void factorization(ll n, vector<int>& factors) 
{
    for (ll d : allPrimes) 
    {
        if (d * d > n)
            break;
        while (n % d == 0) 
        {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
}

int main()
{
    sieve(MAX);
    int n; cin >> n;
    for(int i = 0 ; i <= n*n ; i++)
        if(isPrime(i))
            cout << i << " is prime\n";

    return 0;
}
