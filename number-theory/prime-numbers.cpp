#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 1e7+10; // This should be the maximum N to be calculated 
const ll MAX = sqrt(MAXN)+10;

vector<bool> prime(MAX+100, true);
vector<ll> allPrimes; // For calculating bigger primes
void sieve(ll n) // Sieve of Eratosthenes
{
    prime[0] = prime[1] = false;

    for(ll i = 2 ; i <= n  ; i++)
    {
        if(prime[i] && i<= n)
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

vector<ll> factorization(ll n) 
{
    vector<ll> res;
    for (ll d : allPrimes) 
    {
        if (d * d > n)
            break;
        while (n % d == 0) 
        {
            res.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        res.push_back(n);
    return res;
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